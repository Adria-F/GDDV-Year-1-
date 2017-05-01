#include "Stack.h"

template<class Type>
Stack<Type>::Stack(int maxElems): maxElems(maxElems), idTopElem(-1)
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
		delete stackElems[];
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
		for (int i = 0; i < maxElems; i++)
		{
			cout << stackElems[i] << endl;
		}
	}
}