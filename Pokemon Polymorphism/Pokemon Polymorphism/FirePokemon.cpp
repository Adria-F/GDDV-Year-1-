#include "FirePokemon.h"

FirePokemon::FirePokemon(const char* pname): Pokemon(pname)
{
	delete[] type;
	type = new char[9];
	sprintf(type, "Fire");
}

FirePokemon::~FirePokemon()
{
}

int FirePokemon::damageAttack(Pokemon* pokemon2)
{
	int result = 10;

	if (strcmp(pokemon2->getType(), "Grass") == 0)
	{
		result = 20;
	}
	else if (strcmp(pokemon2->getType(), "Water") == 0)
	{
		result = 5;
	}

	return result;
}