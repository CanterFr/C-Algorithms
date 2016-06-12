/* 
 * File:   minHeap.h
 * Author: Cesar Carrillo
 *
 * Created on February 17, 2016, 9:25 AM
 */

#ifndef MINHEAP_H
#define	MINHEAP_H
#include <iostream>
#include <cstdlib>
#include "djGraph.h"
#include "myVector.h"
using namespace std;
template<class something>       
class minHeap{

 
  private:

vector<something> items;
       
int parent(int i){
    int index = i+1;
    index/=2;
    index--;
    return index;
}
int lchild(int i){
    int index = i+1;
    index *= 2;
    index--;
    return index;
}
int rchild(int i){
    int index = i+1;
    index *=2;
    return index;
}
    
	//bubble item at position i up
	//until no more violation
	void bubbleUp(int i)
	{
		if( i== 0 )
		{//no parent, so no violation 
                   items[i]->minPos = i;
                }
		else if( items[i]->weight >= items[parent(i)]->weight )
		{//no violation
                    items[i]->minPos = i;
                }
		else{
			//swap items
                        items[i]->minPos = parent(i);
			items[parent(i)]->minPos = i;
                        something temp = items[i];
                        items[i] = items[parent(i)];
                        items[parent(i)] = temp;           
			//bubble up on parent
			bubbleUp(parent(i));
		}
	}
        void bubbleDown(int i)
	{   
            if(i > items.size()){}
            else if(items.size() == 0){}
            else if(rchild(i) >= items.size() && lchild(i)<items.size()){
                if(items[i]->weight > items[lchild(i)]->weight){
                    items[i]->minPos = lchild(i);
                    items[lchild(i)]->minPos = i;     
                        something temp = items[i];
                        items[i] = items[lchild(i)];
                        items[lchild(i)] = temp;
                    bubbleDown(lchild(i));
                }
            }
           else if(rchild(i)< items.size()){ 
                    if(items[i]->weight > items[lchild(i)]->weight){
                        items[i]->minPos = lchild(i);
                        items[lchild(i)]->minPos = i;
                        something temp = items[i];
                        items[i] = items[lchild(i)];
                        items[lchild(i)] = temp;
                        bubbleDown(i);
                        bubbleDown(lchild(i));
                    }
                    else if(items[i]->weight > items[rchild(i)]->weight){
                        items[i]->minPos = rchild(i);
                        items[rchild(i)]->minPos = i;
                        something temp = items[i];
                        items[i] = items[rchild(i)];
                        items[rchild(i)] = temp;
                        bubbleDown(i);
                        bubbleDown(rchild(i));
                    }
                }
        }
        

        
        void swap(something &x , something &y){
            something temp = x;
            x = y;
            y= temp;
        }
        
public:
	minHeap()
	{
	}
        void resize(int size){
            items.resize(size);
        }

    	//add new item to heap
	void insert(something x){   
		//put item at back of array/vector
		x->minPos = items.push_back(x);
                x->inserted = true;
		//bubble item up until no more violation exists
		if(x->weight ==0)
                    bubbleUp(x->minPos);
	}

	//remove and return smallest item
        something extractMin(){
            something temp = items[0];
            items[0] = items.pop_back();
            items[0]->minPos = 0;
            bubbleDown(0);
            temp->minPos = -1;
            return temp;
        }
        
        bool empty(){
            return items.size() <=0 ? true : false;
        }
        
        void changeValueAt(int pos, something &newVal){
                items[pos]= newVal;  
                bubbleUp(pos);          
         }
        
        something &operator[](int value){
                return items[value];
        }
};

#endif	/* MINHEAP_H */

