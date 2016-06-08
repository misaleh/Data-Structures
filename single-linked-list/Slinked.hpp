#ifndef S_LINKED
#define S_LINKED
struct node {   // the structure of the node
		int element;	
		node * ptr;
	 };
class Slinkedlist {
public:
	Slinkedlist(int); 	       // constructor
	void InsertTail(int , node **);  // insert element at head , returns poitner to the node 
	void InsertHead(int , node **); // insert element at tail  , returns pointer to the node
	void RemoveHead(void);  //  remove element at head
	bool Search(int * );         // search the linked list
	int Current(int *);           // gets the last element
private: 
	node *tail ;    // tale node
	node *head;    // head node
	long int size;   // to trace its size
};

#endif
