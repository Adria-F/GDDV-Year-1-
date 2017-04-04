#ifndef __ITEM__
#define __ITEM__

#include "Player.h"
#include <iostream>

class Item
{
private:

	char name[15];

public:

	Item(char iName[])
	{
		sprintf_s(name, iName);
	}

	~Item()
	{
	}

	friend class Player;
};

#endif // !__ITEM__
