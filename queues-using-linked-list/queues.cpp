#include "queues.hpp" 
#include <iostream>
QUEUE::QUEUE()
	{	
		front = 0;
		rear= 0; 
		head  = new node ;   // allocate the head element
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
			//std::cout<<"destruction of"<<tmp<<std::endl;
			delete tmp;
		}
	}
QUEUE::QUEUE(const QUEUE &Qcopy) // copy constructor
	{	
		//std::cout<<"Copying --------------->"<<std::endl;
		if(Qcopy.head == NULL) return; //if list is empty, nothing to copy
		this->head = new node;  //allocate new memory for the new head
		(this->head)->element =  (Qcopy.head)->element; //first element in new queue equals to the first element in old queue
		node* tmp = (Qcopy.head)->ptr;  //temproray equals to head of list to be copied from 
		node* tmp2 = (this->head);  //temproray equals to head of list to be copied to


		while((tmp) != NULL) //as long has not reached tail
			{
				tmp2->ptr = new node; //allocate new node for the next
				tmp2 = tmp2->ptr;	//make temproray point to the next node
				tmp2->element = tmp->element; // copy the element from the othe list
				tmp = tmp->ptr;   //make the ptr of the original list points to the next element
			}
		tmp2->ptr = NULL; // next node to the tail is null
		(this->tail) = tmp2; // the last node is the tail 
		this->rear  = Qcopy.rear;
		this->front = Qcopy.front;
		this->size = Qcopy.size;
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
		if(size == 0) return;

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
