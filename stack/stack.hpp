#ifndef STACK_HPP
#define STACK_HPP

class STACK 
{
public:
	STACK(int size);
	~STACK();
	STACK(const STACK &Qcopy);
	STACK& operator=(STACK &Qcopy);
	bool Push(int element);
	bool Pop(int &element);
	void Front(int &element); 
	bool Empty();	
	unsigned int Size();
	
private:
	int _size;
	int front;
	int *arr;
};

#endif
