#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
 
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleBlocks.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTileMap.h"
#include "ModuleFonts.h"

#include"SceneIntro.h" 

#include "SDL/include/SDL_scancode.h"

ModuleScene::ModuleScene(bool startEnabled) :Module (startEnabled)
{
	name = "level 1";


	pYellow =SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 };


	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.speed = 0.1f;

	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.speed = 0.1f;

}

ModuleScene::~ModuleScene()
{

}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/background.png");
	chTexture = App->textures->Load("Assets/Characters.png");
	blTexture = App->textures->Load("Assets/Blocks.png");
	scTexture = App->textures->Load("Assets/Score.png");
	oneTexture = App->textures->Load("Assets/1p.png");

	App->audio->PlayMusic("Assets/Audio/popcorn.ogg", 1.0f);
	
	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);

	
	
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);

	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 32);

	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 176, 160);


	App->player->Enable();
	App->enemies->Enable();
	App->blocks->Enable();
	App->tilemap->Enable();

	enemiesAlive = 1;


	return ret;
}

update_status ModuleScene::Update()
{
	
	/*if (App->input->keys[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		enemiesAlive = 0;
	}

	if (App->input->keys[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->player->lifes = 0;
		App->player->destroyed = true;

	}*/

	if (enemiesAlive == 0)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneWin, 60);
	}
	


	oneAnim.Update();
	miniEnemyEggAnim.Update();
	return update_status::UPDATE_CONTINUE;
}



// Update: draw background
update_status ModuleScene::PostUpdate()
{

	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 8, 24, NULL);

	App->tilemap->DrawMap();


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

	
	if (App->player->lifes > 0 && App->player->destroyed)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 60);
		App->player->collider->pendingToDelete = true;
	}
	else if (App->player->lifes == 0 && App->player->destroyed)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneLose, 60);		
	}



	App->render->Blit(scTexture, 64, 280, &pYellow);


	App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);

	App->render->Blit(oneTexture, 16, 0, &(oneAnim.GetCurrentFrame()), 0.1f);


	
	return update_status::UPDATE_CONTINUE;
}



bool ModuleScene::CleanUp()
{
	App->player->Disable();
	App->enemies->Disable();
	App->blocks->Disable();
	App->tilemap->Disable();
	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}

