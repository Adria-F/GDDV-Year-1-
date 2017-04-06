#ifndef __POMEMON_H__
#define __POMEMON_H__

#include <iostream>

class Pokemon
{
public:

	Pokemon(const char* pname);
	~Pokemon();

	char* getName() const;
	char* getType() const;
	virtual int damageAttack(Pokemon* pokemon2) = 0;

protected:

	char* name;
	char* type;
};

#endif // !__POMEMON_H__
