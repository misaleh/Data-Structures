#include "stack.hpp" 
#include <iostream>
STACK::STACK(int size)
	{
		arr = new int[size];
		_size = size ;
		front = -1;
	}
STACK::~STACK()
	{
		delete[] arr ;
	}
STACK& STACK::operator=(STACK &Scopy)
	{
		int i =  0;
		this->_size = Scopy._size;
		this->front = Scopy.front;
		this->arr = new int[_size];
		for(i =0 ; i <=Scopy.front ; i++ )
		{			
			(this->arr)[i] = (Scopy.arr)[i];
		}
		return *this;
	}
STACK::STACK(const STACK &Scopy) // copy constructor
	{
		//std::cout<<"copying------>"<<std::endl;

		int i =  0;
		this->_size = Scopy._size;
		this->front = Scopy.front;
		this->arr = new int[_size];
		for(i =0 ; i <=Scopy.front ; i++ )
		{			
			(this->arr)[i] = (Scopy.arr)[i];
		}
		
	}
bool STACK::Push(int element)
	{
		front++;
		if(front == _size) return 0; //if full
		arr[front] = element;
			
		return 1;
		
	}
bool STACK::Pop(int &element)
	{
		if(front == -1) return 0;//if empty
		element = arr[front];
		front --; 
		return 1;
	}
void STACK::Front(int &element)
	{
		element = arr[front];
	}
bool STACK::Empty()
	{
		return (front == -1);
	}
unsigned int STACK::Size()
	{
		return front;
	}
