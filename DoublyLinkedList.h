/* 
 * File:   DoublyLinkedList.h
 * Author: Cesar Carrillo
 *
 * Created on January 26, 2016, 11:45 PM
 */

#ifndef DOUBLYLINKEDLIST_H
#define	DOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

class DoublyLinkedList
{
private:
	class node
	{
	public:
		double data;
		node * next;
		node * prev;

		node(double x)
		{
			data =x;
			next=NULL;
			prev=NULL;
		}
	};
        
	node * head;
	node * tail; //allow O(1) time access to back of list
        
        
        
public:

	DoublyLinkedList()
	{
		tail=NULL;
		head=NULL;
	}
       ~DoublyLinkedList(){
            node * temp = head;
            while(temp != NULL){
                node* next = temp->next;
                delete temp;
                temp = next;
            }
            
        }
       void addFront(double value){
            node * first = new node(value);
            first->data = value;
            first->next = head;
            head = first;
        }
	void addBack(double x)
	{
		if( head==NULL ) //empty list
		{
			node * baby = new node(x);
			head=baby;
			tail=baby;
		}
		else
		{
			node * baby = new node(x);
			tail->next=baby;
			baby->prev = tail;
			tail = baby;
		}
	}

	void displayForwards()
	{
		node * tmp = head;
		while( tmp != NULL )
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
                cout<< endl;
	}

	void displayBackwards()
	{
		node * tmp = tail;
		while( tmp != NULL )
		{
			cout << tmp->data << " ";
			tmp = tmp->prev;
		}
                cout<<endl;
	}
         node * find(double x){
            node * temp = head;
            while(temp != NULL && temp->data != x){
                temp = temp-> next;
            }
           
            return temp;
        }
         node * findSmallest(){
             node * temp = head->next;
             node * smallest = head;
            while(temp != NULL){
                if(smallest->data>temp->data)
                    smallest = temp;
                temp = temp-> next;
            }
           
            return smallest;
         }
         int removeMin(){
             node * min = findSmallest();
             int minimum = min->data;
             if(min == head){
                 removeHead();
                 delete min;
             }
             else if(min == tail){
                 removeTail();
                 delete min;
             }
             else{
                min->prev->next = min->next;
                min->next->prev = min->prev;
                delete min; 
             }
             
             
             return minimum;
         }
	void remove(double x)
	{
            
           node * current = find(x);

           if(current == NULL)
               return;
           else{
               if(current->data == tail->data){
                   tail= tail->prev; 
                   tail->next = NULL;
                         
               }
               else if(current->data == head->data){
                   head= head->next;
                   head->prev =NULL;
               }
               else{
                   current->prev->next = current->next;
                   current->next->prev = current->prev;
               }
               delete current;
              
            }
         }
        double removeKitem(int k){
            node * temp = head;
            
            while(k>0){
                if(temp->next != NULL)
                temp = temp->next;
                k--;
            }
            int ren = temp->data;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        void decimate(){
            node * temp = head;
            int num = 0;
            while(temp != NULL){
                if(num %10 == 0){
                    removeKitem(num);
                }
                num++;
                temp = temp->next;
            }
        }
        void insertAt(int x , int i){
            node * temp = head;
            
            while(i>0){
                if(temp->next != NULL)
                temp = temp->next;
                i--;
            }
            node * babe = new node(x);
            temp->next->prev = babe;
            babe->next = temp->next;
            babe->prev = temp;
            temp->next = babe;
        }
        double removeHead(){
            if(head->next==NULL) {
                int x = head->data;
               head = NULL;
               tail=NULL;
                return x;
            }
            else{
            double x = head->data;
            head = head->next;
            head->prev = NULL;
            return x;
            }
        }
        double removeTail(){
            if(tail->prev==NULL) {
                int x = tail->data;
                head = NULL;
                tail = NULL;
                return x;
            }
            else{
            double x = tail->data;
            tail = tail->prev;
            tail->next = NULL;
            return x;
            }
        }    
            
        bool empty(){
            return head==NULL || tail == NULL;
        }
        
       
        
};



#endif	/* DOUBLYLINKEDLIST_H */

