
#include "stack.hpp"
#include <iostream>
using namespace std;

int main()
{
	bool result ; //used for searching
	/*  Some test cases */
	int element;
	STACK S;
	cout<<"*Push = 5"<<endl;
	S.Push(5);
	S.front(element);	
	cout<<"	front is = "<<element<<endl;	
	//InsertHead
	cout<<"*Push = 3"<<endl;
	S.Push(3);
	S.front(element);
	cout<<"*Pop"<<endl;
	S.Pop(element);
	cout<<"	Pop  is = "<<element<<endl;
	S.front(element);
	cout<<"	front  is = "<<element<<endl;

	//Size
	cout<<"Size of list =  "<<S.Size()<<endl;

	//copy
	STACK S2;
	S2 = S ;
	S2.front(element);
	cout<<"	front S2 is = "<<element<<endl;

	return 0 ;
}
