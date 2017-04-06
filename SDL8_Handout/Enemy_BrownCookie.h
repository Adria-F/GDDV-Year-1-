#ifndef __ENEMY_BROWNCOOKIE_H__
#define __ENEMY_BROWNCOOKIE_H__

#include "Enemy.h"
#include "p2Point.h"
#include "Path.h"

class Enemy_BrownCookie : public Enemy
{
private:
	iPoint original_pos;
	Animation up;
	Animation down;
	Path path;

public:

	Enemy_BrownCookie(int x, int y);

	void Move();
};

#endif // !__ENEMY_BROWNCOOKIES_H__
