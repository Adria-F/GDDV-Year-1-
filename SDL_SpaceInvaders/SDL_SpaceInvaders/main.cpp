#include <iostream>
#include "SDL.h"
#include <time.h>
#include <math.h>

using namespace std;

#define Player_Speed 0.1
#define Bullet_Speed 0.25 //1 sec to cross screen 0.25
#define Enemy_Speed 0.2 //2.5 sec to cross screen 0.1
#define Spawn_Delay 1 //in seconds 1
#define Max_Enemies 3
#define Max_Lives 3
#define Max_Bullets 2


#pragma comment( lib, "SDL2.lib" )
#pragma comment ( lib, "SDL2main.lib" )

SDL_Event event;
bool shot[Max_Bullets];
float delay = 0;
int lives = Max_Lives;
int points = 0;
bool dead = false;
bool m_up = false, m_down = false, m_left = false, m_right = false, space = false;
float character_pos_y = 0, character_pos_x = 0;

void inputs(bool* running, SDL_Rect* character, SDL_Rect bullet[], float bullet_pos[])
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			*running = false;
			break;
		}	
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.repeat == 0)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_SPACE:
					for (int i = 0; i < Max_Bullets; i++)
					{
						if (shot[i] == false)
						{
							shot[i] = true;
							bullet[i].x = character->x;
							bullet[i].y = character->y + 12;
							bullet[i].w = 50;
							bullet[i].h = 25;
							bullet_pos[i] = bullet[i].x;
							break;
						}
					}
					break;
				case SDLK_UP:
					m_up = true;
					break;
				case SDLK_DOWN:
					m_down = true;
					break;
				case SDLK_LEFT:
					m_left = true;
					break;
				case SDLK_RIGHT:
					m_right = true;
					break;
				}
			}
		}
		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				m_up = false;
				break;
			case SDLK_DOWN:
				m_down = false;
				break;
			case SDLK_LEFT:
				m_left = false;
				break;
			case SDLK_RIGHT:
				m_right = false;
				break;
			}
		}
	}
}

void move_character(SDL_Rect* character)
{
	if (m_up && character->y > 30)
	{
		character_pos_y -= Player_Speed;
		character->y = character_pos_y;
	}
	if (m_down && character->y < 430)
	{
		character_pos_y += Player_Speed;
		character->y = character_pos_y;
	}
	if (m_left && character->x > 0)
	{
		character_pos_x -= Player_Speed;
		character->x = character_pos_x;
	}
	if (m_right && character->x < 670)
	{
		character_pos_x += Player_Speed;
		character->x = character_pos_x;
	}
}

void draw_bullet(SDL_Rect bullet[], float bullet_pos[], SDL_Surface* sprite, SDL_Surface* screen)
{
	for (int i = 0; i < Max_Bullets; i++)
	{
		if (shot[i] && bullet[i].x < 770)
		{
			bullet_pos[i] += Bullet_Speed;
			bullet[i].x = bullet_pos[i];
		}
		if (shot[i] && bullet[i].x == 770) { shot[i] = false; }
		if (shot[i])
		{
			SDL_BlitSurface(sprite, NULL, screen, &bullet[i]);
		}
	}
}

void timer(bool* spawn)
{
	delay += 0.1;

	if (delay > (Spawn_Delay * 333))
	{
		delay = 0;
		*spawn = true;
	}
	else
	{
		*spawn = false;
	}
}

void create_enemy(SDL_Rect* enemy, bool* free_enemy, float* enemy_pos)
{
	for (int i = 0; i < Max_Enemies; i++)
	{
		if (free_enemy[i])
		{
			free_enemy[i] = false;
			enemy[i].x = 720;
			enemy[i].y = rand() % 400 + 30;
			enemy_pos[i] = enemy[i].x;
			break;
		}
	}
}

void draw_enemy(SDL_Rect* enemy, bool* free_enemy, float* enemy_pos, SDL_Surface* sprite, SDL_Surface* screen)
{
	for (int i = 0; i < Max_Enemies; i++)
	{
		if (free_enemy[i] == false)
		{
			enemy_pos[i] -= Enemy_Speed;
			enemy[i].x = enemy_pos[i];
			SDL_BlitSurface(sprite, NULL, screen, &enemy[i]);
		}
	}
}

void detect_end(SDL_Rect* enemy, bool* free_enemy)
{
	for (int i = 0; i < Max_Enemies; i++)
	{
		if (free_enemy[i] == false)
		{
			if (enemy[i].x <= 0)
			{
				free_enemy[i] = true;
				if (lives > 0)
				{
					lives -= 1;
				}
			}
		}
	}
}

void bullet_hit(SDL_Rect* enemy, bool* free_enemy, SDL_Rect bullet[])
{
	for (int i = 0; i < Max_Enemies; i++)
	{
		for (int j = 0; j < Max_Bullets; j++)
		{
			if (free_enemy[i] == false)
			{
				if (shot[j] && ((bullet[j].x + 50) > enemy[i].x && bullet[j].x < (enemy[i].x + 40)) && ((bullet[j].y + 25) > enemy[i].y && bullet[j].y < (enemy[i].y + 40)))
				{
					free_enemy[i] = true;
					shot[j] = false;
					points += 5;
				}
			}
		}
	}
}

void draw_lives(SDL_Rect* heart, SDL_Surface* sprite, SDL_Surface* screen)
{
	for (int i = 0; i < lives; i++)
	{
		SDL_BlitSurface(sprite, NULL, screen, &heart[i]);
	}
}

void int_to_char(char* str, int num)
{
	int result;
	int length = 0;

	for (int i = 1; i < 7; i++)
	{
		result = num;
		result /= pow(10.0, i);
		if (result != 0)
		{
			length++;
		}
		else
		{
			break;
		}
	}
	length++;
	for (int i = 0; i < length; i++)
	{
		result = num;
		result /= pow(10.0, (length - 1 - i));
		str[i] = result + 48;
		num -= result * pow(10.0, (length - 1 - i));
	}
	str[length] = '\0';
}

void char_to_score(char* score, char points[])
{
	for (int i = 0; i < 7; i++)
	{
		score[28 + i] = points[i];
	}
}

bool detect_lose(SDL_Surface* gameover, SDL_Surface* screen, SDL_Rect* dead_screen)
{
	bool result = false;
	if (lives == 0)
	{
		SDL_BlitSurface(gameover, NULL, screen, dead_screen);
		result = true;
	}

	return result;
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_RENDERER_PRESENTVSYNC;

	char c_point[7];
	char score[35] = "Space Invaders      Points: ";

	SDL_Window *window;
	SDL_Renderer * renderer;

	SDL_CreateWindowAndRenderer(720, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "Space Invaders");
	SDL_Surface* screen = SDL_GetWindowSurface(window);

	SDL_Surface* background = SDL_LoadBMP("space.bmp");
	SDL_Surface* ship = SDL_LoadBMP("spaceship.bmp");
	SDL_Surface* missile = SDL_LoadBMP("bullet.bmp");
	SDL_Surface* ship2 = SDL_LoadBMP("enemy.bmp");
	SDL_Surface* lives = SDL_LoadBMP("heart.bmp");
	SDL_Surface* gameover = SDL_LoadBMP("gameover.bmp");

	SDL_Rect bckg;
	bckg.h = 480;
	bckg.w = 720;
	bckg.x = 0;
	bckg.y = 0;

	SDL_Rect character;
	character.h = 50;
	character.w = 50;
	character.x = 0;
	character.y = 215;
	character_pos_y = character.y;
	character_pos_x = character.x;

	SDL_Rect bullet[Max_Bullets];
	float bullet_pos[Max_Bullets];
	for (int i = 0; i < Max_Bullets; i++)
	{
		bullet[i].h = 25;
		bullet[i].w = 50;
		bullet[i].x = 0;
		bullet[i].y = 0;
		bullet_pos[Max_Bullets];
		shot[i] = false;
	}

	SDL_Rect enemy[Max_Enemies];
	bool* free_enemy = (bool*)malloc(Max_Enemies * sizeof(bool));
	for (int i = 0; i < Max_Enemies; i++)
	{
		enemy[i].h = 50;
		enemy[i].w = 50;
		enemy[i].x = 0;
		enemy[i].y = 50;
		free_enemy[i] = true;
	}
	float* enemy_pos = (float*)calloc(Max_Enemies, sizeof(float));
	bool spawn = false;

	SDL_Rect heart[Max_Lives];
	for (int i = 0; i < Max_Lives; i++)
	{
		heart[i].h = 30;
		heart[i].w = 30;
		heart[i].x = 0 + (i * 30);
		heart[i].y = 0;
	}

	SDL_Rect dead_screen;
	bckg.h = 480;
	bckg.w = 720;
	bckg.x = 0;
	bckg.y = 0;

	bool running = true;

	while (running)
	{
		SDL_BlitSurface(background, NULL, screen, &bckg);

		timer(&spawn); //comment to delet enemies

		if (spawn)
		{
			create_enemy(&enemy[0], free_enemy, &enemy_pos[0]);
		}

		inputs(&running, &character, &bullet[0], &bullet_pos[0]);
		move_character(&character);
		if (dead == false)
		{
			detect_end(&enemy[0], free_enemy);
			bullet_hit(&enemy[0], free_enemy, &bullet[0]);
			draw_bullet(&bullet[0], &bullet_pos[0], missile, screen);
			draw_enemy(&enemy[0], free_enemy, &enemy_pos[0], ship2, screen);
			SDL_BlitSurface(ship, NULL, screen, &character);
			draw_lives(&heart[0], lives, screen);

			int_to_char(&c_point[0], points);
			char_to_score(&score[0], c_point);
			SDL_SetWindowTitle(window, score);
		}

		dead = detect_lose(gameover, screen, &dead_screen);

		SDL_UpdateWindowSurface(window);
	}

	SDL_Quit();
	return 0;
}