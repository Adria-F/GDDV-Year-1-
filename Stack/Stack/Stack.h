#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using namespace std;

template <class Type>
class Stack
{
public:

	Stack(int maxElems);
	~Stack();

	void push(const Type& item);
	void pop();
	Type top() const;

	bool empty() const;
	int size() const;

	void print() const;

private:

	Type* stackElems;
	int maxElems;
	int idTopElem;
};

template<class Type>
Stack<Type>::Stack(int maxElems) : maxElems(maxElems), idTopElem(-1)
{
	if (maxElems > 0)
		stackElems = new Type[maxElems];
	else
		stackElems = NULL;
}

template<class Type>
Stack<Type>::~Stack()
{
	if (stackElems != NULL)
		delete stackElems;
	stackElems = NULL;
}

template<class Type>
void Stack<Type>::push(const Type& item)
{
	if (idTopElem < maxElems)
		stackElems[++idTopElem] = item;
}

template<class Type>
void Stack<Type>::pop()
{
	if (idTopElem > -1)
		idTopElem--;
}

template<class Type>
Type Stack<Type>::top() const
{
	return stackElems[idTopElem];
}

template<class Type>
bool Stack<Type>::empty() const
{
	return (idTopElem == -1);
}

template<class Type>
int Stack<Type>::size() const
{
	return idTopElem + 1;
}

template<class Type>
void Stack<Type>::print() const
{
	if (idTopElem > -1)
	{
		for (int i = idTopElem; i >= 0; i--)
		{
			cout << stackElems[i] << endl;
		}
	}
}

#endif // !__STACK_H__