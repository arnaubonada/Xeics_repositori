#include "SceneFinish.h"

#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleTileMap.h"
#include "ModuleScene.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "SceneIntro.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"
#include "SceneWin.h"

SceneFinish::SceneFinish(bool startEnabled) : Module(startEnabled)
{
	name = "s finish";

}

SceneFinish::~SceneFinish()
{

}


bool SceneFinish::Start()
{
	LOG("Loading snowscene assets");

	bool ret = true;
	App->audio->PlayMusic("Assets/Audio/finishSong.ogg", 1.0f);
	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;
	yellowFont = App->fonts->Load("Assets/yellowFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;


	App->input->Enable();


	return ret;
}

update_status SceneFinish::Update()
{
	GamePad& pad = App->input->pads[0];

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || pad.a == true)
	{

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
		App->player->lifes = 4;
		App->scene->cont = 0;
		App->scene->enemiesAlive = 0;
	}

	return update_status::UPDATE_CONTINUE;
}


update_status SceneFinish::PostUpdate()
{
	App->fonts->BlitText(48, 104, yellowFont, "congratulations !!");
	App->fonts->BlitText(78, 128, whiteFont, "you win");
	App->fonts->BlitText(38, 152, whiteFont, "we hope you enjoy it");

	return update_status::UPDATE_CONTINUE;
}


bool SceneFinish::CleanUp()
{


	App->fonts->UnLoad(whiteFont);
	App->fonts->UnLoad(yellowFont);



	return true;
}