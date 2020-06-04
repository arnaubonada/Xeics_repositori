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

int ModuleTileMap::spaceToBlock(int x, int y) {
	int space = 0;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (App->enemies->opcio == 1) {
		while (tilemap[posY][posX - 1] == TILE_NOBLOCK) {
		space++;
		posX--;
		}
	}
	else if (App->enemies->opcio == 2) {
		while (tilemap[posY][posX + 1] == TILE_NOBLOCK) {
			space++;
			posX++;
		}
	}
	else if (App->enemies->opcio == 3) {
		while (tilemap[posY + 1][posX] == TILE_NOBLOCK) {
			space++;
			posY++;
		}
	}
	else if (App->enemies->opcio == 4) {
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

void ModuleTileMap::MoveBlock(int x, int y)
{

	movedBlockX = x / 16;
	movedBlockY = (y - 16) / 16;

	//movedBlock = true;

	tilemap[movedBlockY][movedBlockX] = TILE_NOBLOCK;
	if (App->player->opcio == 'l') {
		//while (tilemap[movedBlockY][movedBlockX - 1] == TILE_NOBLOCK) {
			movedBlockX--;
		//}
		tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
	}
	else if (App->player->opcio == 'r') {
		while (tilemap[movedBlockY][movedBlockX + 1] == TILE_NOBLOCK) {
			movedBlockX++;
			

		}
		tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
	}
	else if (App->player->opcio == 'u') {
		while (tilemap[movedBlockY - 1][movedBlockX] == TILE_NOBLOCK) {
			movedBlockY--;
		}
		tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
	}
	else if (App->player->opcio == 'd') {
		while (tilemap[movedBlockY + 1][movedBlockX] == TILE_NOBLOCK) {
			movedBlockY++;
		}
		tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
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
			destroyedAnimBlock = true;
			blockDestrAnim.Reset();
			tilemap[blockY][blockX] = TILE_NOBLOCK;
		}
	}

	if(counter % 10==0) {
		tilemap[counter/10][1] = 1;
	}
	counter++;

	//tilemap[1][1]=1;




	oneAnim.Update();
	miniEnemyEggAnim.Update();


	return update_status::UPDATE_CONTINUE;
}


update_status ModuleTileMap::PostUpdate()
{
	if (destroyedBlock) {
		App->render->Blit(texture, blockX*16, (blockY*16)+16, &(blockDestrAnim.GetCurrentFrame()), 0.1f);	
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