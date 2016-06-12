/* 
 * File:   priorityQueueLL.h
 * Author: Cesar
 *
 * Created on January 27, 2016, 12:11 AM
 */

#ifndef PRIORITYQUEUELL_H
#define	PRIORITYQUEUELL_H
#include "DoublyLinkedList.h"

class priorityQueueLL
{
private:
    DoublyLinkedList list;

public:
	
	priorityQueue()
	{}
        ~priorityQueue(){//big oh (n)runs through the whole list
            list.~DoublyLinkedList();
        }
        	


	//return true if empty, false if not
	bool empty(){//big oh (1) checks the tail and head of the list.
            list.empty();
        }

	//add item
	void insert(int x){//big oh (1) removes the tail
            list.addBack(x);
        }

	//remove and return smallest item
	int extractMin(){ // big oh(n) finding the smallest consumes the most
                            // time
            return list.removeMin();
        }

};


#endif	/* PRIORITYQUEUELL_H */

