#include "GrassPokemon.h"

GrassPokemon::GrassPokemon(const char* pname): Pokemon(pname)
{
	delete[] type;
	type = new char[6];
	sprintf(type, "Grass");
}

GrassPokemon::~GrassPokemon()
{
}

int GrassPokemon::damageAttack(Pokemon* pokemon2)
{
	int result = 10;

	if (strcmp(pokemon2->getType(), "Fire") == 0)
	{
		result = 5;
	}
	else if (strcmp(pokemon2->getType(), "Water") == 0)
	{
		result = 20;
	}

	return result;
}