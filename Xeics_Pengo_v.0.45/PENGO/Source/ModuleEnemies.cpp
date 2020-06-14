#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "Enemy.h"
#include "Enemy_SnoBee.h"
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
#include "ModuleTileMap.h"

#include <stdio.h>

#include "SDL/include/SDL.h"
#include "SDL/include/SDL_scancode.h"

#include "time.h"

#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	name = "enemies";

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}




ModuleEnemies::~ModuleEnemies()
{

}

bool ModuleEnemies::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Characters.png");
	
	//position.x = 176;
	//position.y = 64;

	srand(time(NULL));

	return ret;
}

update_status ModuleEnemies::Update()
{
	HandleEnemiesSpawn();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Update();
	}

	HandleEnemiesDespawn();

	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}


	return update_status::UPDATE_CONTINUE;
}

bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
			App->collisions->RemoveCollider(App->enemies->colliderStunned);
		}
	}

	SDL_DestroyTexture(texture);

	App->audio->UnloadFx(App->enemies->snobeeSmashedFx);
	App->audio->UnloadFx(App->enemies->snobeeStunnedFx);

	//App->textures->Unload(texture);
	
	//App->collisions->RemoveCollider(collider);
	//--totalColliders;

	return true;
}


bool ModuleEnemies::AddEnemy(ENEMY_TYPE type, int x, int y)
{
	bool ret = false;

	App->scene->enemiesAlive++;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		//App->enemies[i].touchWall = false;

		if (spawnQueue[i].type == ENEMY_TYPE::NO_TYPE)
		{
			
			//snobee.enemiesAlive++;

			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::HandleEnemiesSpawn()
{
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type != ENEMY_TYPE::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

				SpawnEnemy(spawnQueue[i]);
				spawnQueue[i].type = ENEMY_TYPE::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
}

void ModuleEnemies::HandleEnemiesDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);

				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}
}



void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] == nullptr)
		{
			switch (info.type)
			{

			case ENEMY_TYPE::SNOBEE_NORMAL:
				enemies[i] = new Enemy_SnoBee(info.x, info.y, ENEMY_TYPE::SNOBEE_NORMAL);
				break;
			case ENEMY_TYPE::SNOBEE_DESTROYER:
				enemies[i] = new Enemy_SnoBee(info.x, info.y, ENEMY_TYPE::SNOBEE_DESTROYER);
				break;
			}
			enemies[i]->texture = texture;
			break;
		}
	}
}



void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c1,c2); //Notify the enemy of a collision

			if (c2->type == Collider::Type::PLAYER) {
					delete enemies[i];
					enemies[i] = nullptr;
				
			}
		}
		
		if (enemies[i] != nullptr && enemies[i]->GetColliderStun() == c1)
		{
			enemies[i]->OnCollision(c1,c2); //Notify the enemy of a collision

			if (c2->type == Collider::Type::BLOCK) {
					delete enemies[i];
					enemies[i] = nullptr;
					App->scene->enemiesAlive--;
					c1->pendingToDelete = true;
					App->player->score += 400;
					break;
			}
		}
		
		

	}
}


void ModuleEnemies::counterEnemiesStunned() {

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{

		//if (enemies[i]->enemyCanDie==true) {
			enemiesStunned[i] = true;
		//}

	}

}


