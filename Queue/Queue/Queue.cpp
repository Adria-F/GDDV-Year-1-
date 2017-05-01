#include "Queue.h"

template<class Type>
Queue<Type>::Queue(int maxElems): maxElems(maxElems), idEndElem(-1)
{
	queueElems = new Type[maxElems];
}

template<class Type>
Queue<Type>::~Queue()
{
	delete queueElems[];
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