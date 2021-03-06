#ifndef __MODULE_TILEMAP_H__
#define __MODULE_TILEMAP_H__

#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "p2Point.h"

#include "SDL/include/SDL_Rect.h"

#define MAX_BLOCKS 208

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

	last
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
	void DestroyBlock2(int x, int y);
	void DestroyBlock3(int x, int y);
	void DestroyBlock4(int x, int y);

	void MoveBlock(int x, int y, Direction d);

	void MoveDiamond(int x, int y, Direction d);

	void PushLeftWall();

	void PushRightWall();

	void PushUpWall();

	void PushDownWall();

	void MouseState();

	bool isWalkable(int x, int y);

	bool thereIsABlock(int x, int y);

	bool thereIsAWall(int x, int y);

	bool thereIsADiamond(int x, int y);

	bool thereIsEnemy(int x, int y);

	//bool isWalkable_pixel(int x, int y);

	int blocks[MAX_BLOCKS];

	void checkDiamonds();

	int spaceToBlock(int x, int y, Direction d);

	int spaceToWall(int x, int y, Direction d);

	void spawnfromBlock1(int x, int y);
	void spawnfromBlock2(int x, int y);
	void spawnfromBlock3(int x, int y);
	void spawnfromBlock4(int x, int y);

	void nextBlockSpawn1(int x, int y);
	void nextBlockSpawn2(int x, int y);
	void nextBlockSpawn3(int x, int y);
	void nextBlockSpawn4(int x, int y);
	void nextBlockSpawn5(int x, int y);
	void nextBlockSpawn6(int x, int y);
	void nextBlockSpawn7(int x, int y);
	void nextBlockSpawn8(int x, int y);


	//// Called at the middle of the application loop
	//// Updates the scene's background animations
	update_status Update() override;

	//// Called at the end of the application loop.
	//// Performs the render call of all the parts of the scene's background
	//update_status PostUpdate() override;

	bool CleanUp() override;

	//void OnCollision(Collider* c1, Collider* c2) override;
	//char* getLevel(int level);
	//int timer;

public:
	Animation* currentAnimation = nullptr;

	Animation blockDestrAnim;
	Animation blockAnim;
	Animation blockColoredAnim;
	Animation diamondAnim;
	Animation twodiamondsAnim;
	Animation threediamondsAnim;

	Animation starsHorizontalRedAnim;
	Animation starsHorizontalBlueAnim;
	Animation starsHorizontalPurpleAnim;
	Animation starsHorizontalYellowAnim;
	Animation starsHorizontalOrangeAnim;
	Animation starsHorizontalPinkAnim;
	Animation starsHorizontalSoftYellowAnim;
	Animation starsHorizontalGreenAnim;

	Animation starsVerticalRedAnim;
	Animation starsVerticalBlueAnim;
	Animation starsVerticalPurpleAnim;
	Animation starsVerticalYellowAnim;
	Animation starsVerticalOrangeAnim;
	Animation starsVerticalPinkAnim;
	Animation starsVerticalSoftYellowAnim;
	Animation starsVerticalGreenAnim;

	Animation spawnFromBlock;

	Animation nextSpawnBlock;


	Animation sidesWallAnim;
	Animation topbotWallAnim;


	Direction dirBlock;

	Direction dirDiamond;

	iPoint positionBlock;

	iPoint positionDiamond;

	int spacestoblock;
	int spacestoblock_diamond;

	int finalpositionX;
	int finalpositionY;

	int finalpositionX_diamond;
	int finalpositionY_diamond;

	bool destroyedBlock = false;
	bool destroyedBlock2 = false;
	bool destroyedBlock3 = false;
	bool destroyedBlock4 = false;

	bool nextBlock1 = false;
	bool nextBlock2 = false;
	bool nextBlock3 = false;
	bool nextBlock4 = false;
	bool nextBlock5 = false;
	bool nextBlock6 = false;
	bool nextBlock7 = false;
	bool nextBlock8 = false;

	bool movedBlockfinish = false;
	bool destroyedAnimBlock = false;
	bool pushLeft = false;
	bool pushRight = false;
	bool pushUp = false;
	bool pushDown = false;

	bool twoDiamonds = false;
	bool threeDiamonds = false;
	bool threeDiamondsDone = false;
	bool threeDiamondsAnimation = false;
	bool bonusCounter = false;

	bool threeDiamondsFinish = false;

	bool oneTimeFx = false;
	bool oneTime2Fx = false;

	int whiteFont = -1;
	int blueFont = -1;
	int yellowFont = -1;

	uint scoreBonus = 10000;
	char scoreBonusText[10] = { "\0" };


	int timeDiamondStunned = 0;

	int mousePositionX;
	int mousePositionY;

	int iBlock;
	int jBlock;

	int posSpawnX, posSpawnY;
	int posSpawn2X, posSpawn2Y;
	int posSpawn3X, posSpawn3Y;
	int posSpawn4X, posSpawn4Y;

	int nextSpawnX, nextSpawnY;
	int nextSpawn2X, nextSpawn2Y;
	int nextSpawn3X, nextSpawn3Y;
	int nextSpawn4X, nextSpawn4Y;
	int nextSpawn5X, nextSpawn5Y;
	int nextSpawn6X, nextSpawn6Y;
	int nextSpawn7X, nextSpawn7Y;
	int nextSpawn8X, nextSpawn8Y;

	bool spawn1 = false;
	bool spawn2 = false;
	bool spawn3 = false;
	bool spawn4 = false;

	SDL_Texture* texture;
	SDL_Texture* scTexture;
	SDL_Texture* chTexture;

	SDL_Texture* noBlock;
	SDL_Texture* Block;
	SDL_Texture* Diamond;
	SDL_Texture* Corner;

	SDL_Rect source;
	SDL_Rect destination;


	uint stoppedBlockFx = 0;
	uint threeDiamondsFx = 0;
	uint countingbonusFx = 0;

	Collider* collider = nullptr;
	Collider* colliderDiamond = nullptr;

	int timeDiamond = 0;

	int blockX, blockY;
	int block2X, block2Y;
	int block3X, block3Y;
	int block4X, block4Y;

	int movedBlockX, movedBlockY;

	int movedDiamondX, movedDiamondY;

	int counter = 0;

	bool scenelvl1 = true;
	bool scenelvl2 = false;
	bool scenelvl3 = false;
	bool scenelvl4 = false;
	bool scenelvl5 = false;
	bool scenelvl6 = false;
	bool scenelvl7 = false;
	bool scenelvl8 = false;
	bool scenelvl9 = false;
	bool scenelvl10 = false;
	bool scenelvl11 = false;
	bool scenelvl12 = false;
	bool scenelvl13 = false;
	bool scenelvl14 = false;
	bool scenelvl15 = false;

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


	int lvl4[17][15] = {
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
		{ 2,0,1,0,0,0,0,0,0,0,0,0,1,0,2 },
		{ 2,0,1,0,1,3,1,1,1,1,1,0,1,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,0,0,0,2 },
		{ 2,0,1,0,1,0,1,0,1,0,1,1,1,0,2 },
		{ 2,0,0,0,1,0,0,0,0,0,1,0,1,0,2 },
		{ 2,0,1,1,1,0,1,1,1,0,1,0,1,0,2 },
		{ 2,0,0,0,0,0,1,0,0,0,1,0,1,0,2 },
		{ 2,1,1,3,1,1,1,0,1,1,1,0,1,0,2 },
		{ 2,0,0,0,0,0,0,0,1,0,1,0,0,0,2 },
		{ 2,0,1,1,1,1,1,1,1,0,1,1,1,1,2 },
		{ 2,0,1,0,0,0,0,0,1,0,0,0,0,0,2 },
		{ 2,0,1,0,1,1,1,1,3,1,1,0,1,0,2 },
		{ 2,0,0,0,0,0,0,0,0,0,0,0,1,0,2 },
		{ 2,0,1,1,1,0,1,0,1,0,1,0,1,0,2 },
		{ 2,0,1,0,0,0,1,0,1,0,1,0,1,0,2 },
		{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl5[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,0,0,1,0,0,0,0,0,1,0,2 },
	{ 2,0,1,0,1,1,1,1,1,1,1,0,3,0,2 },
	{ 2,0,0,0,1,0,0,0,0,0,1,0,1,0,2 },
	{ 2,0,1,1,1,0,1,1,1,0,1,0,1,0,2 },
	{ 2,0,0,0,0,0,1,0,0,0,1,0,0,0,2 },
	{ 2,1,1,1,1,1,1,0,1,1,1,0,1,0,2 },
	{ 2,0,0,0,0,0,0,0,1,0,1,0,1,0,2 },
	{ 2,0,1,1,1,1,1,1,1,0,3,0,1,1,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,0,0,2 },
	{ 2,0,1,1,1,1,1,0,1,0,1,1,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,1,1,1,1,0,1,1,1,1,2 },
	{ 2,0,0,0,1,0,0,0,1,0,0,0,0,0,2 },
	{ 2,1,1,0,1,0,3,0,1,1,1,1,1,0,2 },
	{ 2,0,0,0,0,0,1,0,0,0,0,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl6[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,0,0,2 },
	{ 2,0,1,0,1,1,1,0,1,0,1,1,1,0,2 },
	{ 2,0,0,0,1,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,1,1,1,1,1,1,0,1,0,2 },
	{ 2,0,0,0,1,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,0,1,0,3,0,1,1,1,1,3,0,2 },
	{ 2,0,1,0,1,0,1,0,0,0,0,0,1,0,2 },
	{ 2,0,1,1,1,0,1,1,1,1,1,0,1,0,2 },
	{ 2,0,0,0,0,0,1,0,0,0,1,0,1,0,2 },
	{ 2,1,1,1,1,1,1,1,1,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,1,1,0,1,0,1,0,1,0,2 },
	{ 2,0,0,0,1,0,1,0,1,0,1,0,0,0,2 },
	{ 2,1,1,0,3,0,1,0,1,0,1,1,1,0,2 },
	{ 2,0,0,0,1,0,0,0,0,0,0,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl7[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,0,0,1,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,1,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,1,3,0,3,0,1,1,1,1,2 },
	{ 2,0,0,0,1,0,0,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,3,1,1,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,1,1,0,1,0,1,1,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,0,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,1,1,0,1,0,2 },
	{ 2,0,1,0,0,0,1,0,0,0,1,0,1,0,2 },
	{ 2,1,1,0,1,0,1,1,1,0,1,0,1,0,2 },
	{ 2,0,0,0,1,0,0,0,0,0,0,0,1,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl8[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,1,0,0,0,0,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,1,1,0,1,0,1,0,2 },
	{ 2,0,0,0,0,0,1,0,0,0,1,0,1,0,2 },
	{ 2,1,1,1,1,1,3,0,3,1,1,0,1,0,2 },
	{ 2,0,0,0,0,0,0,0,1,0,1,0,0,0,2 },
	{ 2,0,1,1,1,1,1,1,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,0,0,0,0,0,0,1,0,2 },
	{ 2,0,1,0,1,0,1,1,1,1,3,1,1,1,2 },
	{ 2,0,1,0,0,0,1,0,1,0,0,0,0,0,2 },
	{ 2,0,1,0,1,1,1,0,1,0,1,1,1,0,2 },
	{ 2,0,0,0,0,0,1,0,0,0,1,0,0,0,2 },
	{ 2,1,1,1,1,0,1,0,1,1,1,0,1,1,2 },
	{ 2,0,0,0,0,0,1,0,0,0,1,0,1,0,2 },
	{ 2,1,1,0,1,1,1,1,1,0,1,0,1,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,1,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl9[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,1,0,0,0,0,0,0,0,1,0,2 },
	{ 2,0,1,0,1,0,1,1,3,1,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,0,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,1,1,3,0,1,1,1,0,2 },
	{ 2,0,1,0,1,0,1,0,0,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,1,1,0,1,0,2 },
	{ 2,0,1,0,0,0,1,0,1,0,0,0,1,0,2 },
	{ 2,0,1,0,1,1,1,0,1,0,1,0,3,0,2 },
	{ 2,0,1,0,1,0,1,0,0,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,1,0,1,1,1,1,1,1,2 },
	{ 2,0,0,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,1,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,0,0,1,0,1,0,0,0,1,0,0,0,2 },
	{ 2,1,1,0,1,0,1,1,1,1,1,1,1,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl10[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,1,0,0,0,0,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,1,1,1,0,1,0,1,1,2 },
	{ 2,0,0,0,1,0,1,0,0,0,1,0,0,0,2 },
	{ 2,1,1,0,1,0,3,1,1,1,1,1,1,0,2 },
	{ 2,0,0,0,1,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,3,0,3,0,1,0,1,1,1,0,2 },
	{ 2,0,0,0,1,0,1,0,0,0,0,0,1,0,2 },
	{ 2,0,1,0,1,0,1,1,1,1,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,1,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,0,0,0,0,1,0,1,0,1,0,1,0,2 },
	{ 2,1,1,1,1,1,1,0,1,0,1,0,1,0,2 },
	{ 2,0,0,0,0,0,1,0,0,0,1,0,0,0,2 },
	{ 2,0,1,1,1,0,1,0,1,0,1,1,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl11[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,0,0,1,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,1,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,1,1,0,1,0,1,1,1,1,2 },
	{ 2,0,0,0,1,0,0,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,3,1,1,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,1,1,0,1,0,1,1,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,3,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,0,0,1,0,2 },
	{ 2,0,1,0,3,0,1,0,1,1,1,0,1,0,2 },
	{ 2,0,1,0,0,0,1,0,0,0,1,0,1,0,2 },
	{ 2,1,1,0,1,0,1,1,1,0,1,0,1,0,2 },
	{ 2,0,0,0,1,0,0,0,0,0,0,0,1,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl12[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,0,0,1,0,0,0,0,0,1,0,2 },
	{ 2,0,1,0,1,1,1,0,1,1,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,1,1,1,1,0,1,1,1,0,2 },
	{ 2,0,1,0,0,0,0,0,0,0,1,0,1,0,2 },
	{ 2,0,1,0,1,1,1,1,1,1,3,0,1,0,2 },
	{ 2,0,1,0,0,0,1,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,0,1,0,1,0,0,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,0,0,0,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,1,1,0,2 },
	{ 2,0,0,0,1,0,1,0,0,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,1,0,3,1,1,0,1,1,2 },
	{ 2,0,1,0,1,0,1,0,0,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,3,1,1,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,0,0,1,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl13[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,1,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,1,0,1,0,3,1,1,1,1,1,1,0,2 },
	{ 2,0,1,0,0,0,1,0,0,0,0,0,0,0,2 },
	{ 2,0,1,0,1,1,1,0,1,1,1,1,1,1,2 },
	{ 2,0,1,0,1,0,0,0,1,0,0,0,0,0,2 },
	{ 2,0,1,0,1,1,1,1,1,0,1,1,1,0,2 },
	{ 2,0,0,0,0,0,1,0,0,0,1,0,0,0,2 },
	{ 2,1,1,1,1,0,1,0,1,1,1,0,1,1,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,0,0,1,0,0,0,2 },
	{ 2,0,3,0,1,0,1,1,1,0,1,1,1,1,2 },
	{ 2,0,0,0,1,0,0,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,1,3,0,1,0,1,1,1,0,2 },
	{ 2,0,1,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl14[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,0,0,1,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,1,1,0,3,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,1,1,1,0,1,0,1,1,1,1,2 },
	{ 2,0,0,0,1,0,0,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,1,1,1,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,1,0,0,0,1,0,2 },
	{ 2,0,1,1,3,1,1,0,1,0,1,1,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,0,0,1,0,2 },
	{ 2,0,1,0,3,0,1,0,1,1,1,0,1,0,2 },
	{ 2,0,1,0,0,0,1,0,0,0,1,0,1,0,2 },
	{ 2,1,1,0,1,0,1,1,1,0,1,0,1,0,2 },
	{ 2,0,0,0,1,0,0,0,0,0,0,0,1,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

	int lvl15[17][15] = {
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,0,0,2 },
	{ 2,0,1,0,1,0,1,0,3,0,1,0,1,0,2 },
	{ 2,0,1,0,0,0,0,0,0,0,1,0,1,0,2 },
	{ 2,0,1,0,1,1,1,1,1,0,1,0,1,1,2 },
	{ 2,0,1,0,1,0,1,0,1,0,0,0,0,0,2 },
	{ 2,0,1,0,1,0,1,0,1,1,1,1,1,0,2 },
	{ 2,0,1,0,1,0,1,0,0,0,1,0,1,0,2 },
	{ 2,0,1,0,3,0,1,0,1,1,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,0,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,0,0,1,0,0,0,2 },
	{ 2,0,1,0,3,0,1,0,1,1,1,1,1,1,2 },
	{ 2,0,0,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,0,0,0,0,0,0,0,0,2 },
	{ 4,2,2,2,2,2,2,2,2,2,2,2,2,2,4 }
	};

};
#endif // __ModuleTileMap_H__