#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "Module.h"

class SDL_Window;
class SDL_Renderer;
class SDL_Surface;

// TODO 1: Create the declaration of ModuleWindow class
class ModuleWindow : public Module
{
public:
	bool Init();
	bool CleanUp();
	SDL_Surface* screen;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif // __ModuleWindow_H__