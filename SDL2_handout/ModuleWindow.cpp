#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL\include\SDL.h"
#include "SDL_image\include\SDL_image.h"
#include "SDL_mixer\include\SDL_mixer.h"

bool ModuleWindow::Init()
{
	LOG("ModuleWindow Init");
	bool result = true;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		LOG("Unable to initialize SDL: %s\n", SDL_GetError());
		result = false;
	}

	if (SDL_CreateWindowAndRenderer(720, 480, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0)
	{
		LOG("Unable to crate window: %s\n", SDL_GetError());
		result = false;
	}

	return result;
}

bool ModuleWindow::CleanUp()
{
	LOG("ModuleWindow CleanUp!");

	SDL_Quit();

	return true;
}

// TODO 2: Init the library and check for possible error
// using SDL_GetError()

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

