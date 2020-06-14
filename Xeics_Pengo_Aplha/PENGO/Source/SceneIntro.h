#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneIntro : public Module
{
public:
	//Constructor
	SceneIntro(bool startEnabled);

	//Destructor
	~SceneIntro();

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
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* logo = nullptr;

	int whiteFont = -1;
	int blueFont = -1;
	char scoreText[10] = { "\0" };

	//////prova
	//SDL_Texture* skyTexture = nullptr;
	//SDL_Texture* snowTexture = nullptr;
	//Animation skyAnim;





	int contador = 0;
};

#endif