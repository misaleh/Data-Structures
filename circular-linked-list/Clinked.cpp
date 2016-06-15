#include "Clinked.hpp"
#include <iostream>
Clinkedlist::Clinkedlist()
	{
		head  = new node ;   // allocate the head element
		tail  = head;
		tail->ptr = head;
		size =  0 ; 
	}
Clinkedlist::~Clinkedlist()
	{
		unsigned long int i  = 0 ; 
	
		for(i = 0 ; i <size ; i++) // delete all nodes
		{
			node *tmp = head;
			head = head->ptr;
			delete tmp;
		}
	}
Clinkedlist::Clinkedlist(Clinkedlist& Lcopy)
	{
		unsigned long int i  = 0 ; 
		//std::cout<<"Copying --------------->"<<std::endl;
		if(Lcopy.head == NULL) return; //if list is empty, nothing to copy
		this->head = new node;  //allocate new memory for the new head
		this->tail = new node;  //allocate new memory for the new head
		(this->head)->element =  (Lcopy.head)->element; //first element in new queue equals to the first element in old queue
		node* tmp = (Lcopy.head)->ptr;  //temproray equals to head of list to be copied from 
		node* tmp2 = (this->head);  //temproray equals to head of list to be copied t
		for(i = 1; i < Lcopy.size ; i++) //for number of nodes in old list
			{
				tmp2->ptr = new node; //allocate new node for the next
				tmp2 = tmp2->ptr;	//make temproray point to the next node
				tmp2->element = tmp->element; // copy the element from the othe list
				tmp = tmp->ptr;   //make the ptr of the original list points to the next element
			}
		//tmp2->ptr = head;
		tail = tmp2;
		this->size = Lcopy.size;
		(this->tail)->element = (Lcopy.tail)->element;
		(this->tail)->ptr = this->head;
	}
Clinkedlist& Clinkedlist::operator=(Clinkedlist& Lcopy)
	{
		unsigned long int i  = 0 ; 	
		//std::cout<<"Copying --------------->"<<std::endl;
		if(Lcopy.head == NULL) return *this; //if list is empty, nothing to copy
		this->head = new node;  //allocate new memory for the new head
		this->tail = new node;  //allocate new memory for the new head
		(this->head)->element =  (Lcopy.head)->element; //first element in new queue equals to the first element in old queue
		node* tmp = (Lcopy.head)->ptr;  //temproray equals to head of list to be copied from 
		node* tmp2 = (this->head);  //temproray equals to head of list to be copied t
		for(i = 1 ; i < Lcopy.size ; i++) //for number of nodes in old list
			{
				tmp2->ptr = new node; //allocate new node for the next
				tmp2 = tmp2->ptr;	//make temproray point to the next node
				tmp2->element = tmp->element; // copy the element from the othe list
				tmp = tmp->ptr;   //make the ptr of the original list points to the next element
			}
		tail = tmp2;
		this->size = Lcopy.size;
		(this->tail)->element = (Lcopy.tail)->element;
		(this->tail)->ptr = this->head;
		return *this;
	}
void Clinkedlist::InsertTail(int newelement, node **nodeptr)
	{
		if(size ==  0)  // not first time 
		{
			head->element = newelement;  // assign its value
			head->ptr = head ; // as it is also the tail now 
			size ++;
			return; 
		}
		node *newnode  = new node ;  // allocate new  node 
		newnode->element = newelement; // assign its value 
		*nodeptr =  newnode;
		tail->ptr=  newnode;  // the last element will point ot this 
		tail = newnode; //this is the last element now 
		tail->ptr = head; // point to head (circular)
		size++;
		
	}
void Clinkedlist::InsertHead(int newelement, node **nodeptr)
	{
		if(size ==  0)  // not first time 
		{
			head->element = newelement;  // assign its value
			head->ptr = head ; // as it is also the tail now 
			size ++;
			return; 
		}
		node *newnode  = new node ;  // allocate new node
		newnode->element = newelement;  // assign its value 
		newnode->ptr = head; // make it poin to the head 
		*nodeptr = newnode; // to return ptr to it 
		head = newnode; // it is the new head now
		tail->ptr = head;//point to head (circular)
		size ++;
		
	}	
void Clinkedlist::RemoveHead(void)
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
			delete head;
			head = next ;  //make it the head now
			tail->ptr = head; //point to head (circular)
		}
		size --;
		
	}
void Clinkedlist::RemoveTail(void)
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
					tail->ptr = head; //point to head(circular)
					break;
				}
			temp = temp->ptr;
			}
		}
		size --;

	}
bool Clinkedlist::Tail(int * currentelement)
	{
		if(size != 0)
			{
				 *currentelement  =  tail->element;  // return the tail element
				 return 1 ; // the list is not empty
			}
		else
			return 0;//list is empty

	} 
bool Clinkedlist::Head(int * headelement)
	{
		if(size != 0)
			{
				 *headelement  =  head->element;  // return the tail element
				 return 1 ; // the list is not empty
			}
		else
			return 0;//list is empty

	} 
bool Clinkedlist::Search(int lookfor)
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
unsigned long int Clinkedlist::Size(void)	
{
	return size;
}
