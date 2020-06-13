#ifndef __SCENE_WIN_H__
#define __SCENE_WIN_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneWin : public Module
{
public:
	//Constructor
	SceneWin(bool startEnabled);

	//Destructor
	~SceneWin();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

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
	SDL_Texture* texturePengo = nullptr;
	SDL_Texture* texturePengoEstampadaEsquerra = nullptr;
	SDL_Texture* oneTexture;

	Animation estampadadreta;
	Animation estampadaesquerra;
	Animation oneAnim;
	Animation rightAnimWin;
	Animation leftAnimWin;
	SDL_Rect pYellow, pYellowFive, pRed;

	uint timeBonusFx = 0;

	uint scoreWin = 000;
	char scoreWinText[10] = { "\0" };
	bool bonusAddedOneTime = false;
	bool dreta;
	bool esquerra = false;

	int count = 0;
	int espera = 0;
	bool SpacePressed = false;
	bool counterWinFinish = false;

	int counterWinDelay = 0;

	char bonusText[5] = { "\0" };

	int whiteFont = -1;
	int blueFont = -1;
	int yellowFont = -1;
};

#endif
