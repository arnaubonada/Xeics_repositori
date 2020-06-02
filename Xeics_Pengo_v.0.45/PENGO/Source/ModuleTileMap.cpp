#include "ModuleTileMap.h"

#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollisions.h"

ModuleTileMap::ModuleTileMap(bool start_enabled) : Module(start_enabled)
{
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

void ModuleTileMap::updatePlayer(int x, int y)
{
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

}

void ModuleTileMap::DestroyBlock(int x, int y)
{
	
	blockX = x / 16;
	blockY = (y - 16) / 16;

	destroyedBlock = true;
	currentAnimation = &blockDestrAnim;
	
	
	
	
	
	//App->render->Blit(noBlock, destination.x, destination.y, &source);

}

void ModuleTileMap::MoveBlock(int x, int y)
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
		tilemap[posY][posX] = TILE_BLOCK;
	}
	else if (App->player->opcio == 'r') {
		while (tilemap[posY][posX+1] == TILE_NOBLOCK) {
			posX++;
		}
		tilemap[posY][posX] = TILE_BLOCK;
	}
	else if (App->player->opcio == 'u') {
		while (tilemap[posY-1][posX] == TILE_NOBLOCK) {
			posY--;
		}
		tilemap[posY][posX] = TILE_BLOCK;
	}
	else if (App->player->opcio == 'd') {
		while (tilemap[posY+1][posX] == TILE_NOBLOCK) {
			posY++;
		}
		tilemap[posY][posX] = TILE_BLOCK;
	}

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

update_status ModuleTileMap::Update()
{
	/*int posXplayer;
	int posYplayer;
	posXplayer = (App->player->position.x) / 16;
	posYplayer = ((App->player->position.y) - 16) / 16;

	tilemap[posYplayer][posXplayer] = TILE_PLAYER;*/
	if (destroyedBlock) {
		blockDestrAnim.Update();
		if (blockDestrAnim.HasFinished()) {
			destroyedBlock = false;
			blockDestrAnim.Reset();
			tilemap[blockY][blockX] = TILE_NOBLOCK;
		}
	}
	return update_status::UPDATE_CONTINUE;
}


update_status ModuleTileMap::PostUpdate()
{
	if (destroyedBlock) {
		App->render->Blit(texture, blockX*16, (blockY*16)+16, &(blockDestrAnim.GetCurrentFrame()), 0.1f);
		
		
	}
	
	return update_status::UPDATE_CONTINUE;
}