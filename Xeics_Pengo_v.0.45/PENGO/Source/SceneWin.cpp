#include "SceneWin.h"

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

SceneWin::SceneWin(bool startEnabled) : Module(startEnabled)
{

}

SceneWin::~SceneWin()
{

}


bool SceneWin::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/blackScreen.png");
	App->audio->PlayMusic("Assets/Audio/ActClear.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}
update_status SceneWin::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->sceneIntro->contador = 3;
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
		App->player->lifes = 3;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneWin::PostUpdate()
{
	// Draw everything --------------------------------------


	App->render->Blit(bgTexture, 0, 0, NULL);
	App->fonts->BlitText(40, 104, App->player->whiteFont, "thanks for playing");
	App->fonts->BlitText(40, 104, App->player->whiteFont, "thanks for playing");
	App->fonts->BlitText(56, 128, App->player->whiteFont, "try once more !");

	return update_status::UPDATE_CONTINUE;
}