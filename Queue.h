#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template<class something>
class Queue{
private:
	something * list;
	int back;
	int arraysize;
        int front;   
public:

	
        Queue(){
		back=0;
		arraysize=100;
		list = new something[100];
                front=0;
	}

	void enqueue(something x){
		if(back==arraysize)
		 resizearray();
		
		list[back++]=x;
		
	}
	something dequeue(){
		 if(front>=arraysize)
			 return NULL;	 
		something x=list[front];
                front = ++front %arraysize;
                return x;
	 }
         int size(){
             return abs(back-front);
         }
	void resizearray(){
		something * templist = new something[arraysize*2];
		for(int x=0;x<arraysize;x++){
			templist[x]=list[x];
		}
		arraysize *=2;
		delete[] list;
		list = templist;
	 }
        bool empty(){
            return(front == back) ? true : false;
        }


};