#include "ModuleDebugInfo.h"

#include "Application.h"
#include "Globals.h"

#include "ModuleFonts.h"
#include "ModuleInput.h"
#include "ModuleCollisions.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleTileMap.h"
#include "ModuleFadeToBlack.h"

#include "SDL/include/SDL.h"
#include <stdio.h>

ModuleDebugInfo::ModuleDebugInfo(bool startEnabled) : Module(startEnabled)
{
	name = "debug";
}

ModuleDebugInfo::~ModuleDebugInfo()
{

}

bool ModuleDebugInfo::Start()
{
	char lookupTable[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	debugFont = App->fonts->Load("Assets/rtype_font3.png", lookupTable, 2);

	return true;
}

bool ModuleDebugInfo::CleanUp()
{

	App->fonts->UnLoad(debugFont);
	return true;
}

update_status ModuleDebugInfo::Update()
{
	if (App->input->keys[SDL_SCANCODE_F2] == KEY_DOWN)
		debugMemLeaks = !debugMemLeaks;

	if (App->input->keys[SDL_SCANCODE_F3] == KEY_DOWN)
		inspectedModule = (Module*)App->player;

	if (App->input->keys[SDL_SCANCODE_F4] == KEY_DOWN)
		inspectedModule = (Module*)App->sceneIntro;

	if (App->input->keys[SDL_SCANCODE_F5] == KEY_DOWN)
		inspectedModule = (Module*)App-> scene;

	if (App->input->keys[SDL_SCANCODE_F6] == KEY_DOWN)
		inspectedModule = nullptr;
	if (App->input->keys[SDL_SCANCODE_F8] == KEY_DOWN)
		App->player->Collide = false;

	if (App->input->keys[SDL_SCANCODE_F9] == KEY_DOWN)
	{
		App->player->Collide = true;
		App->player->destroyed = true;
		App->player->lifes--;
	}

	if (App->input->keys[SDL_SCANCODE_F10] == KEY_DOWN)
	{
		App->scene->enemiesAlive = 0;
	}


	if (App->input->keys[SDL_SCANCODE_M] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = true;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl1);
	}	
	
	if (App->input->keys[SDL_SCANCODE_N] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = true;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl2);

	}
	if (App->input->keys[SDL_SCANCODE_B] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);


		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = true;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl3);

	}

	if (App->input->keys[SDL_SCANCODE_4] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = true;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl4);

	}

	if (App->input->keys[SDL_SCANCODE_5] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = true;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl5);

	}

	if (App->input->keys[SDL_SCANCODE_6] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = true;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl6);

	}

	if (App->input->keys[SDL_SCANCODE_7] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = true;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl7);

	}

	if (App->input->keys[SDL_SCANCODE_8] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = true;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl8);

	}

	if (App->input->keys[SDL_SCANCODE_9] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = true;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl9);

	}

	if (App->input->keys[SDL_SCANCODE_P] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = true;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl10);

	}

	if (App->input->keys[SDL_SCANCODE_O] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = true;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl11);

	}

	if (App->input->keys[SDL_SCANCODE_I] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = true;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl12);

	}

	if (App->input->keys[SDL_SCANCODE_U] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = true;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl13);

	}

	if (App->input->keys[SDL_SCANCODE_Y] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = true;
		App->tilemap->scenelvl15 = false;

		App->tilemap->LoadMap(App->tilemap->lvl14);

	}

	if (App->input->keys[SDL_SCANCODE_T] == KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 10);

		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = true;

		App->tilemap->LoadMap(App->tilemap->lvl15);

	}



	return update_status::UPDATE_CONTINUE;
}

update_status ModuleDebugInfo::PostUpdate()
{
	if (!debugMemLeaks)
	{}
	else
	{
		App->fonts->BlitText(10, 1, debugFont, "press f2 to close mem leaks debug info");

		App->fonts->BlitText(10, 20, debugFont, "total loaded resources");

		// Display total textures loaded
		sprintf_s(debugText, 150, "textures  %i", App->textures->GetTexturesCount());
		App->fonts->BlitText(20, 35, debugFont, debugText);

		// Display total audio files loaded
		sprintf_s(debugText, 150, "audio fx  %i", App->audio->GetFxCount());
		App->fonts->BlitText(20, 50, debugFont, debugText);

		// Display total font files loaded
		sprintf_s(debugText, 150, "fonts     %i", App->fonts->GetFontsCount());
		App->fonts->BlitText(20, 65, debugFont, debugText);

		// Display total colliders loaded
		sprintf_s(debugText, 150, "colliders %i", App->collisions->GetColliderCount());
		App->fonts->BlitText(20, 80, debugFont, debugText);

		// Display total particles loaded
		sprintf_s(debugText, 150, "particles %i", App->particles->GetParticlesCount());
		App->fonts->BlitText(20, 95, debugFont, debugText);

		App->fonts->BlitText(10, 120, debugFont, "press f3 to f6 to display specific modules");

		if (inspectedModule != nullptr)
		{
			DrawModuleResources(inspectedModule);
		}
	}

	return update_status::UPDATE_CONTINUE;
}

void ModuleDebugInfo::DrawModuleResources(Module* module)
{
	sprintf_s(debugText, 150, "module %s", module->name);
	App->fonts->BlitText(20, 140, debugFont, debugText);

	sprintf_s(debugText, 150, "active  total");
	App->fonts->BlitText(155, 140, debugFont, debugText);

	sprintf_s(debugText, 150, "textures          %i      %i", module->activeTextures, module->totalTextures);
	App->fonts->BlitText(30, 155, debugFont, debugText);

	sprintf_s(debugText, 150, "audio fx          %i      %i", module->activeFx, module->totalFx);
	App->fonts->BlitText(30, 170, debugFont, debugText);

	sprintf_s(debugText, 150, "fonts             %i      %i", module->activeFonts, module->totalFonts);
	App->fonts->BlitText(30, 185, debugFont, debugText);

	sprintf_s(debugText, 150, "colliders         %i      %i", module->activeColliders, module->totalColliders);
	App->fonts->BlitText(30, 200, debugFont, debugText);
}