#include "ModuleBlocks.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

#include "Block_Normal.h"
#include "Block.h"



#define SPAWN_MARGIN 50

ModuleBlocks::ModuleBlocks(bool startEnabled) : Module(startEnabled)
{
	for (uint i = 0; i < MAX_BLOCKS; ++i)
		blocks[i] = nullptr;
}

ModuleBlocks::~ModuleBlocks()
{

}

bool ModuleBlocks::Start()
{
	texture = App->textures->Load("Assets/Blocks.png");
	blockDestroyedFx = App->audio->LoadFx("Assets/explosion.wav");

	return true;
}

update_status ModuleBlocks::PreUpdate()
{
	// Remove all enemies scheduled for deletion
	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr && blocks[i]->pendingToDelete)
		{
			delete blocks[i];
			blocks[i] = nullptr;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleBlocks::Update()
{
	HandleBlockSpawn();

	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr)
			blocks[i]->Update();
	}

	HandleBlockDespawn();

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleBlocks::PostUpdate()
{
	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr)
			blocks[i]->Draw();
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleBlocks::CleanUp()
{
	LOG("Freeing all blocks");

	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr)
		{
			delete blocks[i];
			blocks[i] = nullptr;
		}
	}

	return true;
}

bool ModuleBlocks::AddBlock(BLOCK_TYPE type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (spawnQueue[i].type == BLOCK_TYPE::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleBlocks::HandleBlockSpawn()
{
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
	}
}

void ModuleBlocks::HandleBlockDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_BLOCKS; ++i)
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
	}
}

void ModuleBlocks::SpawnBlock(const BlockSpawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] == nullptr)
		{
			switch (info.type)
			{
			case BLOCK_TYPE::NORMAL:
				blocks[i] = new Block_Normal(info.x, info.y);
				break;

			}
			blocks[i]->texture = texture;
			blocks[i]->destroyedFx = blockDestroyedFx;
			break;
		}
	}
}

void ModuleBlocks::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr && blocks[i]->GetCollider() == c1)
		{
			blocks[i]->OnCollision(c2); //Notify the enemy of a collision

			delete blocks[i];
			blocks[i] = nullptr;
			break;
		}
	}
}

void ModuleBlocks::OnCollision2(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_BLOCKS; ++i)
	{
		if (blocks[i] != nullptr && blocks[i]->GetCollider() == c1)
		{
			blocks[i]->OnCollision(c2); //Notify the enemy of a collision

			delete blocks[i];
			blocks[i] = nullptr;
			break;
		}
	}
}