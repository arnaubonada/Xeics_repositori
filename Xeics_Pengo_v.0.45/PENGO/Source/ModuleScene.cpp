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


#include"SceneIntro.h" 

#include "SDL/include/SDL_scancode.h"

ModuleScene::ModuleScene(bool startEnabled) :Module (startEnabled)
{
	name = "level 1";

	//noBlocks = SDL_Rect{ 50,50,16,16 }; blocks = SDL_Rect{ 708,0,16,16 }; pengo = SDL_Rect{ 0,0,16,16 }; snobees = SDL_Rect{ 0,160,16,16 };

	pYellow =SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 };
	rosita = SDL_Rect{ 90,82,8,8 };
	//pmatriux = 0;
	//pmatriuy = 0;

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
	App->audio->PlayMusic("Assets/Audio/popcorn.ogg", 1.0f);
	


	//MATRIU
	
	//map.x = 8;
	//map.y = 32;
	//
	//for (pmatriux = 0; pmatriux < 13; pmatriux++) {
	//	map.y = 32;
	//	for (pmatriuy = 0; pmatriuy < 15; pmatriuy++) {

	//		matriu[map.x][map.y] = BLOCKS;
	//		
	//		map.y += 16;

	//	}
	//	map.x += 16;
	//}	


	/*
	if (rep)			//COLLIDERS PARETS
	{

		//Bottomside
		bottomWall = App->collisions->AddCollider({ 0, 272, 224, 8 }, Collider::Type::WALL);

		//leftside
		leftWall = App->collisions->AddCollider({ 0, 24, 8, 256 }, Collider::Type::WALL);

		//topside
		topWall = App->collisions->AddCollider({ 0, 24, 224, 8 }, Collider::Type::WALL);

		//rightside
		rightWall = App->collisions->AddCollider({ 216, 24, 8, 256 }, Collider::Type::WALL);

	}
	*/


	// Enemies ---
	//App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 24, 64);

	//blocks 
	//App->blocks->AddBlock(BLOCK_TYPE::NORMAL, 200, 200);

	App->player->Enable();
	App->enemies->Enable();
	App->blocks->Enable();


	enemiesAlive = 1;


	return ret;
}

update_status ModuleScene::Update()
{
	
	if (App->input->keys[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		enemiesAlive = 0;
	}

	if (App->input->keys[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->player->lifes = 0;
		App->player->destroyed = true;

	}

	if (enemiesAlive == 0)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneWin, 60);
	}
	


	return update_status::UPDATE_CONTINUE;
}









// Update: draw background
update_status ModuleScene::PostUpdate()
{

	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 8, 24, NULL);

	App->tilemap->DrawMap();


	if (App->player->lifes == 3) {
		App->render->Blit(scTexture, 8, 8, &pRed);
		App->render->Blit(scTexture, 24, 8, &pRed);
		App->render->Blit(scTexture, 40, 8, &pRed);
	}
	if (App->player->lifes == 2) {
		App->render->Blit(scTexture, 8, 8, &pRed);
		App->render->Blit(scTexture, 24, 8, &pRed);
	}
	if (App->player->lifes == 1) {
		App->render->Blit(scTexture, 8, 8, &pRed);
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


	App->render->Blit(scTexture, 116, 36, &rosita);

	

	
	
	




	
	return update_status::UPDATE_CONTINUE;
}



bool ModuleScene::CleanUp()
{
	App->player->Disable();
	App->enemies->Disable();
	App->blocks->Disable();

	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}

