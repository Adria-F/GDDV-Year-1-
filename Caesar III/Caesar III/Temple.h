#ifndef __TEMPLE_H__
#define __TEMPLE_H__

#include "Building.h"

class Temple : public Building
{
private:

	char god[15];
	int priests;

public:

	Temple(const char* pname, const char* pgod, int ppriests) : priests(ppriests), Building(pname)
	{
		sprintf_s(god, pgod);
	}

	void printInfo() const
	{
		cout << "-- " << name << " --" << endl;
		cout << "God: " << god << endl;
		cout << "Num. priests: " << priests << endl << endl;
	}
};

#endif // !__TEMPLE_H__
