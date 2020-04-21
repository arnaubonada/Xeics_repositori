#ifndef __MODULE_BLOCKS_H__
#define __MODULE_BLOCKS_H__

#include "Animation.h"
#include "Module.h"
#include "p2Point.h"

#define MAX_BLOCKS 150



enum class BLOCK_TYPE
{
	NO_TYPE,
	NORMAL,
};

struct BlockSpawnpoint
{
	BLOCK_TYPE type = BLOCK_TYPE::NO_TYPE;
	int x, y;
};

class Block;
struct SDL_Texture;

class ModuleBlocks : public Module
{
public:
	// Constructor
	ModuleBlocks(bool startEnabled);

	// Destructor
	~ModuleBlocks();

	// Called when the module is activated
	// Loads the necessary textures for the enemies
	bool Start() override;

	// Called at the beginning of the application loop
	// Removes all enemies pending to delete
	update_status PreUpdate() override;

	// Called at the middle of the application loop
	// Handles all enemies logic and spawning/despawning
	update_status Update() override;

	// Called at the end of the application loop
	// Iterates all the enemies and draws them
	update_status PostUpdate() override;

	// Called on application exit
	// Destroys all active enemies left in the array
	bool CleanUp() override;

	// Called when an enemi collider hits another collider
	// The enemy is destroyed and an explosion particle is fired
	void OnCollision(Collider* c1, Collider* c2) override;

	// Add an enemy into the queue to be spawned later
	bool AddBlock(BLOCK_TYPE type, int x, int y);

	// Iterates the queue and checks for camera position
	void HandleBlockSpawn();

	// Destroys any enemies that have moved outside the camera limits
	void HandleBlockDespawn();

	//positions
	iPoint position;

	Animation* currentAnimation = nullptr;

	Animation blockAnim;


	//collider
	Collider* collider = nullptr;


private:
	// Spawns a new enemy using the data from the queue
	void SpawnBlock(const BlockSpawnpoint& info);

	// A queue with all spawn points information
	BlockSpawnpoint spawnQueue[MAX_BLOCKS];

	// All spawned enemies in the scene
	Block* blocks[MAX_BLOCKS] = { nullptr };

	// The enemies sprite sheet
	SDL_Texture* texture = nullptr;

	// The audio fx for destroying an enemy
	int blockDestroyedFx = 0;

	char opcio = 'a';

};

#endif // __MODULE_BLOCKS_H____