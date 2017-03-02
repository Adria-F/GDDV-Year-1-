#include <stdlib.h>
#include <iostream>
#include "SDL.h"
#include <Windows.h>
using namespace std;

#pragma comment( lib, "SDL2.lib" )
#pragma comment ( lib, "SDL2main.lib" )

int main(int argc, char* argv[])
{
	SDL_Window *window;
	SDL_Renderer * renderer;
	
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "1st Draw");

	SDL_Surface* screen = SDL_GetWindowSurface(window);
	SDL_Rect rect;
	rect.x = 170;
	rect.y = 90;
	rect.w = 300;
	rect.h = 300;

	Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0);
	Uint32 blue = SDL_MapRGB(screen->format, 0, 0, 255);

	SDL_FillRect(screen, NULL, red);
	SDL_FillRect(screen, &rect, blue);
	SDL_UpdateWindowSurface(window);

	SDL_Event event;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
				break;
			}
		}
	}

	SDL_Quit();
	return(EXIT_SUCCESS);
}