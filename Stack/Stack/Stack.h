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

#endif // !__STACK_H__