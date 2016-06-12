/* 
 * File:   quadraticHashTable.h
 * Author: Cesar Carrillo
 *
 * Created on March 9, 2016, 9:36 AM
 */

#ifndef QUADRATICHASHTABLE_H
#define	QUADRATICHASHTABLE_H
#include <cmath>
#include <cstdlib>



using namespace std;


class quadraticHashTable{

private:
   ////////////////////////////////////////////////////////////////////////////
        class bucket{
        public:
        int data;
        bool filled;
        bool removed = false;
       
         bucket(){
             data=0;
             filled =false;
         }
         bucket(int num){
            data = num;
            filled =true;
        }
         void remove(){
             data=0;
             filled =false;
             removed =true;
         }
    };
    
    bucket *list;
    int size = 11;
    int elem = 0;
   
    ///////////////////////////////////////////////////////////////////////////
    

    void resize(){
        
        bucket * temp = list;
        int orisize = size;
        size = size*2 +1;
        size = nextPrime(size);
        
        list = new bucket[size];
        
        for(int x =0; x<orisize; x++){
            if(temp[x].filled)
                insert(temp[x].data);
        }
        delete temp;
    }
    
    bool isPrime (int n)
    {
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
    }

    int nextPrime(int n)
    {
        if (n <= 0)
            n == 3;
        if (n % 2 == 0)
            n++;
    for (; !isPrime( n ); n += 2);
    return n;
    }
     int hashFunction(int x){
        return x % size;
    }
    
//////////////////////////////////////////////////////////////////////////////
public:
    
    quadraticHashTable(){
        size = 11;
        list = new bucket[size];
        for(int x=0; x<size; x++)
            list[x] =bucket();
    }
    quadraticHashTable(int num){
        list =  new bucket[num];
        size = num;
        for(int x=0; x<size; x++)
            list[x] =bucket();
    }
    ~quadraticHashTable(){
        delete list;
    }
    
    void insert(int num){
        int pos = hashFunction(num);
        int times =1;
        int opos = hashFunction(num);
        elem++;
        if(elem >= size/2)
            resize();
        if(!list[pos].filled){
            list[pos] =  bucket(num);
            return;
        }
        else if(list[pos].filled && times == 1){
            pos = (opos + (int)pow(times++,2) )% size;
            if(!list[pos].filled){
                list[pos] = bucket(num);
                return;
            }
        }
            
            while(list[pos].filled){
                pos = (opos + (int)pow(times++,2) )% size;
            if(!list[pos].filled){
                list[pos] = bucket(num);
                return;
            }
             }        
          }      

    void testDisplay(){
        for(int x = 0; x<size; x++)
            cout<<list[x].data << " ";
        cout<<endl;
    }
    bool contains(int num){
        int pos = hashFunction(num);
        int opos = pos;
        int times = 1;
        if(list[pos].filled && list[pos].data == num){
            return true;
        }
        else if(list[pos].filled && times == 1){
            pos = (opos + (int)pow(times++,2) )% size;
            if(list[pos].filled && list[pos].data == num){
                return true;
            }
        }
            
            while(list[pos].filled){
                pos = (opos + (int)pow(times++,2) )% size;
                if(list[pos].data == num)
                    return true;
             }
        return false;
          } 
    
    void remove( int num){
        int pos = hashFunction(num);
        int opos = pos;
        int times = 1;
        if(list[pos].filled && list[pos].data == num){
            list[pos].remove();           
        }
         else if(list[pos].filled && times == 1){
            pos = (opos + (int)pow(times++,2) )% size;
            if(list[pos].filled && list[pos].data == num){
                list[pos].remove();
            }
        }
        else{
            
            while(list[pos].filled || list[pos].removed){
                pos = (opos + (int)pow(times++,2) )% size;
                
              if(list[pos].data == num){                   
                list[pos].remove();
             }        
          }   
    }  
    }
};

#endif	/* QUADRATICHASHTABLE_H */

