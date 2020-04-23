#include "SceneLose.h"

#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "SceneIntro.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"
#include <stdio.h>


#include <SDL\include\SDL_scancode.h>

SceneLose::SceneLose(bool startEnabled) : Module(startEnabled)
{

}

SceneLose::~SceneLose()
{

}


bool SceneLose::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/blackScreen.png");
	App->audio->PlayMusic("Assets/Audio/miss.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}
update_status SceneLose::Update()
{
	
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneLose::PostUpdate()
{
	// Draw everything --------------------------------------


	App->render->Blit(bgTexture, 0, 0, NULL);
	App->fonts->BlitText(80, 80, App->player->whiteFont, "you lose!");
	App->fonts->BlitText(40, 104, App->player->whiteFont, "thanks for playing");
	App->fonts->BlitText(56, 128, App->player->whiteFont, "try once more !");


	App->fonts->BlitText(76, 170, App->player->whiteFont, "press esc");



	return update_status::UPDATE_CONTINUE;
}