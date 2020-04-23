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

#include "SDL/include/SDL_scancode.h"

ModuleScene::ModuleScene(bool startEnabled) :Module (startEnabled)
{
	//noBlocks = SDL_Rect{ 50,50,16,16 }; blocks = SDL_Rect{ 708,0,16,16 }; pengo = SDL_Rect{ 0,0,16,16 }; snobees = SDL_Rect{ 0,160,16,16 };

	pYellow =SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 };

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
	


	//Bottomside
	bottomWall = App->collisions->AddCollider({ 0, 272, 224, 8 }, Collider::Type::WALL);

	//leftside
	leftWall = App->collisions->AddCollider({ 0, 24, 8, 256 }, Collider::Type::WALL);

	//topside
	topWall = App->collisions->AddCollider({ 0, 24, 224, 8 }, Collider::Type::WALL);

	//rightside
	rightWall = App->collisions->AddCollider({ 216, 24, 8, 256 }, Collider::Type::WALL);




	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 24, 64);

	//blocks 
	//App->blocks->AddBlock(BLOCK_TYPE::NORMAL, 200, 200);

	App->player->Enable();
	App->enemies->Enable();
	App->blocks->Enable();

	return ret;
}

update_status ModuleScene::Update()
{
	//App->render->camera.x += 3;
	
	


	return update_status::UPDATE_CONTINUE;
}









// Update: draw background
update_status ModuleScene::PostUpdate()
{

	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 24, NULL);

	if (App->player->lifes == 3) {
		App->render->Blit(scTexture, 0, 8, &pRed);
		App->render->Blit(scTexture, 16, 8, &pRed);
		App->render->Blit(scTexture, 32, 8, &pRed);
	}
	if (App->player->lifes == 2) {
		App->render->Blit(scTexture, 0, 8, &pRed);
		App->render->Blit(scTexture, 16, 8, &pRed);
	}
	if (App->player->lifes == 1) {
		App->render->Blit(scTexture, 0, 8, &pRed);
	}
	
	if (App->player->lifes > 0 && App->player->destroyed)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 60);
		App->player->collider->pendingToDelete = true;
	}
	else if (App->player->lifes == 0 && App->player->destroyed)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneIntro, 60);
	}



	App->render->Blit(scTexture, 56, 280, &pYellow);

	

	
	
	




	
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
