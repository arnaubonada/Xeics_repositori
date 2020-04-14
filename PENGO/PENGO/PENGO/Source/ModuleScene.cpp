#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"

ModuleScene::ModuleScene()
{

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
	App->audio->PlayMusic("Assets/stage1.ogg", 1.0f);

	//Bottomside
	App->collisions->AddCollider({ 0, 248, 224, 8 }, Collider::Type::WALL);

	//leftside
	App->collisions->AddCollider({ 0, 0, 8, 256 }, Collider::Type::WALL);

	//topside
	App->collisions->AddCollider({ 0, 0, 224, 8 }, Collider::Type::WALL);

	//rightside
	App->collisions->AddCollider({ 216, 0, 8, 256 }, Collider::Type::WALL);


	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 600, 80);
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 625, 80);
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 640, 80);
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 665, 80);

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
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}