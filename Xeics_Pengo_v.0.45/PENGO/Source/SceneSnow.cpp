#include "SceneSnow.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModuleTileMap.h"

#include "SDL/include/SDL_scancode.h"

SceneSnow::SceneSnow(bool startEnabled) : Module(startEnabled)
{
	name = "s snow";

	skyAnim.PushBack({ 0, 0, 224, 104 });
	skyAnim.PushBack({ 232, 0, 224, 104 });
	skyAnim.PushBack({ 464, 0, 224, 104 });
	skyAnim.PushBack({ 696, 0, 224, 104 });
	skyAnim.PushBack({ 0, 108, 224, 104 });
	skyAnim.PushBack({ 232, 108, 224, 104 });
	skyAnim.PushBack({ 464, 108, 224, 104 });
	skyAnim.PushBack({ 696, 108, 224, 104 });
	skyAnim.PushBack({ 0, 216, 224, 104 });
	skyAnim.PushBack({ 232, 216, 224, 104 });
	skyAnim.PushBack({ 464, 216, 224, 104 });
	skyAnim.PushBack({ 696, 216, 224, 104 });
	skyAnim.PushBack({ 0, 324, 224, 104 });
	skyAnim.PushBack({ 232, 324, 224, 104 });
	skyAnim.PushBack({ 464, 324, 224, 104 });
	skyAnim.PushBack({ 696, 324, 224, 104 });
	skyAnim.speed = 0.02f;

	redPengo.PushBack({ 232, 432, 16, 16 });
	redPengo.PushBack({ 249, 432, 16, 16 });
	redPengo.speed = 0.1f;

	bluePengo.PushBack({ 232, 466, 16, 16 });
	bluePengo.PushBack({ 249, 466, 16, 16 });
	bluePengo.speed = 0.1f;

	yellowPengo.PushBack({ 232, 500, 16, 16 });
	yellowPengo.PushBack({ 249, 500, 16, 16 });
	yellowPengo.speed = 0.1f;

	pinkPengo.PushBack({ 436, 534, 16, 16 });
	pinkPengo.PushBack({ 453, 534, 16, 16 });
	pinkPengo.speed = 0.1f;

	greenSnoBee.PushBack({ 504, 432, 16, 16 });
	greenSnoBee.PushBack({ 521, 432, 16, 16 });
	greenSnoBee.speed = 0.1f;

	pinkSnoBee.PushBack({ 674, 466, 16, 16 });
	pinkSnoBee.PushBack({ 691, 466, 16, 16 });
	pinkSnoBee.speed = 0.1f;
}

SceneSnow::~SceneSnow()
{

}


bool SceneSnow::Start()
{
	LOG("Loading snowscene assets");

	bool ret = true;

	skyTexture = App->textures->Load("Assets/Intro.png");
	snowTexture=App->textures->Load("Assets/snow.png");



	
	//App->render->camera.x = 0;
	//App->render->camera.y = 0;

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

	App->input->Enable();


	return ret;
}

update_status SceneSnow::Update()
{
	GamePad& pad = App->input->pads[0];

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || pad.a == true)
	{
	
		App->fade->FadeToBlack(this, (Module*)App->scene, 30);

	}

	skyAnim.Update();
	redPengo.Update();
	bluePengo.Update();
	yellowPengo.Update();
	pinkPengo.Update();
	greenSnoBee.Update();
	pinkSnoBee.Update();

	
	return update_status::UPDATE_CONTINUE;
}


update_status SceneSnow::PostUpdate()
{
	App->render->Blit(snowTexture, 8, 104, NULL);
	App->render->Blit(skyTexture, 8, 0, &(skyAnim.GetCurrentFrame()), 0.4f);
	App->render->Blit(skyTexture, 16, 190, &(redPengo.GetCurrentFrame()), 0.4f);
	App->render->Blit(skyTexture, 40, 160, &(yellowPengo.GetCurrentFrame()), 0.4f);
	App->render->Blit(skyTexture, 45, 235, &(bluePengo.GetCurrentFrame()), 0.4f);
	App->render->Blit(skyTexture, 125, 132, &(pinkPengo.GetCurrentFrame()), 0.4f);

	App->render->Blit(skyTexture, 160, 185, &(greenSnoBee.GetCurrentFrame()), 0.4f);
	App->render->Blit(skyTexture, 170, 140, &(pinkSnoBee.GetCurrentFrame()), 0.4f);


	return update_status::UPDATE_CONTINUE;
}


bool SceneSnow::CleanUp()
{

	App->textures->Unload(skyTexture);
	App->textures->Unload(snowTexture);

	redPengo.Reset();
	bluePengo.Reset();
	yellowPengo.Reset();
	pinkPengo.Reset();
	greenSnoBee.Reset();
	pinkSnoBee.Reset();
	skyAnim.Reset();

	return true;
}