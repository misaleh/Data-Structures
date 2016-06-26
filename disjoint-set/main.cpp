#include <iostream>
#include "disjoint.hpp"

using namespace std;

int main()
{
	node *set[5];
	disjoint_set ds;
	//add nodes
	set[0] = ds.Add(0);
	set[1] = ds.Add(1);
	set[2] = ds.Add(2);
	set[3] = ds.Add(3);
	set[4] = ds.Add(4);


	ds.Merge(set[2],set[3]);  //merge 2 and 3 
	ds.Merge(set[3],set[4]);  //merge 3 and 4
	cout<<ds.Find(set[2])->value<<endl; //find the value of parent of 2
	ds.Merge(set[1],set[4]);  //merge 1 and 4
	ds.Merge(set[4],set[0]);  //merge 4 and 0 
	cout<<ds.Find(set[2])->value<<endl; //find the value of parent of 2
	cout<<ds.Find(set[1])->value<<endl; //find the value of parent of 1 

	return 0 ;
}
