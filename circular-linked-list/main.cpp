#include <iostream>
#include "Clinked.hpp"
using namespace std;

int main()
{
	bool result ; //used for searching
	/*  Some test cases */
	//Tail
	cout<<"*INIT"<<endl;
	node * nodeptr= new node ; ; 
	int element;
	Clinkedlist ll;
	cout<<"*Insert Tail = 100"<<endl;
	ll.InsertTail(100,&nodeptr);
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);	
	cout<<"	Tail is = "<<element<<endl;	
	//InsertTail
	cout<<"*Insert Tail = 7"<<endl;
	ll.InsertTail(7,&nodeptr);
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	//cout<<"current node ptr is = "<<nodeptr<<endl;	
	//cout<<"current element ptr is = "<<nodeptr->ptr<<endl;
	//cout<<"current element from node is = "<<(nodeptr->element)<<endl;

	//InsertHead
	cout<<"*Insert Head = 3"<<endl;
	ll.InsertHead(3,&nodeptr);
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	//RemoveHead
	cout<<"*Remove Head"<<endl;
	ll.RemoveHead();
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	//RemoveTail
	cout<<"*Remove Tail"<<endl;
	ll.RemoveTail();
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	//Search
		//InsertTail
	cout<<"*Insert Tail = 7"<<endl;
	ll.InsertTail(7,&nodeptr);
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	//InsertTail
	cout<<"*Insert Tail = 8"<<endl;
	ll.InsertTail(8,&nodeptr);
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	//InsertTail
	cout<<"*Insert Tail = 9"<<endl;
	ll.InsertTail(9,&nodeptr);
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	//InsertTail
	cout<<"*Insert Tail = 10"<<endl;
	ll.InsertTail(10,&nodeptr);
	ll.Head(&element);
	cout<<"	Head  is = "<<element<<endl;
	ll.Tail(&element);
	cout<<"	Tail is = "<<element<<endl;
	Clinkedlist l2 = ll;
	l2.Tail(&element);
	cout<<"	Tail l2 is = "<<element<<endl;
	l2.InsertTail(112,&nodeptr);
	l2.Head(&element);
	cout<<"	Head l2  is = "<<element<<endl;
	l2.Tail(&element);
	cout<<"	Tail l2 is = "<<element<<endl;

	//result = ll.Search(10);
	//cout << "searching for 10 = "<<result << endl;
	//result = ll.Search(11);
	//cout << "searching for 11= "<<result << endl;
	//Size
	//cout<<"Size of list =  "<<ll.Size()<<endl;
	return 0 ;
}
