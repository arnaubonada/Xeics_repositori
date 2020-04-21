#ifndef __MODULE_SCENE_H__
#define __MODULE_SCENE_H__

#include "Module.h"
#include "Animation.h"
#define NOBLOCKS 0
#define BLOCKS 1
#define PENGO 2
#define SNOBEES 3
#define LIMITS 4


struct SDL_Texture;

class ModuleScene : public Module
{
public:
	//Constructor
	ModuleScene(bool startEnabled);

	//Destructor
	~ModuleScene();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;
	int state = 0;

	int borrar(int state);
	int pintar(int state);



	//iPoint map;
	int matriu[300][300] = {};

	iPoint pMat;

	int pmatriux;
	int pmatriuy;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	

	bool CleanUp();

public:

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* scTexture = nullptr;
	SDL_Texture* chTexture = nullptr;
	SDL_Texture* segaTexture = nullptr;
	SDL_Texture* blTexture = nullptr;

	SDL_Rect noBlocks, blocks, pengo, snobees;
	SDL_Rect A, C, T, P, one, oneblue,twoblue, pYellow, pRed, zero, Hblue, Iblue;


	// The sprite rectangle for the ground
	SDL_Texture* starsTexture = nullptr;
};

#endif