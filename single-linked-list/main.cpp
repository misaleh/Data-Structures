#include <iostream>
#include "Slinked.hpp"
using namespace std;

int main()
{
	
	/*  Some test cases */
	node * nodeptr= new node ; ; 
	int element;
	Slinkedlist ll(5);
	ll.Current(&element);	
	cout<<"current element is = "<<element<<endl;	
	ll.InsertTail(7,&nodeptr);
	ll.Current(&element);
	cout<<"current element is = "<<element<<endl;
	cout<<"current node ptr is = "<<nodeptr<<endl;	
	cout<<"current element ptr is = "<<nodeptr->ptr<<endl;
	cout<<"current element from node is = "<<(nodeptr->element)<<endl;
	ll.InsertHead(3,&nodeptr);
	ll.Current(&element);
	cout<<"current element is = "<<element<<endl;
	cout<<"current node ptr is = "<<nodeptr<<endl;	
	cout<<"current element ptr is = "<<nodeptr->ptr<<endl;
	cout<<"current element from node is = "<<(nodeptr->element)<<endl;		
	return 0 ;
}
