#include "Application.h"

#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "SceneIntro.h"
#include "ModuleScene.h"
#include "SceneSnow.h"
#include "SceneWin.h"
#include "SceneLose.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleDebugInfo.h"
#include "ModuleFonts.h"
#include "ModuleRender.h"
#include "ModuleBlocks.h"
#include "ModuleTilemap.h"


Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen
	modules[0] =	window =		new ModuleWindow(true);
	modules[1] =	input =			new ModuleInput(true);
	modules[2] =	textures =		new ModuleTextures(true);
	modules[3] =	audio =			new ModuleAudio(true);

	modules[4] =	sceneIntro =	new SceneIntro(true);
	
	modules[5] =	scene =			new ModuleScene(false);		
	modules[6] =	sceneSnow =		new SceneSnow(false);
	modules[7] =	sceneWin =		new SceneWin(false);
	modules[8] =	sceneLose =		new SceneLose(false);
	modules[9] =	player =		new ModulePlayer(false);
	modules[10] =	particles =		new ModuleParticles(true);
	modules[11] =	enemies =		new ModuleEnemies(false);
	modules[12] =	blocks =		new ModuleBlocks(false);
	modules[13] =	collisions =	new ModuleCollisions(true);
	modules[14] =	fade =			new ModuleFadeToBlack(true);
	modules[15] =	fonts =			new ModuleFonts(true);
	modules[16] =	debugInfo =		new ModuleDebugInfo(true);
	modules[17] =	tilemap =		new ModuleTileMap(false);
	modules[18] =	render =		new ModuleRender(true);

}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		//Important: when deleting a pointer, set it to nullptr afterwards
		//It allows us for null check in other parts of the code
		delete modules[i];
		modules[i] = nullptr;
	}
}

bool Application::Init()
{
	bool ret = true;

	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->Init();

	//By now we will consider that all modules are always active
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : update_status::UPDATE_CONTINUE;

	return ret;
}
 
bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;
	
	return ret;
}
