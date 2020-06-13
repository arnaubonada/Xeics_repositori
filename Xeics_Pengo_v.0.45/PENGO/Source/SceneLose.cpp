#include "SceneLose.h"

#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "SceneIntro.h"
#include "ModuleCollisions.h"
#include "ModuleTileMap.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"
#include <stdio.h>
#include "ModuleScene.h"
#include "SceneWin.h"


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
	GamePad& pad = App->input->pads[0];

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || pad.a==true) {
		App->fade->FadeToBlack(this, (Module*)App->sceneSnow, 30);

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
		losed = true;
	
		App->sceneWin->counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->scene->enemiesAlive = 0;
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

bool SceneLose::CleanUp()
{

	App->textures->Unload(bgTexture);
	App->fonts->UnLoad(whiteFont);


	return true;
}