#ifndef __FIREPOKEMON_H__
#define __FIREPOKEMON_H__

#include "Pokemon.h"

class FirePokemon : public Pokemon
{
public:

	FirePokemon(const char* pname);
	~FirePokemon();

	int damageAttack(Pokemon* pokemon2);
};

#endif // !__FIREPOKEMON_H__