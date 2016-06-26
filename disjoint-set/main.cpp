#include <iostream>
#include "disjoint.hpp"

using namespace std;

int main()
{
	node *set[5];
	disjoint_set ds;
	set[0] = ds.Add(0);
	set[1] = ds.Add(1);
	set[2] = ds.Add(2);
	set[3] = ds.Add(3);
	set[4] = ds.Add(4);
	cout << "Values"<<endl;
	for(int i = 0; i < 5 ; i++ )
	{
		cout<< set[i]->value<<endl;
	} 
	ds.Merge(set[2],set[3]);

	ds.Merge(set[3],set[4]);
	ds.Merge(set[1],set[0]);
	cout<<ds.Find(set[2])->value<<endl;
	cout<<ds.Find(set[2])->value<<endl;
	cout<<ds.Find(set[1])->value<<endl;

	return 0 ;
}
