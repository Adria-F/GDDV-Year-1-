#include "Warehouse.h"
#include "House.h"
#include "Temple.h"
#include <iostream>

int main()
{
	Warehouse w("East Warehouse", 10, 20, 30);
	House h("Agripa's house", 2, 5, 10);
	Temple t("Mercury's Temple", "Mercury", 3);

	std::cout << "Warehouse name: " << w.getName() << std::endl << std::endl;

	w.printResources();
	h.printHouse();
	t.printTemple();

	system("pause");
	return 0;
}