#include "Application.h"
#include "Enemy_Mech.h"
#include "ModuleCollision.h"

Enemy_Mech::Enemy_Mech(int x, int y) : Enemy(x, y)
{
	left.PushBack({ 4, 105, 32, 32 });
	left.PushBack({ 37, 105, 32, 32 });
	left.PushBack({ 72, 105, 32, 32 });
	left.PushBack({ 37, 105, 32, 32 });
	left.speed = 0.2f;

	right.PushBack({ 106, 105, 31, 32 });
	right.PushBack({ 137, 105, 31, 32 });
	right.PushBack({ 170, 105, 31, 32 });
	right.PushBack({ 137, 105, 31, 32 });
	right.speed = 0.2f;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	animation = &left;
	path.PushBack({ -1.0f, 0.0f }, 150, animation);
	animation = &right;
	path.PushBack({ 1.0f, 0.0f }, 150, animation);
}

void Enemy_Mech::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);
}