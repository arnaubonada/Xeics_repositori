#ifndef __MODULE_TILEMAP_H__
#define __MODULE_TILEMAP_H__

#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "p2Point.h"

#include "SDL/include/SDL_Rect.h"

struct SDL_Texture;

enum TileType
{
	TILE_NOBLOCK = 0,
	TILE_BLOCK = 1,
	TILE_WALL = 2,
	TILE_DIAMOND = 3,
	TILE_CORNER = 4,
	TILE_PLAYER = 5,
	TILE_ENEMY = 6,

	MAX
};

enum Direction
{
	NOMOVE = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
	UP = 4,
};


class ModuleTileMap : public Module
{
public:

	ModuleTileMap(bool start_enabled = true);
	~ModuleTileMap();

	SDL_Rect tile;

	int tilemap[17][15];

	void LoadMap(int arr[17][15]); //inicialitzem el mapa

	bool Start() override;
	
	update_status PostUpdate() override;

	void DrawMap();

	void DestroyBlock(int x, int y);

	void MoveBlock(int x, int y, Direction d);

	/*void MoveBlockLeft(int x, int y);

	void MoveBlockRight(int x, int y);

	void MoveBlockUp(int x, int y);

	void MoveBlockDown(int x, int y);*/

	void MoveDiamond(int x, int y);

	void PushLeftWall();

	void PushRightWall();

	void PushUpWall();

	void PushDownWall();

	bool isWalkable(int x, int y);

	bool thereIsABlock(int x, int y);

	bool thereIsAWall(int x, int y);

	bool thereIsADiamond(int x, int y);

	bool thereIsEnemy(int x, int y);

	int spaceToBlock(int x, int y, Direction d);


	//// Called at the middle of the application loop
	//// Updates the scene's background animations
	update_status Update() override;

	//// Called at the end of the application loop.
	//// Performs the render call of all the parts of the scene's background
	//update_status PostUpdate() override;



	//char* getLevel(int level);
	//int timer;

public:
	Animation* currentAnimation = nullptr;

	Animation blockDestrAnim;
	Animation blockAnim;
	Animation sidesWallAnim;
	Animation topbotWallAnim;
	Animation oneAnim;
	Animation miniEnemyEggAnim;

	Direction dirBlock;

	//iPoint positionBlock;
	int positionBlockx=32;
	int positionBlocky=32;

	int spacestoblock;

	int finalpositionX;
	int finalpositionY;

	bool destroyedBlock = false;

	bool movedBlockfinish = false;
	bool destroyedAnimBlock = false;
	bool pushLeft = false;
	bool pushRight = false;
	bool pushUp = false;
	bool pushDown = false;


	SDL_Texture* texture;
	SDL_Texture* oneTexture;
	SDL_Texture* scTexture;

	SDL_Texture* noBlock;
	SDL_Texture* Block;
	SDL_Texture* Diamond;
	SDL_Texture* Corner;

	SDL_Rect source;
	SDL_Rect destination;


	int blockX, blockY;

	int movedBlockX, movedBlockY;

	int counter = 0;

	int BlockMap[17][15] = {
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2 },
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl1[17][15] = {
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
		{ 2,0,1,0,1,0,0,0,1,0,0,0,0,0,2 },
		{ 2,0,1,0,1,0,1,1,1,0,3,1,1,0,2 },
		{ 2,0,0,0,1,0,0,0,0,0,1,0,0,0,2 },
		{ 2,0,1,0,1,1,1,1,1,1,1,0,1,1,2 },
		{ 2,0,1,0,1,0,0,0,0,0,0,0,1,0,2 },
		{ 2,0,3,0,1,0,1,1,1,1,3,1,1,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,0,0,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
		{ 2,0,1,0,1,0,0,0,1,0,0,0,1,0,2 },
		{ 2,0,1,0,1,1,1,0,1,0,1,1,1,0,2 },
		{ 2,0,1,0,1,0,0,0,1,0,0,0,1,0,2 },
		{ 2,0,1,0,1,0,1,1,1,1,1,0,1,0,2 },
		{ 2,0,1,0,0,0,0,0,0,0,0,0,1,0,2 },
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	}; //110 0

	int lvl2[17][15] = {
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
		{ 2,0,1,0,0,0,0,0,0,0,0,0,1,0,2 },
		{ 2,0,1,0,1,1,1,1,1,1,3,0,1,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,0,0,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,1,3,0,2 },
		{ 2,0,0,0,1,0,0,0,0,0,1,0,1,0,2 },
		{ 2,0,1,1,1,0,1,1,1,0,1,0,1,0,2 },
		{ 2,0,0,0,0,0,1,0,0,0,1,0,1,0,2 },
		{ 2,1,1,1,1,1,1,0,1,1,1,0,1,0,2 },
		{ 2,0,0,0,0,0,0,0,1,0,1,0,0,0,2 },
		{ 2,0,1,1,1,1,1,1,1,0,1,1,1,1,2 },
		{ 2,0,1,0,0,0,0,0,1,0,0,0,0,0,2 },
		{ 2,0,1,0,1,1,1,1,3,1,1,0,1,0,2 },
		{ 2,0,0,0,0,0,0,0,0,0,0,0,1,0,2 },
		{ 2,0,1,1,1,0,1,0,1,0,1,0,1,0,2 },
		{ 2,0,1,0,0,0,1,0,1,0,1,0,1,0,2 },
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl3[17][15] = {
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
		{ 2,0,1,0,0,0,1,0,0,0,0,0,1,0,2 },
		{ 2,0,1,0,1,1,1,1,1,1,1,0,3,0,2 },
		{ 2,0,0,0,1,0,0,0,0,0,1,0,1,0,2 },
		{ 2,0,1,1,1,0,1,1,1,0,1,0,1,0,2 },
		{ 2,0,0,0,0,0,1,0,0,0,1,0,0,0,2 },
		{ 2,1,1,1,1,1,1,0,1,1,1,0,1,0,2 },
		{ 2,0,0,0,0,0,0,0,1,0,1,0,1,0,2 },
		{ 2,0,1,1,1,1,1,1,1,1,3,0,1,1,2 },
		{ 2,0,1,0,0,0,0,0,1,0,0,0,0,0,2 },
		{ 2,0,1,1,1,1,1,0,1,0,1,1,1,0,2 },
		{ 2,0,1,0,0,0,0,0,1,0,1,0,0,0,2 },
		{ 2,0,1,0,1,1,1,1,1,0,1,1,1,1,2 },
		{ 2,0,0,0,1,0,0,0,1,0,0,0,0,0,2 },
		{ 2,1,1,0,1,0,3,0,1,1,1,1,1,0,2 },
		{ 2,0,0,0,0,0,1,0,0,0,0,0,0,0,2 },
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};


};
#endif // __ModuleTileMap_H__