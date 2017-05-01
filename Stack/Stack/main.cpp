#include "Stack.h"

int main()
{
	Stack<int> stackInt(5);
	Stack<char> stackChar(3);
	Stack<bool> stackBool(2);

	//Test stack int
	stackInt.push(4);
	stackInt.pop();
	cout << ((stackInt.empty()) ? "The Stack is empty" : "The Stack is not empty") << endl;
	stackInt.push(5);
	stackInt.push(6);
	stackInt.push(7);
	cout << stackInt.size() << endl;
	stackInt.push(8);
	cout << stackInt.top() << endl;
	stackInt.push(9);
	cout << ((stackInt.empty()) ? "The Stack is empty" : "The Stack is not empty") << endl;
	stackInt.print();

	getchar();
	return 0;
}