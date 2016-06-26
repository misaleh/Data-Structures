#include "disjoint.hpp"
#include <iostream>
node* disjoint_set::Add(int num)
{	
	node* A = new node; //allocate new node for the number 
	A->value = num;  
	A->parent = A; //make it point to itself
	//std::cout<<num<<" address = "<<A<<std::endl;
	//std::cout<<A<<" parent = "<<A->parent<<std::endl;
	return A;
}
void disjoint_set::Merge(node* A,node* B)
{
	A->parent = B;   //make B its parent
	//std::cout<<A<<" parent = "<<A->parent<<std::endl;
}
node* disjoint_set::Find(node* A)
{
	//std::cout<<"one"<<std::endl;

	if(A->parent == A) //if it is the parent of itself
	{	
		//std::cout<<"bye"<<std::endl;
		return A;
	}
	
	Find(A->parent = A->parent->parent); //assingment for path compression
}
