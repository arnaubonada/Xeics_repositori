#include "Globals.h"
#include "Application.h"
#include "ModuleTileMap.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"

ModuleTileMap::ModuleTileMap(bool start_enabled) : Module(start_enabled)
{
	//noBlock = App->textures->Load("Assets/background.png");
	//Block = App->textures->Load("Assets/background.png");
	//Wall = App->textures->Load("Assets/background.png");
	//Diamond = App->textures->Load("Assets/background.png");



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
	noBlock = App->textures->Load("Assets/noBlock.png");
	Block = App->textures->Load("Assets/Block.png");
	//Bot_Top = App->textures->Load("Assets/Bot_Top.png");
	Diamond = App->textures->Load("Assets/Diamond.png");
	//Corner= App->textures->Load("Assets/Corner.png");
	//Sides= App->textures->Load("Assets/Sides.png");
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
			
			case TILE_BOT_TOP:
				break;
			
			case TILE_DIAMOND:
				App->render->Blit(Diamond, destination.x, destination.y, &source);
				break;
			
			case TILE_CORNER:
				
				break;
			
			case TILE_SIDES:
		
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

	if (tilemap[posY][posX] == 0)
	{
		valid = true;
	}
	
	return valid;
}


//update_status ModuleTileMap::Update()
//{
//	DrawMap();
//}
//
//update_status ModuleTileMap::PostUpdate()
//{
//
//
//}