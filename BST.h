/* 
 * File:   BST.h
 * Author: Cesar Carrillo
 *
 * Created on November 30, 2015, 5:01 PM
 */

#ifndef BST_H
#define	BST_H

#include <cstdlib>
#include <iostream>
using namespace std;
class BST{
private: 
    class node{
    public:
        node * left;
        node * right;
        double data;
        node(double val){
            data = val;
            left = NULL;
            right = NULL;
        }
    };
    node * root;
    int size;
    node * removed;
    // end of nodes, start of private functions for BST.
    
    node * add(double data, node * current){
       //base case
        if(current == NULL){
            return new node(data);
        }
        // compare the values
        if(data < current->data){
            current->left = add(data,current->left);
        }
        else
            current->right = add(data,current->right);
        
        return current;
    }
    void inorder(node * temp){
        if(temp == NULL)
            return;
        else{
            inorder(temp->left);
            cout<<temp->data<<" ";
            inorder(temp->right);
        }
    }
    int Height(node * current){
        if(current == NULL)
            return 0;
        if(current->left == NULL && current->right == NULL)
            return 0;
        if(current->left == NULL || current->right == NULL)
            return 1;
         else 
             return max(Height(current->left), Height(current->right))+1;
    }
    int Leaves(node * current){
        if(current ==NULL)
            return 0;
        if(current->left == NULL && current->right == NULL)
            return 1;
        else
            return Leaves(current->left) + Leaves(current->right);
    }
    node * removeMin(node * &current){
        if(current->left == NULL){
            removed = current;
            return current->right;  
        }
        //keep going left
        current->left = removeMin(current->left);
        
        return current;
    }
    node * removeMax(node * &current){
         if(current->right == NULL){
            return current->left;
         }
         //keep going right
        current->right = removeMax(current->right);
        
        return current;
    }
    int getMax(){
        return getMax(root)->data;
    }
    int getMin(){
        return getMin(root)->data;
    }
    node * getMax(node * current){
        //max reached
        if(current->right == NULL)
        
        //keep going right
        return getMax(current->right);
    }
    node * getMin(node * current){
        //min reached
        if(current->left == NULL)
           return current;
        
        //keep going right
        return getMin(current->left);
    }
    node * remove(node* &current, int targetData)
    {
        //empty
        if(current == NULL)
            return NULL;    
        //match found
        if(current->data == targetData)
        {           
            bool leftExists = current->left != NULL;
            bool rightExists = current->right != NULL; 
            //full node
            if(leftExists && rightExists)
            {
                node * temp;
                //pick a side at random
                int r = rand() % 2 ;
                cout<<r<<endl;
                //get max from left tree
                if(r >= 1)
                {   
                    temp = getMax(current->left);                  
                    //swap data
                    current->data=temp->data;                  
                    //remove the max in the left subtree
                    removeMax(current->left);
                    current->left = removed;
                    cout<<removed->data<<endl;
                }
                //get min from right tree
                else
                {
                    temp = getMin(current->right);                  
                    //swap data
                    current->data=temp->data;       
                    //remove the min in the right sub tree
                    removeMin(current->right);
                    current->right = removed;
                     
                }
            }            
            else if(leftExists)
                return current->left;          
            //right child exists
            else if(rightExists)
                return current->right;           
            //leaf
            else
                return NULL;
        }
        //search left
        else if(current->data < targetData)
            current->left = remove(current->left, targetData);  
        //search right
        else
            current->right = remove(current->right, targetData);
        
        return current;
    }
public:
    
    BST(){
        root = NULL;
        size = 0;
    }
    
    void insert(double data){
        root = add(data,root);
        size++;
    }
    void display(){
        inorder(root);
        cout<<endl;
    }
    int numItems(){
        return size;
    }
    int getHeight(){
        return Height(root);
    }
    int numLeaves(){
        return Leaves(root);
    }
    int extractMin(){
        removeMin(root);
        return removed->data;
    }
    int extractMax(){
        removeMax(root);
       return removed->data;
    }
    void remove(int data){
        root = remove(root, data);
    }
};

#endif	/* BST_H */

