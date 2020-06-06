#include "ModuleTileMap.h"

#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"

ModuleTileMap::ModuleTileMap(bool start_enabled) : Module(start_enabled)
{
	blockAnim.PushBack({ 708, 0, 16, 16 });
	blockAnim.speed = 0.1f;

	blockDestrAnim.PushBack({ 708, 48, 16, 16 });
	blockDestrAnim.PushBack({ 724, 48, 16, 16 });
	blockDestrAnim.PushBack({ 740, 48, 16, 16 });
	blockDestrAnim.PushBack({ 756, 48, 16, 16 });
	blockDestrAnim.PushBack({ 772, 48, 16, 16 });
	blockDestrAnim.PushBack({ 788, 48, 16, 16 });
	blockDestrAnim.PushBack({ 804, 48, 16, 16 });
	blockDestrAnim.PushBack({ 820, 48, 16, 16 });
	blockDestrAnim.PushBack({ 836, 48, 16, 16 });
	blockDestrAnim.loop = false;
	blockDestrAnim.speed = 0.2f;

	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 0, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.PushBack({ 0, 8, 16, 8 });
	oneAnim.speed = 0.1f;

	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 80, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.PushBack({ 90, 82, 8, 8 });
	miniEnemyEggAnim.speed = 0.1f;

	sidesWallAnim.PushBack({ 684, 0, 8, 256 });
	sidesWallAnim.PushBack({ 696, 0, 8, 256 });
	sidesWallAnim.PushBack({ 684, 0, 8, 256 });	
	sidesWallAnim.PushBack({ 696, 0, 8, 256 });
	sidesWallAnim.loop = false;
	sidesWallAnim.speed = 0.1f;

	topbotWallAnim.PushBack({ 456, 260, 224, 8 });
	topbotWallAnim.PushBack({ 456, 272, 224, 8 });
	topbotWallAnim.PushBack({ 456, 260, 224, 8 });
	topbotWallAnim.PushBack({ 456, 272, 224, 8 });
	topbotWallAnim.loop = false;
	topbotWallAnim.speed = 0.1f;

	source.x = source.y = 0;
	source.w = source.h = 16;
	destination.w = destination.h = 16;
	destination.x = destination.y = 0;
}

ModuleTileMap::~ModuleTileMap()
{
	
}

bool ModuleTileMap::Start()
{
	texture = App->textures->Load("Assets/Blocks.png");
	oneTexture = App->textures->Load("Assets/1p.png");
	scTexture = App->textures->Load("Assets/Score.png");

	noBlock = App->textures->Load("Assets/noBlock.png");
	Block = App->textures->Load("Assets/Block.png");
	Diamond = App->textures->Load("Assets/Diamond.png");

	LoadMap(lvl1);

	return true;
}

void ModuleTileMap::LoadMap(int arr[17][15])
{
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 15; j++) {
			tilemap[i][j] = arr[i][j];
		}
	}
}

void ModuleTileMap::DrawMap()
{
	int type = 0;

	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 15; j++) {
			type = tilemap[i][j];

			destination.x = j * 16;
			destination.y = 16+i * 16;
			//App->render->Blit(Block, destination.x, destination.y, &source);
			switch (type)
			{
			case TILE_NOBLOCK:
				App->render->Blit(noBlock, destination.x, destination.y, &source);
				break;
			
			case TILE_BLOCK:
				App->render->Blit(Block, destination.x, destination.y, &source);
				break;
			
			case TILE_WALL:
				break;
			
			case TILE_DIAMOND:
				App->render->Blit(Diamond, destination.x, destination.y, &source);
				break;
			
			case TILE_CORNER:
				
				break;		
			
			default:
				break;              //si treiem el break no compila
			}

		}
	}
	
}

bool ModuleTileMap::isWalkable(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x/16;
	posY = (y-16)/16;

	if (tilemap[posY][posX] == TILE_NOBLOCK)
	{
		valid = true;
	}
	
	return valid;
}

bool ModuleTileMap::thereIsABlock(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_BLOCK)
	{
		valid = true;
	}

	return valid;
}

bool ModuleTileMap::thereIsAWall(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_WALL)
	{
		valid = true;
	}

	return valid;
}

bool ModuleTileMap::thereIsADiamond(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_DIAMOND)
	{
		valid = true;
	}

	return valid;
}

bool ModuleTileMap::thereIsEnemy(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_ENEMY)
	{
		valid = true;
	}
	return valid;
}

int ModuleTileMap::spaceToBlock(int x, int y, Direction d) {
	int space = 0;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;


	if (d == LEFT) {
		while (tilemap[posY][posX - 1] == TILE_NOBLOCK) {
		space++;
		posX--;
		}
	}
	else if (d == RIGHT) {
		while (tilemap[posY][posX + 1] == TILE_NOBLOCK) {
			space++;
			posX++;
		}
	}
	else if (d == DOWN) {
		while (tilemap[posY + 1][posX] == TILE_NOBLOCK) {
			space++;
			posY++;
		}
	}
	else if (d == UP) {
		while (tilemap[posY - 1][posX] == TILE_NOBLOCK) {
			space++;
			posY--;
		}
	}

	return space;

}


void ModuleTileMap::DestroyBlock(int x, int y)
{	
	blockX = x / 16;
	blockY = (y - 16) / 16;

	destroyedBlock = true;
	currentAnimation = &blockDestrAnim;
	
	//App->render->Blit(noBlock, destination.x, destination.y, &source);
}

void ModuleTileMap::MoveBlock(int x, int y, Direction d)
{
	positionBlockx = x;
	positionBlocky = y;

	movedBlockX = x / 16;
	movedBlockY = (y - 16) / 16;

	dirBlock = d;

	spacestoblock = spaceToBlock(positionBlockx, positionBlocky, dirBlock);

	if (dirBlock == LEFT) {
		finalpositionX = x - (spacestoblock*16);
	}
	else if (dirBlock == RIGHT) {
		finalpositionX = x + (spacestoblock*16);
	}
	else if (dirBlock == UP) {
		finalpositionY = y - (spacestoblock*16);
	}
	else if (dirBlock == DOWN) {
		finalpositionY = y + (spacestoblock*16);
	}

	tilemap[movedBlockY][movedBlockX] = TILE_NOBLOCK;
}





void ModuleTileMap::MoveDiamond(int x, int y)
{
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	tilemap[posY][posX] = TILE_NOBLOCK;
	if (App->player->opcio == 'l') {
		while (tilemap[posY][posX-1] == TILE_NOBLOCK) {
			posX--;
		}
		tilemap[posY][posX] = TILE_DIAMOND;
	}
	else if (App->player->opcio == 'r') {
		while (tilemap[posY][posX+1] == TILE_NOBLOCK) {
			posX++;
		}
		tilemap[posY][posX] = TILE_DIAMOND;
	}
	else if (App->player->opcio == 'u') {
		while (tilemap[posY-1][posX] == TILE_NOBLOCK) {
			posY--;
		}
		tilemap[posY][posX] = TILE_DIAMOND;
	}
	else if (App->player->opcio == 'd') {
		while (tilemap[posY+1][posX] == TILE_NOBLOCK) {
			posY++;
		}
		tilemap[posY][posX] = TILE_DIAMOND;
	}

}

void ModuleTileMap::PushLeftWall()
{
	pushLeft = true;
}
void ModuleTileMap::PushRightWall()
{
	pushRight = true;
}
void ModuleTileMap::PushUpWall()
{
	pushUp = true;
}
void ModuleTileMap::PushDownWall()
{
	pushDown = true;
}

update_status ModuleTileMap::Update()
{
	/*if(counter % 10==0) {
		tilemap[counter/10][1] = 1;
	}
	counter++;*/

	//tilemap[1][1]=1;


	/*int posXplayer;
	int posYplayer;
	posXplayer = (App->player->position.x) / 16;
	posYplayer = ((App->player->position.y) - 16) / 16;

	tilemap[posYplayer][posXplayer] = TILE_PLAYER;*/

	if (destroyedBlock) {
		blockDestrAnim.Update();
		if (blockDestrAnim.HasFinished()) {
			destroyedBlock = false;
			destroyedAnimBlock = true;
			blockDestrAnim.Reset();
			tilemap[blockY][blockX] = TILE_NOBLOCK;
		}
	}

	if (pushLeft) {
		sidesWallAnim.Update();
		if (sidesWallAnim.HasFinished()) {
			pushLeft = false;
			sidesWallAnim.Reset();
		}
	}	
	if (pushRight) {
		sidesWallAnim.Update();
		if (sidesWallAnim.HasFinished()) {
			pushRight = false;
			sidesWallAnim.Reset();
		}
	}	
	if (pushUp) {
		topbotWallAnim.Update();
		if (topbotWallAnim.HasFinished()) {
			pushUp = false;
			topbotWallAnim.Reset();
		}
	}	
	if (pushDown) {
		topbotWallAnim.Update();
		if (topbotWallAnim.HasFinished()) {
			pushDown = false;
			topbotWallAnim.Reset();
		}
	}


	if (dirBlock != NOMOVE) 
	{
			
			if (dirBlock == LEFT) {
				if (positionBlockx % 16 == 0) {
					movedBlockX--;
				}
				positionBlockx-=4;
				if (positionBlockx == finalpositionX) {
					dirBlock = NOMOVE;
					tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				}
			}

			else if (dirBlock == RIGHT) {
				if (positionBlockx % 16 == 0) {
					movedBlockX++;
				}
				positionBlockx+=4;
				if (positionBlockx == finalpositionX) {
					dirBlock = NOMOVE;
					tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				}
			}

			else if (dirBlock == UP) {
				if (positionBlocky % 16 == 0) {
					movedBlockY--;
				}
				positionBlocky-=4;
				if (positionBlocky == finalpositionY) {
					dirBlock = NOMOVE;
					tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				}
			}

			else if (dirBlock == DOWN) {
				if (positionBlocky % 16 == 0) {
					movedBlockY++;
				}
				positionBlocky+=4;
				if (positionBlocky == finalpositionY) {
					dirBlock = NOMOVE;
					tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				}
			}
	}

	





	blockAnim.Update();
	oneAnim.Update();
	miniEnemyEggAnim.Update();


	return update_status::UPDATE_CONTINUE;
}


update_status ModuleTileMap::PostUpdate()
{
	if (destroyedBlock) {
		App->render->Blit(texture, blockX*16, (blockY*16)+16, &(blockDestrAnim.GetCurrentFrame()), 0.1f);	
	}
	if (pushLeft) {
		App->render->Blit(texture, 8, 24, &(sidesWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (pushRight) {
		App->render->Blit(texture, 224, 24, &(sidesWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (pushUp) {
		App->render->Blit(texture, 8, 24, &(topbotWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (pushDown) {
		App->render->Blit(texture, 8, 272, &(topbotWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (dirBlock != NOMOVE) {
		App->render->Blit(texture, positionBlockx, positionBlocky, &(blockAnim.GetCurrentFrame()), 0.2f);
	}

	App->render->Blit(oneTexture, 16, 0, &(oneAnim.GetCurrentFrame()), 0.1f);

	App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);





	return update_status::UPDATE_CONTINUE;
}