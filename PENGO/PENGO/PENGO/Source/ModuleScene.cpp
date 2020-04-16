#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"

ModuleScene::ModuleScene()
{
	//two = SDL_Rect{ 18,175,8,8 };
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
	//App->render->Blit(scTexture, 216, 280, &two);

	return update_status::UPDATE_CONTINUE;
}