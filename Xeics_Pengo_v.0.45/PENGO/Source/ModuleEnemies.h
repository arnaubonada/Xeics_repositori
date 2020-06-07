#ifndef __MODULE_ENEMIES_H__
#define __MODULE_ENEMIES_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModuleTileMap.h"

struct SDL_Texture;
struct Collider;

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
	//void OnCollision2(Collider* c1, Collider* c2) override;

	void MoveEnemy(int x, int y, Direction d);

public:
	// Position of the player in the map
	iPoint position;

	// The speed in which we move the player (pixels per frame)
	int move = 1;

	//Where the player goes
	int opcio = 1;
	int rep = 0;
	int longer;
	

	int positionEnemyX;
	int positionEnemyY;
	int movedEnemyX;
	int movedEnemyY;

	int EnemyToBlock;

	int finalEnemyPositionX;
	int finalEnemyPositionY;

	Direction dirEnemy;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnim = nullptr;

	// A set of animations
	//Animation idleAnim;
	Animation snoUpAnim;
	Animation snoDownAnim;
	Animation snoLeftAnim;
	Animation snoRightAnim;

	Animation snoUpAnim2;
	Animation snoDownAnim2;
	Animation snoLeftAnim2;
	Animation snoRightAnim2;



	Animation deadAnim;

	// The player's collider
	Collider* collider = nullptr;

	// A flag to detect when the player has been destroyed
	bool destroyedEnemy = false;

	// A countdown to when the player gets destroyed. After a while, the game exits
	//uint destroyedCountdown = 120;


	// Sound effects indices
	uint snobeeFx = 0;

	int j = 0;

};

#endif // __MODULE_ENEMIES_H__