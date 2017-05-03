#include "List.h"
using namespace std;

int main()
{
	List<char> list1;

	cout << ((list1.empty())? "List is empty":"List is not empty") << endl;
	list1.pushFront('b');
	list1.pushBack('e');
	list1.insert(1, 'c');
	list1.insert(2, 'd');
	cout << "Size: " << (list1.size()) << endl;
	list1.pushFront('a');
	list1.print();

	system("pause");
	return 0;
}