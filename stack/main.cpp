#include <iostream>
#include "stack.hpp"
// circular safe for coppying
using namespace std;
int main()
{	
	int element;
	//test cases
	STACK S(15);
	// Push
	S.Push(1); 
	S.Push(3); 
	S.Push(-1); 
	S.Push(7);
	//front
	S.Front(element);
	cout<<"Front = "<<element<<endl;
	S.Front(element);
	cout<<"Front = "<<element<<endl;
	//Pop
	S.Pop(element);
	cout<<"Pop = "<<element<<endl;
	S.Pop(element);
	cout<<"Pop = "<<element<<endl;
	//size
	cout<<"Size = "<<S.Size()<<endl;
	STACK S2 = S;
	S.Front(element);
	cout<<"Front = "<<element<<endl;
	S2.Front(element);
	cout<<"Front2 = "<<element<<endl;
	

	return 0;
}
