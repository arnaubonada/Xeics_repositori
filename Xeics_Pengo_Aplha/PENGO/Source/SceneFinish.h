#ifndef __SCENE_FINISH_H__
#define __SCENE_FINISH_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneFinish : public Module
{
public:
	//Constructor
	SceneFinish(bool startEnabled);

	//Destructor
	~SceneFinish();

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


	bool losed = false;
	int whiteFont = -1;
	int yellowFont = -1;
};

#endif