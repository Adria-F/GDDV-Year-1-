#include "Warehouse.h"
#include "House.h"
#include "Temple.h"
#include <iostream>

int main()
{
	Building* building[3];
	building[0] = new Warehouse ("East Warehouse", 10, 20, 30);
	building[1] = new House ("Agripa's house", 2, 5, 10);
	building[2] = new Temple ("Mercury's Temple", "Mercury", 3);

	std::cout << "Warehouse name: " << building[0]->getName() << std::endl << std::endl;

	for (int i = 0; i < 3; i++)
	{
		building[i]->printInfo();
	}

	system("pause");
	return 0;
}