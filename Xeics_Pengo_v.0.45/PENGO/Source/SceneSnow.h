#ifndef __SCENE_SNOW_H__
#define __SCENE_SNOW_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneSnow : public Module
{
public:
	//Constructor
	SceneSnow(bool startEnabled);

	//Destructor
	~SceneSnow();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;


	bool CleanUp() override;

public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* skyTexture = nullptr;
	SDL_Texture* snowTexture = nullptr;
	Animation skyAnim;

	Animation redPengo;
	Animation bluePengo;
	Animation yellowPengo;
	Animation pinkPengo;
	Animation greenSnoBee;
	Animation pinkSnoBee;

	//Animation blueAnim;
	//Animation purpleBlueAnim;
	//Animation pinkAnim;
	//Animation yellowAnim;
	//Animation orangeYelowAnim;
	//Animation orangeAnim;
	//Animation blackOrangeAnim;
	//Animation greenOrangeAnim;
	//Animation blackGreenAnim;
	//Animation greenAnim;
	//Animation greenYellowAnim;
	//Animation yellowGreenAnim;
	//Animation yellowAnim;
	//Animation yellowPurpleGreenAnim;
	//Animation yellowBlueGreenAnim;
	//Animation softBlueAnim;

	int contador = 0;
};

#endif