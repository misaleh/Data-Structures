#include "disjoint.hpp"
#include <iostream>
node* disjoint_set::Add(int num)
{	
	node* A = new node;
	A->value = num;
	A->parent = A;
	//std::cout<<num<<" address = "<<A<<std::endl;
	//std::cout<<A<<" parent = "<<A->parent<<std::endl;
	return A;
}
void disjoint_set::Merge(node* A,node* B)
{
	A->parent = B;
	//std::cout<<A<<" parent = "<<A->parent<<std::endl;
}
node* disjoint_set::Find(node* A)
{
	//std::cout<<"one"<<std::endl;

	if(A->parent == A)
	{	
		//std::cout<<"bye"<<std::endl;
		return A;
	}
	
	Find(A->parent = A->parent->parent);
}
