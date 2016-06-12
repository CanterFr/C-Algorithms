/* 
 * File:   myVector.h
 * Author: Cesar Carrillo
 *
 * Created on October 6, 2015, 7:22 PM
 */

#ifndef MYVECTOR_H
#define	MYVECTOR_H
template <class something>
class vector{  
public:

	vector(){
		index=0;
		arraysize=10;
		list = new something[arraysize];
                
	}
        void resize(int size){
		index=0;
		arraysize=size;
		list = new something[size];
	}
        vector(int size, something contents){
		index=0;
		arraysize=size;
		list = new something[size];
                for(int x =0; x<size; x++){
                    list[x] = contents;
                    index++;
                }
	}
        
	int push_back(something x){
            if(arraysize ==0)
                arraysize +=2;
            else if(index==arraysize)
		 resizearray();
		
		list[index]=x;
		return index++;
	}
        
	something pop_back(){
		 if(index==0)
			 return 0;	 
		return list[--index];
	 }
        
	void resizearray(){
           
		something * templist = new something[arraysize*10];
		for(int x=0;x<arraysize;x++){
			templist[x]=list[x];
		}
		arraysize *=10;
		delete[] list;
		list = templist;
	 }
        something back(){
            return list[index-1];
        }
        bool empty(){
            return index ==0;
        }
        int size(){
            return index;
        }
        int capacity(){

            return arraysize;
        }
        something &operator[](int value){
                return list[value];
        }
	private:
	something * list;
	int index;
	int arraysize;

};


#endif	/* MYVECTOR_H */

