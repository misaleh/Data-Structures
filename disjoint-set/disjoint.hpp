#ifndef DISJOINT_H
#define DISJOINT_H

struct node{
int value;
node * parent;
} ;

class disjoint_set
{
public:
node* Add(int);  //ad memeber to the set
void Merge(node*,node*); // merge to nodes
node* Find(node*); // find the parent of the node
private:


};
#endif
