#include "queues.hpp" 
#include <iostream>
QUEUE::QUEUE(int size)
	{
		q = new int[size];
		_size = size ;
		front = 0;
		rear= 0;
		ElementCount = 0 ; 
	}
QUEUE::~QUEUE()
	{
		delete q ;
	}
QUEUE::QUEUE(const QUEUE &Qcopy) // copy constructor
	{
		q = new int[_size];
	}
bool QUEUE::Enqueue(int element)
	{
		if(rear == _size) return 0; //if full
		q[rear] = element;
		rear++;	
		return 1;
		
	}
bool QUEUE::Dequeue(int &element)
	{
		if(front == rear) return 0;//if empty
		element = q[front];
		front ++; 
		return 1;
	}
void QUEUE::Front(int &element)
	{
		element = q[front];
	}
bool QUEUE::Empty()
	{
		return (front == rear);
	}
unsigned int QUEUE::Size()
	{
		return (rear - front);
	}
