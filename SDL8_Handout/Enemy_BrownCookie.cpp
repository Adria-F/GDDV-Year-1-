#include "Application.h"
#include "Enemy_BrownCookie.h"
#include "ModuleCollision.h"

Enemy_BrownCookie::Enemy_BrownCookie(int x, int y) : Enemy(x, y)
{
	up.PushBack({ 67, 71, 27, 23 });
	down.PushBack({ 199, 39, 27, 23 });

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	animation = &up;
	path.PushBack({-0.5f, -0.5f}, 130, animation);
	animation = &down;
	path.PushBack({ -0.5f, 0.5f }, 130, animation);
}

void Enemy_BrownCookie::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);
}