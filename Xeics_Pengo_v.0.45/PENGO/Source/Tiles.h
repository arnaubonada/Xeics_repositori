#ifndef __TILES_H__
#define __TILES_H__


#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

#include "Globals.h"

const int LEVEL_WIDTH = 1280;     //Mirar si son les mides correctes
const int LEVEL_HEIGHT = 960;	  //Mirar si son les mides correctes

const int TILE_WIDTH = 8;
const int TILE_HEIGHT = 8;
const int TOTAL_TILES = 195;
const int TOTAL_TILE_SPRITES = 14;

const int TILE_NOBLOCK = 0;
const int TILE_BLOCK = 1;
const int TILE_PENGO = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;
const int TILE_DIAMOND = 12;
const int TILE_ENEMY = 13;

//The tile
class Tile
{
public:
	//Initializes position and type
	Tile(int x, int y, int tileType);

	//Shows the tile
	//void render(SDL_Rect& camera);

	//Get the tile type
	int getType();

	//Get the collision box
	SDL_Rect getBox();

private:
	//The attributes of the tile
	SDL_Rect mBox;

	//The tile type
	int mType;
};


//The dot that will move around on the screen
class Dot
{
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
	Dot();

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);


	//Moves the dot and check collision against tiles
	void move(Tile* tiles[]);

	//Centers the camera over the dot
	void setCamera(SDL_Rect& camera);

	//Shows the dot on the screen
	void render(SDL_Rect& camera);

private:
	//Collision box of the dot
	SDL_Rect mBox;

	//The velocity of the dot
	int mVelX, mVelY;
};


//Loads media
bool loadMedia(Tile* tiles[]);

//Frees media and shuts down SDL
void close(Tile* tiles[]);

//Box collision detector
bool checkCollision(SDL_Rect a, SDL_Rect b);

//Checks collision box against set of tiles
bool touchesWall(SDL_Rect box, Tile* tiles[]);

//Sets tiles from tile map
bool setTiles(Tile* tiles[]);












#endif // __TILES_H__