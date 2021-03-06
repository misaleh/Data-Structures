#ifndef S_LINKED
#define S_LINKED
struct node {   // the structure of the node
		int element;	
		node * ptr;
	 };
class Slinkedlist {
public:
	Slinkedlist(); 	       // constructor
	~Slinkedlist();  //destructor
	Slinkedlist(Slinkedlist&);  //copy constructor
	Slinkedlist& operator=(Slinkedlist&); //assingment overloading
	void InsertTail(int , node **);  // insert element at head , returns poitner to the node 
	void InsertHead(int , node **); // insert element at tail  , returns pointer to the node
	void RemoveHead(void);  //  remove element at head
	void RemoveTail(void);  //removes element from tail
	bool Search(int  );         // search the linked list
	bool Tail(int *);           // gets the last element
	bool Head(int *);            //gets the head of the list
	unsigned long int Size(void);// return size
	
private: 
	node *tail ;    // tale node
	node *head;    // head node
	unsigned long int size;   // to trace its size
};

#endif
