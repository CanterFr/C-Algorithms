#include <iostream>
#include "linkedList.h"
using namespace std;


int main()
{
	//Part 1:  Implement a "split" routine.

	linkedList<int> list1;
        linkedList<int> list2;
        linkedList<int> list3;
        linkedList<int> list4;

	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_back(40);
	list1.push_back(50);
	list1.push_back(60);
	list1.push_back(70);
	list1.push_back(80);
	list1.push_back(90);
	list1.push_back(100);

	list1.display();
	cout << endl;

	//split list into two halves.  
        list1.split(list1, list2);
	
        
	list1.display(); //10 20 30 40 50
	cout << endl;

	list2.display(); //60 70 80 90 100
	cout << endl;

	list1.split(list1, list3);
	list2.split(list2,list4);

	list1.display(); //10 20
	cout << endl;
	list3.display(); //30 40 50
	cout << endl;
	list2.display(); //60 70
	cout << endl;
	list4.display(); //80 90 100
	cout << endl;

	//Part 2:  Implement a "merge" routine
	linkedList<int> a,b;

	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	a.push_back(11);
	a.push_back(13);
	a.push_back(17);

	b.push_back(-20);
	b.push_back(0);
	b.push_back(8);
	b.push_back(10);
	b.push_back(15);
	b.push_back(50);

	//merge two sorted linked lists into a combined sorted list, empty original lists.
	//Note: merge is a "static" method in the linked list class.
	linkedList<int> c = a.merge(a,b);
	c.display(); //-20 0 2 3 5 7 8 10 11 13 15 17 50
	cout << endl;

	//both original lists should now be empty
	a.display(); 
	b.display(); 


	//Implement mergeSort
	linkedList<int> items;

	items.push_back(178);
	items.push_back(20);
	items.push_back(43);
	items.push_back(56);
	items.push_back(2);
	items.push_back(82);
	items.push_back(12);
	items.push_back(48);
	items.push_back(25);
	items.push_back(34);

	items.mergeSort(items);

	items.display(); //2 12 20 25 34 43 48 56 82 178

	return 0;
}
