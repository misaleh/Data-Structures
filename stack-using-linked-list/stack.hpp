#ifndef STACK_HPP
#define STACK_HPP
struct node {   // the structure of the node
		int element;	
		node * ptr;
	 };
class STACK {
public:
	STACK(); 	       // constructor
	~STACK();  //destructor
	STACK(STACK&);  //copy constructor
	STACK& operator=(STACK&); //assingment overloading
	void Push(int); // insert element at tail  , returns pointer to the node
	void Pop(int &);  //  remove element at head
	bool front(int &);           
	unsigned long int Size(void);// return size
	
private: 
	node *head;    // head node
	node* tail;
	unsigned long int size;   // to trace its size
};

#endif
