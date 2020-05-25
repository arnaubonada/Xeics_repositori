#ifndef __MODULE_TILEMAP_H__
#define __MODULE_TILEMAP_H__

#include "Module.h"
#include "Globals.h"
#include "Application.h"

#include "SDL/include/SDL_Rect.h"

struct SDL_Texture;

enum TileType
{
	NONE = 0,
	BLOCK = 1,
	BOT_TOP = 2,
	DIAMOND = 3,
	CORNER=4,
	SIDES = 5,

	MAX
};


class ModuleTileMap : public Module
{
public:

	ModuleTileMap(bool start_enabled = true);
	~ModuleTileMap();

	SDL_Rect tile;
	
	int tilemap[17][15];

	void LoadMap(int arr[17][15]); //inicialitzem el mapa
	bool Start()override;
	update_status update();
	bool cleanUp();

	void DrawMap();

	
	void drawBrick(int h, int w);
	void drawDiamond(int h, int w);

	//// Called at the middle of the application loop
	//// Updates the scene's background animations
	//update_status Update() override;

	//// Called at the end of the application loop.
	//// Performs the render call of all the parts of the scene's background
	//update_status PostUpdate() override;



	char* getLevel(int level);
	int timer;

public:

	SDL_Texture* noBlock;
	SDL_Texture* Block;
	SDL_Texture* Diamond;
	SDL_Texture* Corner;
	SDL_Texture* Bot_Top;
	SDL_Texture* Sides;

	SDL_Rect source;
	SDL_Rect destination;

	int lvl1[17][15] = {
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
		{ 5,0,1,0,1,0,0,0,1,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,1,1,1,0,1,1,1,0,5 },
		{ 5,0,0,0,1,0,0,0,0,0,1,0,0,0,5 },
		{ 5,0,1,0,1,1,1,1,0,0,1,0,1,1,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,0,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,1,0,5 },
		{ 5,0,1,0,1,0,0,0,0,0,0,0,1,0,5 },
		{ 5,0,1,0,0,0,0,0,0,0,0,0,1,0,5 },
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

};
#endif // __ModuleTileMap_H__