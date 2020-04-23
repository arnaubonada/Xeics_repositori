#include "ModuleBlocks.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include "ModuleScene.h"


#include "Block.h"


#include "SDL/include/SDL_scancode.h"



#define SPAWN_MARGIN 50




ModuleBlocks::ModuleBlocks(bool startEnabled) : Module(startEnabled)
{
	//for (uint i = 0; i < MAX_BLOCKS; ++i)
	//	blocks[i] = nullptr;

	//position.x = 70;
	//position.y = 70;

	blockAnim.PushBack({ 708, 0, 16, 16 });
	blockAnim.speed = 0.1f;
}

ModuleBlocks::~ModuleBlocks()
{

}

bool ModuleBlocks::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Blocks.png");
	currentAnimation = &blockAnim;
	//blockDestroyedFx = App->audio->LoadFx("Assets/explosion.wav");

	
	if (App->scene->rep) {

		for (int i = 32; i < 272; i += 16)
		{
			if (i == 64) {}
			else {
				collider = App->collisions->AddCollider({ 24, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 256) {}
			else {
				collider = App->collisions->AddCollider({ 56, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 80 || i == 208) {
				collider = App->collisions->AddCollider({ 72, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 32 || i == 64 || i == 96 || i == 192 || i == 224 || i == 256) {}
			else {
				collider = App->collisions->AddCollider({ 88, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 48 || i == 80 || i == 112 || i == 240) {
				collider = App->collisions->AddCollider({ 104, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 64 || i == 96 || i == 256) {}
			else {
				collider = App->collisions->AddCollider({ 120, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 80 || i == 112 || i == 240) {
				collider = App->collisions->AddCollider({ 136, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 32 || i == 96 || i == 192 || i == 224 || i == 256) {}
			else {
				collider = App->collisions->AddCollider({ 152, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 48 || i == 112 || i == 208) {
				collider = App->collisions->AddCollider({ 168, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			if (i == 32 || i == 64 || i == 160) {}
			else {
				collider = App->collisions->AddCollider({ 184, i, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);
			}
			
		}
	}
	
	
	
	//App->scene->pintarBlock(App->scene->getState(positionBlock.x, positionBlock.y));
	//destroyed = false;

	
	
	

	return ret;
}

update_status ModuleBlocks::PreUpdate()
{

	App->scene->rep = false;
	
	/*
	// Remove all enemies scheduled for deletion
	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr && blocks[i]->pendingToDelete)
		{
			delete blocks[i];
			blocks[i] = nullptr;
		}
	}*/

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleBlocks::Update()
{
	//HandleBlockSpawn();
	//App->scene->pintarBlock(App->scene->getState(positionBlock.x, positionBlock.y));

	/*for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr)
			blocks[i]->Update();
	}*/



	/* (int i = 0; i < 13; i++) {
		for (int j = 0; j < 15; j++) {
			if (App->scene->matriu[i][j] != BLOCKS) {
				//App->scene->borrar(App->scene->getState(i, j));
				App->scene->pintarBlock(App->scene->getState(i, j));

			}
		}
	}*/


	/*
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) {
		opcio = 'l';
	}
	else {

		if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			opcio = 'r';
		}
		else {
			if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				opcio = 'd';
			}

			else {
				if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
				{
					opcio = 'u';
				}
			}
		}
	}*/



	//HandleBlockDespawn();

	currentAnimation = &blockAnim;
	

	currentAnimation->Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleBlocks::PostUpdate()
{
	/*for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr)
			blocks[i]->Draw();
	}*/
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	
	for (int i = 32; i < 272; i+=16)
	{
		if(i==64){}
		else {
			App->render->Blit(texture, 24, i, &rect);
		}
		if (i == 256) {}
		else {
			App->render->Blit(texture, 56, i, &rect);
		}
		if (i == 80 || i == 208) {
			App->render->Blit(texture, 72, i, &rect);
		}
		if (i == 32 || i == 64 || i == 96 || i == 192 || i == 224 || i == 256) {}
		else {
			App->render->Blit(texture, 88, i, &rect);
		}
		if (i == 48 || i == 80 || i == 112 || i == 240) {
			App->render->Blit(texture, 104, i, &rect);
		}
		if (i == 64 || i == 96 || i == 256) {}
		else {
			App->render->Blit(texture, 120, i, &rect);
		}
		if (i == 80 || i == 112 || i == 240) {
			App->render->Blit(texture, 136, i, &rect);
		}
		if (i == 32 || i == 96 || i == 192 || i == 224 || i == 256) {}
		else {
			App->render->Blit(texture, 152, i, &rect);
		}
		if (i == 48 || i == 112 || i == 208) {
			App->render->Blit(texture, 168, i, &rect);
		}
		if (i == 32 || i == 64 || i == 160) {}
		else {
			App->render->Blit(texture, 184, i, &rect);
		}
		
	}
	
	
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleBlocks::CleanUp()
{
	/*LOG("Freeing all blocks");

	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr)
		{
			delete blocks[i];
			blocks[i] = nullptr;
		}
	}*/

	return true;
}

bool ModuleBlocks::AddBlock(BLOCK_TYPE type, int x, int y)
{
	bool ret = false;

	/*for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (spawnQueue[i].type == BLOCK_TYPE::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			ret = true;
			break;
		}
	}*/

	return ret;
}

void ModuleBlocks::HandleBlockSpawn()
{
	/*
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (spawnQueue[i].type != BLOCK_TYPE::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning block at %d", spawnQueue[i].x * SCREEN_SIZE);

				SpawnBlock(spawnQueue[i]);
				spawnQueue[i].type = BLOCK_TYPE::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}*/
}

void ModuleBlocks::HandleBlockDespawn()
{
	// Iterate existing enemies
	/*for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			if (blocks[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning block at %d", blocks[i]->position.x * SCREEN_SIZE);

				delete blocks[i];
				blocks[i] = nullptr;
			}
		}
	}*/
}

void ModuleBlocks::SpawnBlock(const BlockSpawnpoint& info)
{
	// Find an empty slot in the enemies array
	/*for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] == nullptr)
		{
			switch (info.type)
			{
			case BLOCK_TYPE::NORMAL:
				blocks[i] = new Block(info.x, info.y);
				break;

			}
			blocks[i]->texture = texture;
			blocks[i]->destroyedFx = blockDestroyedFx;
			break;
		}
	}*/
}

void ModuleBlocks::OnCollision(Collider* c1, Collider* c2)
{


	/*

	if (c1 == collider && opcio == 'l')
	{

		positionBlock.x -= 1;
		currentAnimation = &blockAnim;

	}


	if (c1 == collider && opcio == 'r')
	{

		positionBlock.x += 1;
		currentAnimation = &blockAnim;
	}


	if (c1 == collider && opcio == 'd')
	{

		positionBlock.y += 1;
		currentAnimation = &blockAnim;
	}


	if (c1 == collider && opcio == 'u')
	{
		positionBlock.y -= 1;
		currentAnimation = &blockAnim;
	}



	*/



}
