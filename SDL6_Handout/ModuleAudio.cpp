#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio()
{
}


ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	return true;
}

void ModuleAudio::Play(sound_type type)
{
	switch (type)
	{
	case sound_type::MUSIC:
	{
		Mix_PlayMusic(music, -1);
	}
	case sound_type::EFFECT:
	{
		Mix_PlayMusic(effect, 1);
	}
	}
}


void ModuleAudio::Stop()
{
	Mix_FreeMusic(music);
	music = nullptr;
	Mix_HaltMusic();
}

bool ModuleAudio::Load(const char* path, sound_type type)
{
	switch (type)
	{
	case sound_type::MUSIC:
	{
		music = Mix_LoadMUS(path);
	}
	case sound_type::EFFECT:
	{
		effect = Mix_LoadMUS(path);
	}
	}

	return true;
}

bool ModuleAudio::CleanUp()
{
	return true;
}
