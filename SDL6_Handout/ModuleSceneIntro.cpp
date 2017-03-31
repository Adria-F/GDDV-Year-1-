#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"
#include "ModuleAudio.h"

ModuleSceneIntro::ModuleSceneIntro()
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{
}

bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro scene");
	
	background = App->textures->Load("rtype/intro.png");
	App->audio->Load("rtype/intro.ogg", App->audio->MUSIC);
	App->audio->Play(App->audio->MUSIC);

	return true;
}

bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	App->textures->Unload(background);
	App->audio->Stop();

	return true;
}

update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, -25, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->scene_space);
		App->audio->Load("rtype/starting.wav", App->audio->EFFECT);
		App->audio->Play(App->audio->EFFECT);
	}

	return UPDATE_CONTINUE;
}
