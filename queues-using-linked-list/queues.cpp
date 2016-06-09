#include "queues.hpp" 
#include <iostream>
QUEUE::QUEUE()
	{	
		front = 0;
		rear= 0; 
		head  = new node ;   // allocate the head element
		//head->element = head_element;	  //assign value to it
		tail  = head;
		//tail->ptr = NULL;
		size =  0 ; 
	}
QUEUE::~QUEUE()
	{
		int i  = 0 ; 
		while(head) // delete all nodes
		{
			node *tmp = head;
			head = head->ptr;
			delete tmp;
		}
	}
QUEUE::QUEUE(const QUEUE &Qcopy) // copy constructor
	{


	}
void QUEUE::Enqueue(int newelement)
	{
		if(size ==  0)  // not first time 
		{
			head->element = newelement;  // assign its value
			head->ptr = NULL ; // as it is also the tail now 
			size ++;
			rear++;	
			return; 
		}
		node *newnode  = new node ;  // allocate new node
		newnode->element = newelement;  // assign its value 
		newnode->ptr = head; // make it poin to the head 
		head = newnode; // it is the new head now
		//std::cout<<"enqueue"<<head->element <<std::endl;
		size ++;
		rear++;	
	
		
	}
void QUEUE::Dequeue(int &delement)
	{
		
		unsigned long int i ;
		node *temp = new node;	
		temp = head->ptr;
		if(size == 0 ) return;
		delement =  tail->element;  //  return the element element  
		if(size == 1) // if there is only one element in the queue remove it
		{
			delete tail;
			head->ptr = NULL ; 
			tail->ptr = NULL;
		}
		else if(size == 2 ) // just two elemenets make the head equals to the tail
		{
			tail = head;
		}

		else 
		{
			for(i = 0 ; i < size-2 ; i++)
			{
				if((temp->ptr) == tail) // if next element is the tail
				{
					delete tail; //delete the tail
					tail = temp;  // make it points to the element before 
					tail->ptr = NULL;   // the tail points to null 
					break;
				}
			temp = temp->ptr;  //go to next element 
			}
		}
		size --;
		front ++ ;

	}
void QUEUE::Front(int &felement)
	{
		felement = tail->element; //return last element
	}
bool QUEUE::Empty()
	{
		return (front == rear);
	}
unsigned int QUEUE::Size()
	{
		return (rear - front);
	}
