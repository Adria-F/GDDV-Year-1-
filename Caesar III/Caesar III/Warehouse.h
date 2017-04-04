#ifndef __WAREHOUSE_H__
#define __WAREHOUSE_H__

#include "Building.h"

class Warehouse : public Building
{
private:

	int wood, rocks, wheat;

public:

	Warehouse(const char* pname, int pwood, int procks, int pwheat) : wood(pwood), rocks(procks), wheat(pwheat), Building(pname)
	{
	}

	void printResources() const
	{
		cout << "-- " << name << " --" << endl;
		cout << "Wood: " << wood << endl;
		cout << "Rocks: " << rocks << endl;
		cout << "Wheat: " << wheat << endl << endl;
	}
};

#endif // !__WAREHOUSE__
