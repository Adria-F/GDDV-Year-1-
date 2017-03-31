#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jumping;
	iPoint position;
<<<<<<< HEAD
	
private:
	
=======

private:

>>>>>>> origin/master
	bool jump;
	float jump_state;
};

#endif