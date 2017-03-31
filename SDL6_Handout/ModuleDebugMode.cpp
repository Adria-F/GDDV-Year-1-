#include "Application.h"
#include "ModuleDebugMode.h"
#include "ModuleInput.h"
#include <iostream>
using namespace std;

ModuleDebugMode::ModuleDebugMode()
{

}

ModuleDebugMode::~ModuleDebugMode()
{

}

bool ModuleDebugMode::Start()
{
	LOG("Init debug mode");
	while (choice == false)
	{
		App->input->PreUpdate();
		if (App->input->keyboard[SDL_SCANCODE_Y])
		{
			choice = true;
			debugging = true;
		}
		else if (App->input->keyboard[SDL_SCANCODE_N])
		{
			choice = true;
			Disable();
		}
	}
	
	return debugging;
}

bool ModuleDebugMode::CleanUp()
{
	return true;
}

update_status ModuleDebugMode::Update()
{
	return UPDATE_CONTINUE;
}