#include "Slinked.hpp"
#include <iostream>
Slinkedlist::Slinkedlist(int head_element)
	{
		head  = new node ;   // allocate the head element
		head->element = head_element;	  //assign value to it
		tail  = head;
		tail->ptr = NULL;
		tail->prev = NULL;
		size =  1 ; 
	}
void Slinkedlist::InsertTail(int newelement, node **nodeptr)
	{
		node *previous = new node;
		node *newnode  = new node ;  // allocate new  node 
		newnode->element = newelement; // assign its value 
		*nodeptr =  newnode;
		previous = tail;
		tail->ptr=  newnode;  // the last element will point ot this 
		tail = newnode; //this is the last element now 
		tail->ptr = NULL;
		tail->prev = previous;  // previous pointer of tail will point to the old tail
		size++;
		
	}
void Slinkedlist::InsertHead(int newelement, node **nodeptr)
	{
		node *newnode  = new node ;  // allocate new node
		newnode->element = newelement;  // assign its value 
		newnode->ptr = head; // make it poin to the head 
		head->prev = newnode ; // old head previous pointer will point to the new head
		*nodeptr = newnode; // to return ptr to it 
		head = newnode; // it is the new head now
		size ++;
		
	}	
void Slinkedlist::RemoveHead(void)
	{
		if(size == 1) //if it was the last element
		{
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
			node * next =  head->ptr;  // the element next to head 
			head = next ;  //make it the head now
			head->prev = NULL;
		}
		size --;
		
	}
void Slinkedlist::RemoveTail(void)
	{	
		unsigned long int i ;
		node *temp = new node;	
		temp = head->ptr;
		if(size == 0 ) return;
		else if(size == 1)
		{
			delete tail;
			head->ptr = NULL ; 
			tail->ptr = NULL;
		}
		else if(size == 2 )
		{
			tail = head;
		}

		else 
		{
			for(i = 0 ; i < size-2 ; i++)
			{
				if((temp->ptr) == tail)
				{
					delete tail;
					tail = temp;
					tail->ptr = NULL; 
					break;
				}
			temp = temp->ptr;
			}
		}
		size --;

	}
bool Slinkedlist::Tail(int * currentelement)
	{
		if(size != 0)
			{
				 *currentelement  =  tail->element;  // return the tail element
				 return 1 ; // the list is not empty
			}
		else
			return 0;//list is empty

	} 
bool Slinkedlist::Head(int * headelement)
	{
		if(size != 0)
			{
				 *headelement  =  head->element;  // return the tail element
				 return 1 ; // the list is not empty
			}
		else
			return 0;//list is empty

	} 
bool Slinkedlist::Search(int lookfor)
	{
		unsigned long int i ;
		node temp  = *head ;
		for(i = 0 ; i < size ; i++)
		{
			if(temp.element == lookfor)
			{
				return 1;
			}
			if(temp.ptr == NULL) return 0;
		temp = *(temp.ptr);			
		}
		return 0 ;
	}
unsigned long int Slinkedlist::Size(void)	
	{
		return size;
	}

void Slinkedlist::PrintForward(void)  
	{
		node temp  = *head ;
		unsigned long int i ;
		for(i = 0 ; i < size ; i++)
		{
			std::cout<<temp.element<<std::endl;
			if(temp.ptr == NULL) return;
			temp = *(temp.ptr);
		}
		
	}  
void Slinkedlist::PrintBackward(void)
	{
		node temp  = *tail ;
		unsigned long int i ;
		for(i = 0 ; i < size ; i++)
		{
			std::cout<<temp.element<<std::endl;
			if(temp.prev == NULL) return;
			temp = *(temp.prev);
		}
	}
