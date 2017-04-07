#ifndef __HOUSE_H__
#define __HOUSE_H__

#include "Building.h"

class House : public Building
{
private:

	int floors, inhabitants, servants;

public:

	House(const char* pname, int pfloors, int pinhabitants, int pservants): floors(pfloors), inhabitants(pinhabitants), servants(pservants), Building(pname)
	{
	}

	void printInfo() const
	{
		cout << "-- " << name << " --" << endl;
		cout << "Num. floors: " << floors << endl;
		cout << "Num. inhabitants: " << inhabitants << endl;
		cout << "Num. servants: " << servants << endl << endl;
	}
};

#endif // !__HOUSE_H__
