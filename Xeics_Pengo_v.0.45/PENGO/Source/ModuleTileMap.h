#ifndef __MODULE_TILEMAP_H__
#define __MODULE_TILEMAP_H__

#include "Module.h"
#include "Globals.h"
#include "Application.h"

#include "SDL/include/SDL_Rect.h"

struct SDL_Texture;

class ModuleTileMap : public Module
{
public:

	ModuleTileMap(bool start_enabled = true);
	~ModuleTileMap();

	SDL_Rect tile;
	static int tilemap[17][15];

	bool init();
	bool start();
	update_status update();
	bool cleanUp();

	void loadMap(int);

	void drawBrick(int h, int w);
	void drawDiamond(int h, int w);


	char* getLevel(int level);
	int timer;

public:

	//SDL_Texture** textNumW;
	//SDL_Texture** textNumY;
	//SDL_Texture** textNumR;
	//SDL_Rect rectNum;

	//SDL_Texture* ladderGraphics;
	//SDL_Texture* bricksGraphics;
	//SDL_Rect SolidBrickSection;
	//Animation* brick_Animation[5];

};
#endif // __ModuleTileMap_H__