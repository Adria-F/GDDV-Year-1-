#ifndef __ELECTRICPOKEMON_H__
#define __ELECTRICPOKEMON_H__

#include "Pokemon.h"

class ElectricPokemon : public Pokemon
{
public:

	ElectricPokemon(const char* pname);
	~ElectricPokemon();

	int damageAttack(Pokemon* pokemon2);
};

#endif // !__ELECTRICPOKEMON_H__