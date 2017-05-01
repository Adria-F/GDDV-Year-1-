#include "Queue.h"

int main()
{
	Queue<int> queue1(5);
	queue1.enqueue(1);
	queue1.enqueue(2);
	queue1.enqueue(3);
	queue1.enqueue(4);
	queue1.enqueue(5);
	queue1.print();
	cout << "Element removed from queue:" << queue1.dequeue() << endl;
	queue1.print();

	system("pause");
	return 0;
}