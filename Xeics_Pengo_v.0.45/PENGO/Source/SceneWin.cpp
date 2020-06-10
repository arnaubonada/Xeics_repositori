#include "SceneWin.h"


#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleTileMap.h"
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
	name = "s win";

	pYellow = SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 };

	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.speed = 0.1f;
}

SceneWin::~SceneWin()
{

}


bool SceneWin::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/blackScreen.png");
	scTexture = App->textures->Load("Assets/Score.png");
	oneTexture = App->textures->Load("Assets/1p.png");
	App->audio->PlayMusic("Assets/Audio/ActClear.ogg", 1.0f);

	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;
	blueFont = App->fonts->Load("Assets/blueFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;
	yellowFont = App->fonts->Load("Assets/yellowFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->input->Enable();

	return ret;
}
update_status SceneWin::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl1 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl2 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl3 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl4 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl5 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl6 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl7 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl8 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl9 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl10 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl11 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl12 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl13 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl14 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = true;
		App->player->lifes = 4;
	}
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl15 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl15 = false;
		App->tilemap->scenelvl1 = true;
		App->player->lifes = 4;
	}
	oneAnim.Update();
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneWin::PostUpdate()
{
	// Draw everything --------------------------------------


	//App->render->Blit(bgTexture, 0, 0, NULL);
	App->fonts->BlitText(24, 40, yellowFont, "game time");
	App->fonts->BlitText(128, 40, yellowFont, "min.");
	App->fonts->BlitText(184, 40, yellowFont, "sec.");
	App->fonts->BlitText(24, 72, blueFont, "from 00 to 19 .5000 pts.");
	App->fonts->BlitText(24, 88, blueFont, "from 20 to 29 .2000 pts.");
	App->fonts->BlitText(24, 104, blueFont, "from 30 to 39 .1000 pts.");
	App->fonts->BlitText(24, 120, blueFont, "from 40 to 49 ..500 pts.");
	App->fonts->BlitText(24, 136, blueFont, "from 50 to 59 ...10 pts.");
	App->fonts->BlitText(24, 152, blueFont, "60 and over");
	App->fonts->BlitText(144, 152, blueFont, "no bonus.");

	App->fonts->BlitText(56, 0, whiteFont, App->player->scoreText);
	App->fonts->BlitText(144, 280, whiteFont, "© sega 1982");
	App->fonts->BlitText(88, 0, blueFont, "hi");
	App->fonts->BlitText(112, 0, whiteFont, "20000");
	App->fonts->BlitText(160, 0, blueFont, "2p");
	App->fonts->BlitText(216, 0, whiteFont, "0");

	if (App->tilemap->scenelvl1 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 1");
	}
	else if (App->tilemap->scenelvl2 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 2");
	}
	else if (App->tilemap->scenelvl3 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 3");
	}
	else if (App->tilemap->scenelvl4 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 4");
	}
	else if (App->tilemap->scenelvl5 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 5");
	}
	else if (App->tilemap->scenelvl6 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 6");
	}
	else if (App->tilemap->scenelvl7 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 7");
	}
	else if (App->tilemap->scenelvl8 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 8");
	}
	else if (App->tilemap->scenelvl9 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 9");
	}
	else if (App->tilemap->scenelvl10 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 10");
	}
	else if (App->tilemap->scenelvl11 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 11");
	}
	else if (App->tilemap->scenelvl12 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 12");
	}
	else if (App->tilemap->scenelvl13 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 13");
	}
	else if (App->tilemap->scenelvl14 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 14");
	}
	else if (App->tilemap->scenelvl15 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 15");
	}

	if (App->player->lifes == 4) {
		App->render->Blit(scTexture, 8, 8, &pRed);
		App->render->Blit(scTexture, 24, 8, &pRed);
		App->render->Blit(scTexture, 40, 8, &pRed);
	}
	if (App->player->lifes == 3) {
		App->render->Blit(scTexture, 8, 8, &pRed);
		App->render->Blit(scTexture, 24, 8, &pRed);
	}
	if (App->player->lifes == 2) {
		App->render->Blit(scTexture, 8, 8, &pRed);
	}
	if (App->player->lifes == 1) {

	}
	App->render->Blit(scTexture, 64, 280, &pYellow);

	App->render->Blit(oneTexture, 16, 0, &(oneAnim.GetCurrentFrame()), 0.1f);

	return update_status::UPDATE_CONTINUE;
}