#include "stack.hpp"
#include <iostream>
STACK::STACK()
	{
		head  = new node ;   // allocate the head element
		tail  = head;
		tail->ptr = NULL;
		size =  0 ; 
	}
STACK::~STACK()
	{
		int i  = 0 ; 
		while(head) // delete all nodes
		{
			node *tmp = head;
			head = head->ptr;
			delete tmp;
		}	
	}
STACK::STACK(STACK& Lcopy)
	{
		//std::cout<<"Copying --------------->"<<std::endl;
		if(Lcopy.head == NULL) return; //if list is empty, nothing to copy
		this->head = new node;  //allocate new memory for the new head
		this->tail = new node;  //allocate new memory for the new head
		(this->head)->element =  (Lcopy.head)->element; //first element in new queue equals to the first element in old queue
		node* tmp = (Lcopy.head)->ptr;  //temproray equals to head of list to be copied from 
		node* tmp2 = (this->head);  //temproray equals to head of list to be copied t
		while((tmp) != NULL) //as long has not reached tail
			{
				tmp2->ptr = new node; //allocate new node for the next
				tmp2 = tmp2->ptr;	//make temproray point to the next node
				tmp2->element = tmp->element; // copy the element from the othe list
				tmp = tmp->ptr;   //make the ptr of the original list points to the next element
			}
		tail = tmp2;
		tmp2->ptr = NULL; // next node to the tail is null
		this->size = Lcopy.size;
		(this->tail)->element = (Lcopy.tail)->element;
	}
STACK& STACK::operator=(STACK& Lcopy)
	{
		//std::cout<<"Copying --------------->"<<std::endl;
		if(Lcopy.head == NULL) return *this; //if list is empty, nothing to copy
		this->head = new node;  //allocate new memory for the new head
		this->tail = new node;  //allocate new memory for the new head
		(this->head)->element =  (Lcopy.head)->element; //first element in new queue equals to the first element in old queue
		node* tmp = (Lcopy.head)->ptr;  //temproray equals to head of list to be copied from 
		node* tmp2 = (this->head);  //temproray equals to head of list to be copied t
		while((tmp) != NULL) //as long has not reached tail
			{
				tmp2->ptr = new node; //allocate new node for the next
				tmp2 = tmp2->ptr;	//make temproray point to the next node
				tmp2->element = tmp->element; // copy the element from the othe list
				tmp = tmp->ptr;   //make the ptr of the original list points to the next element
			}
		tail = tmp2;
		tmp2->ptr = NULL; // next node to the tail is null
		this->size = Lcopy.size;
		(this->tail)->element = (Lcopy.tail)->element;
		return *this;
	}

void STACK::Push(int newelement)
	{
			if(size ==  0)  // not first time 
		{
			head->element = newelement;  // assign its value
			head->ptr = NULL ; // as it is also the tail now 
			size ++;
			return; 
		}
		node *newnode  = new node ;  // allocate new node
		newnode->element = newelement;  // assign its value 
		newnode->ptr = head; // make it poin to the head 
		head = newnode; // it is the new head now
		size ++;
		
	}	
void STACK::Pop(int & retelement)
	{
		if(size == 1) //if it was the last element
		{
			retelement = head->element;
			head->ptr = NULL ; 
			tail->ptr = NULL;

		}
		else if(size == 0)  // if there is no elements
		{
				//std::cout<<"ERROR: list is empty"<<std::endl;
				return;
		}		
		else
		{
			retelement = head->element;
			node * next =  head->ptr;  // the element next to head 
			delete head;
			head = next ;  //make it the head now
		}
		size --;
		
	}

bool STACK::front(int  &headelement)
	{
		if(size != 0)
			{
				 headelement  =  head->element;  // return the tail element
				 return 1 ; // the list is not empty
			}
		else
			return 0;//list is empty

	} 

unsigned long int STACK::Size(void)	
{
	return size;
}
