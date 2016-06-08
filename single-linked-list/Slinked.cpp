#include "Slinked.hpp"
#include <iostream>
Slinkedlist::Slinkedlist(int head_element)
	{
		head  = new node ;   // allocate the head element
		head->element = head_element;	  //assign value to it
		tail  = head ;   //the tail is the head as it has one element only now 
		size =  1 ; 
	}
void Slinkedlist::InsertTail(int newelement, node *nodeptr)
	{
		node *newnode  = new node ;  // allocate new  node 
		newnode->element = newelement; // assign its value 
		nodeptr = newnode;  // to return ptr to it
		tail->ptr=  newnode;  // the last element will point ot this 
		tail = newnode; //this is the last element now 
		size++;
		std::cout<<" CLASS current node ptr is = "<<nodeptr<<std::endl;
		
	}
void Slinkedlist::InsertHead(int newelement, node *nodeptr)
	{
		node *newnode  = new node ;  // allocate new node
		newnode->element = newelement;  // assign its value 
		nodeptr = newnode; // to return ptr to it 
		newnode->ptr = head->ptr; // make it poin to the head 
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
				std::cout<<"ERROR: list is empty"<<std::endl;
		}		
		else{
			node * next =  head->ptr;  // the element next to head 
			head = next ;  //make it the head now
		}
		size --;
		
	}
int Slinkedlist::Current(int * currentelement)
	{
		if(size != 0)
			{
				 *currentelement  =  tail->element;  // return the tail element
				 return 1 ; // the list is not empty
			}
		else
			return 0;//list is empty

	} 
