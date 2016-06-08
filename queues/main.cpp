#include <iostream>
#include "queues.hpp"
// circular safe for coppying
using namespace std;
int main()
{	
	int element;
	//test cases
	QUEUE Q(15);
	// enqueu
	Q.Enqueue(1); 
	Q.Enqueue(3); 
	Q.Enqueue(-1); 
	Q.Enqueue(7);
	//front
	Q.Front(element);
	cout<<"Front = "<<element<<endl;
	Q.Front(element);
	cout<<"Front = "<<element<<endl;
	//dequeue
	Q.Dequeue(element);
	cout<<"Dequeue = "<<element<<endl;
	Q.Dequeue(element);
	cout<<"Dequeue = "<<element<<endl;
	//size
	cout<<"Size = "<<Q.Size()<<endl;
	return 0;
}
