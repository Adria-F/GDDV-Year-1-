#ifndef __ENEMY_MECH_H__
#define __ENEMY_MECH_H__

#include "Enemy.h"
#include "p2Point.h"
#include "Path.h"

class Enemy_Mech : public Enemy
{
private:
	iPoint original_pos;
	Animation left;
	Animation right;
	Path path;

public:

	Enemy_Mech(int x, int y);

	void Move();
};

#endif // !__ENEMY_MECH_H__