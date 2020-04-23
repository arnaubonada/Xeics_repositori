#ifndef __MODULE_SCENE_H__
#define __MODULE_SCENE_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

//#define NOBLOCKS 0
//#define BLOCKS 1
//#define PENGO 2
//#define SNOBEES 3
//#define LIMITS 4


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
	/*int _state = 0;


	int getState(int x, int y);
	int borrar(int state);
	int pintarBlock(int state);
	int pintarPengo(int state);*/


	/*iPoint map;
	int matriu[500][500];*/

	//iPoint pMat;

	/*int pmatriux;
	int pmatriuy;*/

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	

	bool CleanUp();

public:

	Collider* rightWall = nullptr;
	Collider* leftWall = nullptr;
	Collider* topWall = nullptr;
	Collider* bottomWall = nullptr;

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* scTexture = nullptr;
	SDL_Texture* chTexture = nullptr;
	SDL_Texture* blTexture = nullptr;

	//SDL_Rect noBlocks, blocks, pengo, snobees;
	SDL_Rect pYellow, pRed;

	int lifecount;
	// The sprite rectangle for the ground
	//SDL_Texture* starsTexture = nullptr;
};

#endif