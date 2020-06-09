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
	name = "s lose";
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


	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;


	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->input->Enable();


	return ret;
}
update_status SceneLose::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->scene, 30);
	}
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneLose::PostUpdate()
{
	// Draw everything --------------------------------------


	//App->render->Blit(bgTexture, 0, 0, NULL);

	App->fonts->BlitText(40, 104, whiteFont, "thanks for playing");
	App->fonts->BlitText(56, 128, whiteFont, "try once more !");




	return update_status::UPDATE_CONTINUE;
}