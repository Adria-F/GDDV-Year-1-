#ifndef __GRASSPOKEMON_H__
#define __GRASSPOKEMON_H__

#include "Pokemon.h"

class GrassPokemon : public Pokemon
{
public:

	GrassPokemon(const char* pname);
	~GrassPokemon();

	int damageAttack(Pokemon* pokemon2);
};

#endif // !__GRASSPOKEMON_H__