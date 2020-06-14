#ifndef __MODULE_ENEMIES_H__
#define __MODULE_ENEMIES_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "Enemy.h"
#include "Enemy_SnoBee.h"

#define MAX_ENEMIES 10



enum class ENEMY_TYPE
{
	NO_TYPE,
	SNOBEE_NORMAL,
	SNOBEE_DESTROYER,

};

struct EnemySpawnpoint
{
	ENEMY_TYPE type = ENEMY_TYPE::NO_TYPE;
	int x, y;
};

class Enemy;
struct SDL_Texture;
struct Enemy_SnoBee;

class ModuleEnemies : public Module
{
public:
	// Constructor
	ModuleEnemies(bool startEnabled);

	// Destructor
	~ModuleEnemies();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	update_status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	update_status PostUpdate() override;

	bool CleanUp() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;

	// Add an enemy into the queue to be spawned later
	bool AddEnemy(ENEMY_TYPE type, int x, int y);

	// Iterates the queue and checks for camera position
	void HandleEnemiesSpawn();

	// Destroys any enemies that have moved outside the camera limits
	void HandleEnemiesDespawn();

	void counterEnemiesStunned();

	Enemy_SnoBee snobee;

	// The enemies sprite sheet
	SDL_Texture* texture = nullptr;

	Enemy* enemies[MAX_ENEMIES] = { nullptr };

	bool enemiesStunned[MAX_ENEMIES]{ false };
	bool enemiesSmashed[MAX_ENEMIES]{ false };
	int posEnemyX;
	int posEnemyY;

	Collider* colliderStunned = nullptr;
	
	uint snobeeFx = 0;
	uint snobeeSmashedFx = 0;
	uint snobeeStunnedFx = 0;

private:
	// Spawns a new enemy using the data from the queue
	void SpawnEnemy(const EnemySpawnpoint& info);

private:
	// A queue with all spawn points information
	EnemySpawnpoint spawnQueue[MAX_ENEMIES];

	// All spawned enemies in the scene
	

	//Collider* snobeeCollider = snobee.collider;

	// The audio fx for destroying an enemy
	int enemyDestroyedFx = 0;



};

#endif // __MODULE_ENEMIES_H__