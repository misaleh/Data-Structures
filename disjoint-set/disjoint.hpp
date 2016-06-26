#ifndef DISJOINT_H
#define DISJOINT_H

struct node{
int value;
node * parent;
} ;

class disjoint_set
{
public:
node* Add(int);
void Merge(node*,node*);
node* Find(node*);
private:


};
#endif
