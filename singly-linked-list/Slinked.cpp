#include "Slinked.hpp"
#include <iostream>
Slinkedlist::Slinkedlist()
	{
		head  = new node ;   // allocate the head element
		//head->element = head_element;	  //assign value to it
		tail  = head;
		tail->ptr = NULL;
		size =  0 ; 
	}
Slinkedlist::~Slinkedlist()
	{
		int i  = 0 ; 
		while(head) // delete all nodes
		{
			node *tmp = head;
			head = head->ptr;
			delete tmp;
		}	
	}
Slinkedlist::Slinkedlist(Slinkedlist& Lcopy)
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
		tmp2->ptr = NULL; // next node to the tail is null
		this->size = Lcopy.size;
		(this->tail)->element = (Lcopy.tail)->element;
	}
Slinkedlist& Slinkedlist::operator=(Slinkedlist& Lcopy)
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
		tmp2->ptr = NULL; // next node to the tail is null
		this->size = Lcopy.size;
		(this->tail)->element = (Lcopy.tail)->element;
		return *this;
	}
void Slinkedlist::InsertTail(int newelement, node **nodeptr)
	{
		if(size ==  0)  // not first time 
		{
			head->element = newelement;  // assign its value
			head->ptr = NULL ; // as it is also the tail now 
			size ++;
			return; 
		}
		node *newnode  = new node ;  // allocate new  node 
		newnode->element = newelement; // assign its value 
		*nodeptr =  newnode;
		tail->ptr=  newnode;  // the last element will point ot this 
		tail = newnode; //this is the last element now 
		tail->ptr = NULL;
		size++;
		
	}
void Slinkedlist::InsertHead(int newelement, node **nodeptr)
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
