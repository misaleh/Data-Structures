#ifndef QUEUE_HPP
#define QUEUE_HPP
struct node {   // the structure of the node
		int element;	
		node * ptr;
	 };
class QUEUE 
{
public:
	QUEUE();
	~QUEUE();
	QUEUE(const QUEUE &Qcopy);
	QUEUE& operator=(QUEUE &Qcopy);
	void Enqueue(int element);
	void Dequeue(int &element);
	void Front(int &element); 
	bool Empty();	
	unsigned int Size();
	
private:
	int size;  // size of the queue 
	int front;  //points to front
	int rear;  // points to rear
	node *tail ;    // tale node
	node *head;    // head node
};

#endif
