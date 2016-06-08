#include <iostream>
#include "Slinked.hpp"
using namespace std;

int main()
{
	
	/*  Some test cases */
	//Tail
	cout<<"*INIT with 5"<<endl;
	node * nodeptr= new node ; ; 
	int element;
	Slinkedlist ll(5);
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
	return 0 ;
}
