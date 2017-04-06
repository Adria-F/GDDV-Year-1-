#include "Pokemon.h"

Pokemon::Pokemon(const char* pname)
{
	type = new char[7];
	sprintf(type, "noType");

	int length = strlen(pname);
	name = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		name[i] = pname[i];
	}
	name[length] = '\0';
}

Pokemon::~Pokemon()
{
	delete[] type;
	delete[] name;
}

char* Pokemon::getName() const
{
	return name;
}

char* Pokemon::getType() const
{
	return type;
}