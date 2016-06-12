/*
 * Graph and breadth first search.
 * Created by Cesar Carrillo
 * 3/25/2016
 * 
 */

#include <iostream>
#include <string>
#include <list>
#include "Queue.h"
using namespace std;
class graph{
private:
    int size=0;
	class vertex{
	public:
		string data;
		list<vertex*> neighbors;
                int position = -1;
                vertex * from;
                vertex(){}
		vertex(string x, int pos)
		{   
                    from = NULL;
                    position = pos;
                    data = x;
		}
	};

	list<vertex*> verticeList;

	vertex * findVertex(string stuff) {
		for (list<vertex *>::iterator iter = verticeList.begin(); iter!= verticeList.end(); iter++) {
			if ((*iter)->data == stuff)
				return *iter;
		}
		return NULL;
	}
        bool isConnected(string one, string two){
            vertex  * temp =  findVertex(one);
            
        for (list<vertex *>::iterator iter2 = (temp)->neighbors.begin(); iter2 != (temp)->neighbors.end(); iter2++) {
                if((*iter2)->data == two)
                    return true;
            }
            return false;
        }
        string flip(vertex * x){
            if(x->from == NULL)
                return "";
            else
                return flip(x->from)+ " " + x->data;
        }
        

public:

	void addVertex(string x){
		verticeList.push_back(new vertex(x,size++));
	}

	void addEdge(string x, string y){
		vertex * one = findVertex(x);
		vertex * two = findVertex(y);
		one->neighbors.push_back(two);
		two->neighbors.push_back(one);
	}

	//list all vertices, and who each vertex is connect to
	void testDisplay(){
		for (list<vertex *>::iterator iter = verticeList.begin(); iter != verticeList.end(); iter++) {
			cout << (*iter)->data<<": ";
			for (list<vertex *>::iterator iter2 = (*iter)->neighbors.begin(); iter2 != (*iter)->neighbors.end(); iter2++) {
				cout << (*iter2)->data<<"\t";
			}
			cout << endl;
		}
	}
        string shortestPath(string start, string end){
            string shortest = "";
            bool * visited =  new bool[size];
            for(int x=0; x<size; x++)
                visited[x] = false;
       
            Queue<vertex*> check;
            
            //add the first location to queue
            check.enqueue(findVertex(start));
            visited[findVertex(start)->position] = true;
            shortest += start;
            while(!check.empty()){
                vertex * temp =check.dequeue(); 
                start  = temp->data;
                
                
               for (list<vertex *>::iterator iter = verticeList.begin(); iter != verticeList.end(); iter++) {
                        if(isConnected(start,(*iter)->data) && visited[(*iter)->position] != true){
                        check.enqueue((*iter));
                        (*iter)->from = temp;
                        visited[(*iter)->position] = true;
                        if((*iter)->data == end){
                            vertex * t = (*iter);
                            shortest += flip(t);
                            return shortest;
                        }
                      }
                 }  
              }
            return shortest;
            }


};