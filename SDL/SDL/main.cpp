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
	SDL_SetWindowTitle(window, "Shooting Spaceship");

	SDL_Surface* screen = SDL_GetWindowSurface(window);
	
	SDL_Surface* ship = SDL_LoadBMP("spaceship.bmp");
	SDL_Surface* s_bullet = SDL_LoadBMP("bullet.bmp");
	SDL_Surface* enemy = SDL_LoadBMP("enemy.bmp");

	SDL_Rect rect;
	rect.x = 295;
	rect.y = 215;
	rect.w = 50;
	rect.h = 50;

	SDL_Rect bullet;
	bool shot = false;
	float float_bullet_pos;

	Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);

	SDL_Rect objective;
	objective.x = 580;
	objective.y = 220;
	objective.w = 40;
	objective.h = 40;
	bool obj_hit = false;
	float obj_mov = -0.1;
	float float_enemy_pos = objective.y;

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
			if (event.type == SDL_KEYDOWN)
			{					
				switch (event.key.keysym.sym)						
				{
					case SDLK_ESCAPE:
						running = false;
						break;
					case SDLK_SPACE:
						if (shot == false)
						{
							shot = true;
							bullet.x = rect.x;
							bullet.y = rect.y + 12;
							bullet.w = 50;
							bullet.h = 25;
							float_bullet_pos = bullet.x;
						}
						break;
					case SDLK_UP:
						if (rect.y > 0)
						{
							rect.y -= 10;
						}
						break;
					case SDLK_DOWN:
						if (rect.y < 430)
						{
							rect.y += 10;
						}
						break;
					case SDLK_LEFT:
						if (rect.x > 0)
						{
							rect.x -= 10;
						}
						break;
					case SDLK_RIGHT:
						if (rect.x < 590)
						{
							rect.x += 10;
						}
						break;
					case SDLK_r:
						obj_hit = false;
						break;
				}
			}
		}
		SDL_FillRect(screen, NULL, white);
		if (shot && obj_hit == false && ((bullet.x + 50) > objective.x && bullet.x < (objective.x + 40)) && ((bullet.y + 25) > objective.y && bullet.y < (objective.y + 40)))
		{
			obj_hit = true;
			shot = false;
		}
		if (shot && bullet.x < 642)
		{
			float_bullet_pos += 0.25;
			bullet.x = float_bullet_pos;
		}
		if (shot && bullet.x == 642) { shot = false; }
		if (shot)
		{
			SDL_BlitSurface(s_bullet, NULL, screen, &bullet);
		}
		SDL_BlitSurface(ship, NULL, screen, &rect);

		if (obj_hit == false)
		{
			SDL_BlitSurface(enemy, NULL, screen, &objective);
			float_enemy_pos += obj_mov;
			if (objective.y == 20)
			{
				obj_mov = 0.1;
			}
			if (objective.y == 420)
			{
				obj_mov = -0.1;
			}
			objective.y = float_enemy_pos;
		}
		SDL_UpdateWindowSurface(window);
	}

	SDL_Quit();
	return(EXIT_SUCCESS);
}