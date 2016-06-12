`/* 
 * File:   Avl.h
 * Author: Cesar Carrillo
 *
 * Created on February 9, 2016, 10:27 PM
 */

#ifndef AVL_H
#define	AVL_H

#include <iostream>
using namespace std;

class AVLTree{
    
private:
	class node{
	public:
		double data;
		node * left;
		node * right;

		//height of node in tree
		int height;

		node(double x){
			data=x;
			left=NULL;
			right=NULL;
			height = 0;
		}
	};

	int getHeight(node * r){
		if( r==NULL )
			return -1;
		else
			return r->height;
	}

	node * root;

	//update r's height to correct
	//value
	void updateHeight(node * r){
		r->height = 1+ max(getHeight(r->left),getHeight(r->right));
	}
        
        
    /* Start AVL Functions */
        
        /* Rotations*/
        void doubleWithLeftChild(node *&t){ // RIGHT LEFT
            rotateRight(t->right);
            rotateLeft(t);
        }
        void doubleWithRightChild(node *&t){ // LEFT RIGHT
            rotateLeft(t->left);
            rotateRight(t);
        }
        void rotateLeft(node *&p2){ // LEFT LEFT
            node * p1 = p2->right;
            p2->right = p1 ->left;
            p1->left = p2;
            updateHeight(p2);
            updateHeight(p1);
            p2=p1;
        }
    
        void rotateRight(node *&p2){ // RIGHT RIGHT
            node * p1 = p2->left;
            p2->left = p1 ->right;
            p1->right = p2;
            updateHeight(p2);
            updateHeight(p1);
            p2=p1;
        }
        
     /* Remove Functions*/ 
        node * removeMax(node * &current) {
            if(current->right == NULL)
            return current->left;
       
            //keep going right
            current->right = removeMax(current->right);
        
            return current;
        }
    
    
        node * removeMin(node *& current){
            if(current->left == NULL)
             return current->right;
       
            //keep going left
            current->left = removeMin(current->left);
        
            return current;
        }
         node * getMax(node* current)  {
            //max reached
             if(current->right = NULL)
                return current;
        
            //keep going right
            return getMax(current->right);
        }
        node * getMin(node * current){
            //min reached
            if(current->left == NULL)
                return current;
        
            //keep going left
             return getMin(current->left);
        }
        
        /* Insert and Remove Functions*/
        
	void insert(node * &r, double x){
		if( r==NULL ){
			r = new node(x);
		}
		else
		{
			if( x < r->data ){
				insert(r->left,x);
			}
			else{
				insert(r->right,x);
			}
			//r's height may have changed
			//after inserting
                        balance(r);
			
		}
	}
        void balance(node * &r){
            if(r == NULL)
                return;
            
            if(getHeight(r->left) - getHeight(r->right) > 1)
                if(getHeight(r->left->left) >= getHeight(r->left->right))
                    rotateRight(r);
                else
                    doubleWithRightChild(r);
            else if(getHeight(r->right) - getHeight(r->left) > 1)
                if(getHeight(r->right->right) >= getHeight(r->right->left))
                    rotateLeft(r);
                else
                    doubleWithLeftChild(r);
            
            updateHeight(r);
        }
           

	//print all items in tree
	//rooted at r
	void display(node * r){
		if( r==NULL ){
			//do nothing
		}
		else{
                    
			display(r->left);
			cout << r->data<< " ";
			display(r->right);
		}
	}

	//delete tree rooted at r
	void deleteTree(node * r){
		if( r!= NULL ){
			deleteTree(r->left);
			deleteTree(r->right);
			delete r;
		}
	}
       
        
// Start Public 
 
        
public:

	~AVLTree(){
		deleteTree(root);
	}

	AVLTree(){
		root=NULL;
	}
        int height(){
            return getHeight(root);
        }
        
	void insert(double x){
		insert(root,x);
	}
        void insert(int x){
		insert(root,x);
	}

	void display(){
		display(root);
                cout<<endl;
                
	}
        
        void sort(int *& list, int start, int end){
            for(int x=start; x<end; x++){
                insert(list[x]);
            }
            for( int y = start; y<end; y++){
                list[y] = removeMin(root)->data;
            }
        }
        
        
};


#endif	/* AVL_H */

