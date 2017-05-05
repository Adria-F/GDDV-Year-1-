#include "DynamicArrays.h"

int main()
{
	DynArray<char> array1(3);
	cout << array1.size() << endl;
	cout << ((array1.insert(0, 'a')) ? "Inserted char a into index 0" : "Could not insert char into index 0") << endl;
	cout << ((array1.insert(2, 'c')) ? "Inserted char c into index 2" : "Could not insert char into index 2") << endl;
	cout << ((array1.insert(1, 'b')) ? "Inserted char b into index 1" : "Could not insert char into index 1") << endl;
	cout << ((array1.insert(2, 'c')) ? "Inserted char c into index 2" : "Could not insert char into index 2") << endl;
	array1.print();
	cout << ((array1.insert(3, 'd')) ? "Inserted char d into index 3" : "Could not insert char into index 3") << endl;
	cout << array1.size() << endl;
	array1.print();
	cout << ((array1.remove(2)) ? "Removed element into index 2" : "Could not remove element into index 2") << endl;
	array1.print();

	system("pause");
	return 0;
}