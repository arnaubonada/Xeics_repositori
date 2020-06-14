#include "SceneWin.h"


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

#include <stdio.h>


#include <SDL\include\SDL_scancode.h>

SceneWin::SceneWin(bool startEnabled) : Module(startEnabled)
{
	name = "s win";

	pYellow = SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 }; pYellowFive = SDL_Rect{ 72,150,16,16 };

	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.speed = 0.1f;


	rightAnimWin.PushBack({ 96, 0, 16, 16 });
	rightAnimWin.PushBack({ 112, 0, 16, 16 });
	rightAnimWin.speed = 0.1f;

	leftAnimWin.PushBack({ 32, 0, 16, 16 });
	leftAnimWin.PushBack({ 48, 0, 16, 16 });
	leftAnimWin.speed = 0.1f;

	estampadadreta.PushBack({ 33, 32, 16, 16 });
	estampadadreta.speed = 0.1f;
	estampadadreta.loop = false;

	estampadaesquerra.PushBack({ 591, 32, 16, 16 });
	estampadaesquerra.speed = 0.1f;
	estampadaesquerra.loop = false;

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
	texturePengo = App->textures->Load("Assets/Characters.png");
	texturePengoEstampadaEsquerra = App->textures->Load("Assets/Characters2.png");
	App->audio->PlayMusic("Assets/Audio/ActClear.ogg", 1.0f);
	timeBonusFx = App->audio->LoadFx("Assets/Audio/TimeBonusExtend.wav");


	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;
	blueFont = App->fonts->Load("Assets/blueFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;
	yellowFont = App->fonts->Load("Assets/yellowFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;

	esquerra = false;
	dreta = false;
	espera = 0;

	bonusAddedOneTime = false;

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->input->Enable();

	return ret;
}
update_status SceneWin::Update()
{
	counterWinDelay++;
	if (counterWinDelay > 400) {
		counterWinFinish = true;
		counterWinDelay = 0;
	}


	if (/*(App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->tilemap->scenelvl1 == true && SpacePressed == false)|| */counterWinFinish && App->tilemap->scenelvl1 == true)
	{
		App->tilemap->scenelvl1 = false;
		App->tilemap->scenelvl2 = true;
		App->fade->FadeToBlack(this, (Module*)App->scene, 10);
		//SpacePressed = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
		App->tilemap->spawnFromBlock.Reset();
	}
	else if (counterWinFinish && App->tilemap->scenelvl2 == true)
	{
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = true;
		App->fade->FadeToBlack(this, (Module*)App->scene, 30);
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
		App->tilemap->spawnFromBlock.Reset();
	}
	else if (counterWinFinish && App->tilemap->scenelvl3 == true)
	{
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = true;
		App->fade->FadeToBlack(this, (Module*)App->scene, 30);
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;

	}
	else if (counterWinFinish && App->tilemap->scenelvl4 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 30);
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl5 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl6 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl7 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl8 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl9 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl10 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl11 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl12 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl13 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl14 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}
	else if (counterWinFinish && App->tilemap->scenelvl15 == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneFinish, 30);
		App->tilemap->scenelvl15 = false;
		App->tilemap->scenelvl1 = true;
		counterWinFinish = false;
		App->player->timerLevel = 0;
		App->player->minutes = 0;
		App->scene->lvlCont++;
		App->scene->lvlRep = 0;
		App->scene->i++;
		App->scene->cont = 0;
		App->tilemap->threeDiamonds = false;
		App->tilemap->timeDiamond = 0;
		App->tilemap->threeDiamondsDone = false;
		App->tilemap->timeDiamondStunned = 0;
	}

	scoreWin = App->player->score;

	rightAnimWin.Update();
	oneAnim.Update();
	estampadadreta.Update();
	estampadaesquerra.Update();
	leftAnimWin.Update();

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneWin::PostUpdate()
{
	// Draw everything --------------------------------------
	//dreta = false;
	if (App->player->position.x > 0 && App->player->position.x < 120 && !esquerra)
	{
		dreta = true;
	}
	if (App->player->position.x >= 120 && !dreta)
	{
		esquerra = true;
	}

	if (dreta) {

		if (App->player->position.x == 190) {
			App->render->Blit(texturePengo, App->player->position.x, App->player->position.y, &(estampadadreta.GetCurrentFrame()), 0.01f);
			count++;

		}
		else
		{
			App->render->Blit(texturePengo, App->player->position.x, App->player->position.y, &(rightAnimWin.GetCurrentFrame()), 0.1f);
			App->player->position.x += 2;
		}
		if (count == 60) {
			App->player->position.x++;
			count = 0;

		}
	}

	if (esquerra) {
		if (App->player->position.x == 40) {
			App->render->Blit(texturePengoEstampadaEsquerra, App->player->position.x, App->player->position.y, &(estampadaesquerra.GetCurrentFrame()), 0.01f);
			count++;

		}
		else
		{
			App->render->Blit(texturePengo, App->player->position.x, App->player->position.y, &(leftAnimWin.GetCurrentFrame()), 0.1f);
			App->player->position.x -= 2;
		}
		if (count == 60) {
			App->player->position.x--;
			count = 0;
		}
	}

	sprintf_s(scoreWinText, 10, "%d", scoreWin);
	if (scoreWin < 10) {
		App->fonts->BlitText(72, 0, whiteFont, scoreWinText);
	}
	else if (scoreWin >= 10 && scoreWin < 100) {
		App->fonts->BlitText(64, 0, whiteFont, scoreWinText);
	}
	else if (scoreWin >= 100 && scoreWin < 1000) {
		App->fonts->BlitText(56, 0, whiteFont, scoreWinText);
	}
	else if (scoreWin >= 1000 && scoreWin < 10000) {
		App->fonts->BlitText(48, 0, whiteFont, scoreWinText);
	}
	else if (scoreWin >= 10000 && scoreWin < 100000) {
		App->fonts->BlitText(40, 0, whiteFont, scoreWinText);
	}
	if (scoreWin > 20000) {
		App->fonts->BlitText(40, 0, whiteFont, scoreWinText);
		App->fonts->BlitText(112, 0, whiteFont, scoreWinText);
	}


	App->fonts->BlitText(144, 280, whiteFont, "© sega 1982");
	App->fonts->BlitText(88, 0, blueFont, "hi");

	if (scoreWin <= 20000) {
		App->fonts->BlitText(112, 0, whiteFont, "20000");
	}

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
		App->fonts->BlitText(16, 280, whiteFont, "act10");
	}
	else if (App->tilemap->scenelvl11 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act11");
	}
	else if (App->tilemap->scenelvl12 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act12");
	}
	else if (App->tilemap->scenelvl13 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act13");
	}
	else if (App->tilemap->scenelvl14 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act14");
	}
	else if (App->tilemap->scenelvl15 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act15");
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

	if (App->tilemap->scenelvl1 == true || App->tilemap->scenelvl6 == true || App->tilemap->scenelvl11 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl2 == true || App->tilemap->scenelvl7 == true || App->tilemap->scenelvl12 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl3 == true || App->tilemap->scenelvl8 == true || App->tilemap->scenelvl13 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
		App->render->Blit(scTexture, 96, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl4 == true || App->tilemap->scenelvl9 == true || App->tilemap->scenelvl14 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
		App->render->Blit(scTexture, 96, 280, &pYellow);
		App->render->Blit(scTexture, 112, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl5 == true || App->tilemap->scenelvl10 == true || App->tilemap->scenelvl15 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
		App->render->Blit(scTexture, 96, 280, &pYellow);
		App->render->Blit(scTexture, 112, 280, &pYellow);
		App->render->Blit(scTexture, 128, 280, &pYellow);
	}
	if (App->tilemap->scenelvl6 == true || App->tilemap->scenelvl7 == true || App->tilemap->scenelvl8 == true || App->tilemap->scenelvl9 == true || App->tilemap->scenelvl10 == true)
	{
		App->render->Blit(scTexture, 216, 8, &pYellowFive);
	}
	else if (App->tilemap->scenelvl11 == true || App->tilemap->scenelvl12 == true || App->tilemap->scenelvl13 == true || App->tilemap->scenelvl14 == true || App->tilemap->scenelvl15 == true)
	{
		App->render->Blit(scTexture, 216, 8, &pYellowFive);
		App->render->Blit(scTexture, 200, 8, &pYellowFive);
	}

	App->render->Blit(oneTexture, 16, 0, &(oneAnim.GetCurrentFrame()), 0.1f);
	espera++;

	if (espera > 170) {
		//App->render->Blit(bgTexture, 0, 0, NULL);
		App->fonts->BlitText(24, 40, yellowFont, "game time");
		App->fonts->BlitText(112, 40, whiteFont, App->player->minutesText);
		App->fonts->BlitText(128, 40, yellowFont, "min.");
		App->fonts->BlitText(160, 40, whiteFont, App->player->secondsText);
		App->fonts->BlitText(184, 40, yellowFont, "sec.");

		if (App->player->minutes < 1) {
			if (App->player->timerLevel >= 0 && App->player->timerLevel < 1200) {
				App->fonts->BlitText(24, 72, yellowFont, "from 00 to 19 .5000 pts.");
				App->fonts->BlitText(24, 88, blueFont, "from 20 to 29 .2000 pts.");
				App->fonts->BlitText(24, 104, blueFont, "from 30 to 39 .1000 pts.");
				App->fonts->BlitText(24, 120, blueFont, "from 40 to 49 ..500 pts.");
				App->fonts->BlitText(24, 136, blueFont, "from 50 to 59 ...10 pts.");
				App->fonts->BlitText(24, 152, blueFont, "60 and over");
				App->fonts->BlitText(144, 152, blueFont, "no bonus.");
				if (!bonusAddedOneTime) {
					App->player->score += 5000;
					App->audio->PlayFx(timeBonusFx, 0);
					bonusAddedOneTime = true;
				}
			}
			else if (App->player->timerLevel >= 1200 && App->player->timerLevel < 1800) {
				App->fonts->BlitText(24, 72, blueFont, "from 00 to 19 .5000 pts.");
				App->fonts->BlitText(24, 88, yellowFont, "from 20 to 29 .2000 pts.");
				App->fonts->BlitText(24, 104, blueFont, "from 30 to 39 .1000 pts.");
				App->fonts->BlitText(24, 120, blueFont, "from 40 to 49 ..500 pts.");
				App->fonts->BlitText(24, 136, blueFont, "from 50 to 59 ...10 pts.");
				App->fonts->BlitText(24, 152, blueFont, "60 and over");
				App->fonts->BlitText(144, 152, blueFont, "no bonus.");
				if (!bonusAddedOneTime) {
					App->player->score += 2000;
					App->audio->PlayFx(timeBonusFx, 0);
					bonusAddedOneTime = true;
				}
			}
			else if (App->player->timerLevel >= 1800 && App->player->timerLevel < 2400) {
				App->fonts->BlitText(24, 72, blueFont, "from 00 to 19 .5000 pts.");
				App->fonts->BlitText(24, 88, blueFont, "from 20 to 29 .2000 pts.");
				App->fonts->BlitText(24, 104, yellowFont, "from 30 to 39 .1000 pts.");
				App->fonts->BlitText(24, 120, blueFont, "from 40 to 49 ..500 pts.");
				App->fonts->BlitText(24, 136, blueFont, "from 50 to 59 ...10 pts.");
				App->fonts->BlitText(24, 152, blueFont, "60 and over");
				App->fonts->BlitText(144, 152, blueFont, "no bonus.");
				if (!bonusAddedOneTime) {
					App->player->score += 1000;
					App->audio->PlayFx(timeBonusFx, 0);
					bonusAddedOneTime = true;
				}
			}
			else if (App->player->timerLevel >= 2400 && App->player->timerLevel < 3000) {
				App->fonts->BlitText(24, 72, blueFont, "from 00 to 19 .5000 pts.");
				App->fonts->BlitText(24, 88, blueFont, "from 20 to 29 .2000 pts.");
				App->fonts->BlitText(24, 104, blueFont, "from 30 to 39 .1000 pts.");
				App->fonts->BlitText(24, 120, yellowFont, "from 40 to 49 ..500 pts.");
				App->fonts->BlitText(24, 136, blueFont, "from 50 to 59 ...10 pts.");
				App->fonts->BlitText(24, 152, blueFont, "60 and over");
				App->fonts->BlitText(144, 152, blueFont, "no bonus.");
				if (!bonusAddedOneTime) {
					App->player->score += 500;
					App->audio->PlayFx(timeBonusFx, 0);
					bonusAddedOneTime = true;
				}
			}
			else if (App->player->timerLevel >= 3000 && App->player->timerLevel < 3600) {
				App->fonts->BlitText(24, 72, blueFont, "from 00 to 19 .5000 pts.");
				App->fonts->BlitText(24, 88, blueFont, "from 20 to 29 .2000 pts.");
				App->fonts->BlitText(24, 104, blueFont, "from 30 to 39 .1000 pts.");
				App->fonts->BlitText(24, 120, blueFont, "from 40 to 49 ..500 pts.");
				App->fonts->BlitText(24, 136, yellowFont, "from 50 to 59 ...10 pts.");
				App->fonts->BlitText(24, 152, blueFont, "60 and over");
				App->fonts->BlitText(144, 152, blueFont, "no bonus.");
				if (!bonusAddedOneTime) {
					App->player->score += 10;
					App->audio->PlayFx(timeBonusFx, 0);
					bonusAddedOneTime = true;
				}
			}
		}
		else {
			App->fonts->BlitText(24, 72, blueFont, "from 00 to 19 .5000 pts.");
			App->fonts->BlitText(24, 88, blueFont, "from 20 to 29 .2000 pts.");
			App->fonts->BlitText(24, 104, blueFont, "from 30 to 39 .1000 pts.");
			App->fonts->BlitText(24, 120, blueFont, "from 40 to 49 ..500 pts.");
			App->fonts->BlitText(24, 136, blueFont, "from 50 to 59 ...10 pts.");
			App->fonts->BlitText(24, 152, yellowFont, "60 and over");
			App->fonts->BlitText(144, 152, yellowFont, "no bonus.");

		}

	}

	return update_status::UPDATE_CONTINUE;
}


bool SceneWin::CleanUp()
{


	App->fonts->UnLoad(whiteFont);
	App->fonts->UnLoad(blueFont);
	App->fonts->UnLoad(yellowFont);

	App->textures->Unload(bgTexture);
	App->textures->Unload(scTexture);
	App->textures->Unload(oneTexture);
	App->textures->Unload(texturePengo);
	App->textures->Unload(texturePengoEstampadaEsquerra);
	App->audio->UnloadFx(timeBonusFx);


	estampadadreta.Reset();
	estampadaesquerra.Reset();
	oneAnim.Reset();
	rightAnimWin.Reset();
	leftAnimWin.Reset();

	return true;
}
