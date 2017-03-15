#include <iostream>
#include "SDL\include\SDL.h"
#include "SDL_image\include\SDL_image.h"
#include <time.h>
using namespace std;

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment ( lib, "SDL/libx86/SDL2main.lib" )
#pragma comment ( lib, "SDL_image/libx86/SDL2_image.lib" )

#define A_UP g.cell.x = 0; g.cell. y = 88;
#define A_DOWN g.cell.x = 88; g.cell. y = 88;
#define A_LEFT g.cell.x = 176; g.cell. y = 88;
#define A_RIGHT g.cell.x = 264; g.cell. y = 88;

struct globals
{
	SDL_Window *window;
	SDL_Renderer * renderer;
	SDL_Texture* background = nullptr;
	SDL_Texture* arrows = nullptr;
	SDL_Texture* numbers = nullptr;
	SDL_Texture* choice = nullptr;
	SDL_Rect cell;
	int num;
	int num_inst;
	int points = 0;
	int level = 1;
	int c_point;
	int d_point;
	int u_point;
	int time = 0;
	int timer;
	int bckg_time = 0;
	int bckg_stage = 0;
	bool change = false;
	int correct = 2;
	bool pressed = false;
}g;

void Start()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_CreateWindowAndRenderer(720, 480, SDL_WINDOW_RESIZABLE, &g.window, &g.renderer);
	SDL_SetWindowTitle(g.window, "Dancing Game");

	g.background = SDL_CreateTextureFromSurface(g.renderer, IMG_Load("resources/background.png"));
	g.arrows = SDL_CreateTextureFromSurface(g.renderer, IMG_Load("resources/arrows.png"));
	g.numbers = SDL_CreateTextureFromSurface(g.renderer, IMG_Load("resources/numbers.png"));
	g.choice = SDL_CreateTextureFromSurface(g.renderer, IMG_Load("resources/choice.png"));

	g.cell.h = 88;
	g.cell.w = 88;
}

void GetPoints_CheckLvl()
{
	g.c_point = g.points / 100;
	g.d_point = (g.points - (g.c_point * 100)) / 10;
	g.u_point = (g.points - (g.c_point * 100) - (g.d_point * 10));

	if (g.points >= (100 * g.level))
	{
		g.level++;
	}
}

void Draw()
{
	SDL_Rect target;
	
	//Draw Background
	target.h = 480;
	target.w = 720;
	target.x = 0;
	target.y = 0;
	
	SDL_RenderCopy(g.renderer, g.background, NULL, &target);

	//Draw A_Bckg
	target.h = 160;
	target.w = 160;
	target.x = 271;
	target.y = 250;
	g.cell.h = 160;
	g.cell.w = 160;
	g.cell.x = 160 * g.bckg_stage;
	g.cell.y = 0;

	SDL_RenderCopy(g.renderer, g.choice, &g.cell, &target);

	//Draw Arrows
	target.h = 151;
	target.w = 151;
	target.x = 271;
	target.y = 250;
	g.cell.h = 88;
	g.cell.w = 88;
	if (g.num == 0)
	{
		A_DOWN
			if (g.correct == 0)
			{
				g.cell.y = 176;
			}
			else if (g.correct == 1)
			{
				g.cell.y = 0;
			}
	}
	if (g.num == 1)
	{
		A_UP
			if (g.correct == 0)
			{
				g.cell.y = 176;
			}
			else if (g.correct == 1)
			{
				g.cell.y = 0;
			}
	}
	if (g.num == 2)
	{
		A_LEFT
			if (g.correct == 0)
			{
				g.cell.y = 176;
			}
			else if (g.correct == 1)
			{
				g.cell.y = 0;
			}
	}
	if (g.num == 3)
	{
		A_RIGHT
			if (g.correct == 0)
			{
				g.cell.y = 176;
			}
			else if (g.correct == 1)
			{
				g.cell.y = 0;
			}
	}

	SDL_RenderCopy(g.renderer, g.arrows, &g.cell, &target);

	GetPoints_CheckLvl();
	//Draw Level
	target.h = 88;
	target.w = 88;
	target.x = 76;
	target.y = 88;
	g.cell.y = 14;
	g.cell.x = (6 + (g.level * 88));

	SDL_RenderCopy(g.renderer, g.numbers, &g.cell, &target);

	//Draw Points
		//Point C
	target.h = 88;
	target.w = 88;
	target.x = 488;
	target.y = 91;
	g.cell.y = 14;
	g.cell.x = (6 + (g.c_point * 88));

	SDL_RenderCopy(g.renderer, g.numbers, &g.cell, &target);
		//Point D
	target.h = 88;
	target.w = 88;
	target.x = 540;
	target.y = 91;
	g.cell.y = 14;
	g.cell.x = (6 + (g.d_point * 88));

	SDL_RenderCopy(g.renderer, g.numbers, &g.cell, &target);
		//Point U
	target.h = 88;
	target.w = 88;
	target.x = 592;
	target.y = 91;
	g.cell.y = 14;
	g.cell.x = (6 + (g.u_point * 88));

	SDL_RenderCopy(g.renderer, g.numbers, &g.cell, &target);

	//Render
	SDL_RenderPresent(g.renderer);
}

void Finnish()
{
	IMG_Quit();
	SDL_Quit();
}

void timer()
{
	g.timer = 3500 - (250 * (g.level - 1));
	g.time += 1;
	if (g.time > g.timer)
	{	
		if (g.pressed == false)
		{
			g.correct = 0;
			g.points -= 3;
			g.pressed = true;
			g.time -= 500;
		}
		else
		{
			g.change = true;
			g.correct = 2;
			g.pressed = false;
			g.time = 0;
		}
	}
	g.bckg_time += 1;
	if (g.bckg_time > 300)
	{
		g.bckg_stage++;
		g.bckg_time = 0;
	}
	if (g.bckg_stage == 7)
	{
		g.bckg_stage = 0;
	}
}

bool Input()
{

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (g.pressed == false)
		{
			if (event.type == SDL_QUIT) { return false; }
			if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_DOWN:
					if (g.num == 0)
					{
						g.points += 5;
						g.correct = 1;
					}
					else if (g.points >= 3)
					{
						g.points -= 3;
						g.correct = 0;
					}
					else
					{
						g.points = 0;
						g.correct = 0;
					}
					g.pressed = true;
					break;
				case SDLK_UP:
					if (g.num == 1)
					{
						g.points += 5;
						g.correct = 1;
					}
					else if (g.points >= 3)
					{
						g.points -= 3;
						g.correct = 0;
					}
					else
					{
						g.points = 0;
						g.correct = 0;
					}
					g.pressed = true;
					break;
				case SDLK_LEFT:
					if (g.num == 2)
					{
						g.points += 5;
						g.correct = 1;
					}
					else if (g.points >= 3)
					{
						g.points -= 3;
						g.correct = 0;
					}
					else
					{
						g.points = 0;
						g.correct = 0;
					}
					g.pressed = true;
					break;
				case SDLK_RIGHT:
					if (g.num == 3)
					{
						g.points += 5;
						g.correct = 1;
					}
					else if (g.points >= 3)
					{
						g.points -= 3;
						g.correct = 0;
					}
					else
					{
						g.points = 0;
						g.correct = 0;
					}
					g.pressed = true;
					break;
				case SDLK_ESCAPE:
					return false;
				}
			}
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	Start();

	while (Input())
	{
		timer();
		if (g.change)
		{
			g.num_inst = g.num;
			while (g.num == g.num_inst)
			{
				g.num = rand() % 4;
			}
			g.change = false;
		}
		
		Draw();

	}


	Finnish();

	return 0;
}