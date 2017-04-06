#ifndef __WATERPOKEMON_H__
#define __WATERPOKEMON_H__

#include "Pokemon.h"

class WaterPokemon : public Pokemon
{
public:

	WaterPokemon(const char* pname);
	~WaterPokemon();

	int damageAttack(Pokemon* pokemon2);
};

#endif // !__WATERPOKEMON_H__