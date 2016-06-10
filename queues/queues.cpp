#include "queues.hpp" 
#include <iostream>
QUEUE::QUEUE(int size)
	{
		q = new int[size];
		_size = size ;
		front = 0;
		rear= 0;
	}
QUEUE::~QUEUE()
	{
		delete q ;
	}
QUEUE::QUEUE(const QUEUE &Qcopy) // copy constructor
	{
		//std::cout<<"copying------>"<<std::endl;

		int i =  0;
		this->_size = Qcopy._size;
		this->front = Qcopy.front;
		this->rear = Qcopy.rear;
		this->q = new int[_size];
		for(i =Qcopy.front ; i <Qcopy.rear ; i++ )
		{			
			(this->q)[i] = (Qcopy.q)[i];
		}
		
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
