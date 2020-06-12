#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(bool startEnabled);

	// Destructor
	~ModulePlayer();

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

public:
	// Position of the player in the map
	iPoint position;

	// The speed in which we move the player (pixels per frame)
	int move = 1;

	//Where the player goes
	char opcio = 'a';


	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;
	
	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of animations
	//Animation idleAnim;
	Animation upAnim;
	Animation downAnim;
	Animation leftAnim;
	Animation rightAnim;

	Animation upAnim2;
	Animation downAnim2;
	Animation leftAnim2;
	Animation rightAnim2;

	Animation deadAnim;

	Animation upPushAnim;
	Animation leftPushAnim;
	Animation downPushAnim;
	Animation rightPushAnim;
	
	// The player's collider
	bool Collide = true;
	Collider* collider = nullptr;

	Collider* colliderStunned = nullptr;

	// A flag to detect when the player has been destroyed
	bool destroyed = false;
	bool snobeeStunned = false;

	bool scoreOneHundred = false;
	// A countdown to when the player gets destroyed. After a while, the game exits
	//uint destroyedCountdown = 120;

	int timerLevel = 0;
	int minutes = 0;



	uint score = 000;
	int whiteFont=-1;
	char scoreText[10] = { "\0" };
	char secondsText[10] = { "\0" };
	char minutesText[10] = { "\0" };

	// Sound effects indices
	uint laserFx = 0;
	uint explosionFx = 0;

	int rep = 0;

	

	int lifes = 4;

};

#endif //!__MODULE_PLAYER_H__