#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using namespace std;

template <class Type>
class Queue
{
public:

	Queue(int maxElems);
	~Queue();

	void enqueue(const Type& elem);
	Type dequeue();

	bool empty() const;
	int size() const;

	void print() const;

private:

	Type* queueElems;
	int maxElems;
	int idEndElem;
};

#endif // !__QUEUE_H__


