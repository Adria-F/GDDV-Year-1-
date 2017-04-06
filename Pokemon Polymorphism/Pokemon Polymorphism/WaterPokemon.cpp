#include "WaterPokemon.h"

WaterPokemon::WaterPokemon(const char* pname): Pokemon(pname)
{
	delete[] type;
	type = new char[9];
	sprintf(type, "Water");
}

WaterPokemon::~WaterPokemon()
{
}

int WaterPokemon::damageAttack(Pokemon* pokemon2)
{
	int result = 10;

	if (strcmp(pokemon2->getType(), "Fire") == 0)
	{
		result = 20;
	}
	else if (strcmp(pokemon2->getType(), "Grass") == 0)
	{
		result = 5;
	}

	return result;
}