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

template<class Type>
Queue<Type>::Queue(int maxElems) : maxElems(maxElems), idEndElem(-1)
{
	queueElems = new Type[maxElems];
}

template<class Type>
Queue<Type>::~Queue()
{
	delete queueElems;
	queueElems = nullptr;
}

template<class Type>
void Queue<Type>::enqueue(const Type& elem)
{
	queueElems[++idEndElem] = elem;
}

template<class Type>
Type Queue<Type>::dequeue()
{
	Type temp = NULL;
	if (idEndElem > -1)
	{
		temp = queueElems[0];
		for (int i = 1; i <= idEndElem; i++)
		{
			queueElems[i - 1] = queueElems[i];
		}
		queueElems[idEndElem--] = NULL;
	}

	return temp;
}

template<class Type>
bool Queue<Type>::empty() const
{
	return (idEndElem == -1);
}

template<class Type>
int Queue<Type>::size() const
{
	return maxElems;
}

template<class Type>
void Queue<Type>::print() const
{
	if (this->empty() == false)
	{
		for (int i = 0; i < maxElems; i++)
		{
			cout << queueElems[i] << endl;
		}
	}
}

#endif // !__QUEUE_H__


