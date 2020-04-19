#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleBlocks.h"

ModuleScene::ModuleScene(bool startEnabled) :Module (startEnabled)
{
	A = SDL_Rect{ 9,184,8,8 }; C = SDL_Rect{ 27,184,8,8 }; T = SDL_Rect{ 36,193,8,8 }; 
	oneblue= SDL_Rect{ 9,202,8,8 }; P = SDL_Rect{ 0,220,8,8 }; twoblue = SDL_Rect{ 18,202,8,8 };
	one= SDL_Rect{ 9,175,8,8 }; pYellow =SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 };
	zero = SDL_Rect{ 0,175,8,8 }; Hblue = SDL_Rect{ 72,211,8,8 }; Iblue = SDL_Rect{ 81,211,8,8 };
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
	scTexture = App->textures->Load("Assets/Score.png");
	segaTexture = App->textures->Load("Assets/SEGA1982.png");
	App->audio->PlayMusic("Assets/stage1.ogg", 1.0f);
	


	//MATRIU
	int matriu[195];

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 15; j++) {
			matriu[j] = 0;
		}
	}







	//Bottomside
	App->collisions->AddCollider({ 0, 272, 224, 8 }, Collider::Type::WALL);

	//leftside
	App->collisions->AddCollider({ 0, 24, 8, 256 }, Collider::Type::WALL);

	//topside
	App->collisions->AddCollider({ 0, 24, 224, 8 }, Collider::Type::WALL);

	//rightside
	App->collisions->AddCollider({ 216, 24, 8, 256 }, Collider::Type::WALL);


	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 50, 50);

	//blocks 
	App->blocks->AddBlock(BLOCK_TYPE::NORMAL, 70, 50);

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

	App->render->Blit(segaTexture, 136, 280, NULL);

	App->render->Blit(scTexture, 8, 280, &A);
	App->render->Blit(scTexture, 16, 280, &C);
	App->render->Blit(scTexture, 24, 280, &T);
	App->render->Blit(scTexture, 40, 280, &one);

	App->render->Blit(scTexture, 56, 280, &pYellow);

	App->render->Blit(scTexture, 8, 0, &oneblue);
	App->render->Blit(scTexture, 16, 0, &P);
	App->render->Blit(scTexture, 152, 0, &twoblue);
	App->render->Blit(scTexture, 160, 0, &P);

	App->render->Blit(scTexture, 0, 8, &pRed);
	App->render->Blit(scTexture, 16, 8, &pRed);
	App->render->Blit(scTexture, 32, 8, &pRed);

	App->render->Blit(scTexture, 64, 0, &zero);
	App->render->Blit(scTexture, 136, 0, &zero);
	App->render->Blit(scTexture, 208, 0, &zero);
	
	App->render->Blit(scTexture, 80, 0, &Hblue); 
	App->render->Blit(scTexture, 88, 0, &Iblue);
	



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