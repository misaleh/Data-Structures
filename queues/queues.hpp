#ifndef QUEUE_HPP
#define QUEUE_HPP

class QUEUE 
{
public:
	QUEUE(int size);
	~QUEUE();
	QUEUE(const QUEUE &Qcopy);
	bool Enqueue(int element);
	bool Dequeue(int &element);
	void Front(int &element); 
	bool Empty();	
	unsigned int Size();
	
private:
	int _size;
	int front;
	int rear;
	int *q;
};

#endif
