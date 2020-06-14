#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "ModuleEnemies.h"

#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleBlocks.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTileMap.h"
#include "SceneWin.h"
#include "ModuleFonts.h"
#include "Enemy.h"
#include "Enemy_SnoBee.h"
#include "ModuleParticles.h"
#include "SceneLose.h"
#include "SceneFinish.h"

#include"SceneIntro.h" 

#include "SDL/include/SDL_scancode.h"

ModuleScene::ModuleScene(bool startEnabled) :Module(startEnabled)
{
	name = "level 1";


	pYellow = SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 }; pYellowFive = SDL_Rect{ 72,150,16,16 };


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

	


}

ModuleScene::~ModuleScene()
{

}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/background.png");
	chTexture = App->textures->Load("Assets/Characters.png");
	blTexture = App->textures->Load("Assets/Blocks.png");
	scTexture = App->textures->Load("Assets/Score.png");
	oneTexture = App->textures->Load("Assets/1p.png");;

	App->audio->PlayMusic("Assets/Audio/popcorn.ogg", 1.0f);

	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);

	blueFont = App->fonts->Load("Assets/blueFont.png", lookupTable, 3);

	if (lvlCont == i && App->tilemap->scenelvl1 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(96, 208);
			App->tilemap->DestroyBlock2(160, 144);
			App->tilemap->DestroyBlock3(192, 208);
			App->tilemap->spawnfromBlock1(96, 208);
			App->tilemap->spawnfromBlock2(160, 144);
			App->tilemap->spawnfromBlock3(192, 208);
		
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 96, 208);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 144);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 208);
			App->tilemap->nextBlockSpawn1(128, 80);
			App->tilemap->nextBlockSpawn2(192, 144);
			App->tilemap->nextBlockSpawn3(128, 48);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1]==TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {

					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl2 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(96, 80);
			App->tilemap->DestroyBlock2(128, 176);
			App->tilemap->DestroyBlock3(160, 240);
			App->tilemap->spawnfromBlock1(96, 80);
			App->tilemap->spawnfromBlock2(128, 176);
			App->tilemap->spawnfromBlock3(160, 240);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 96, 80);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 128, 176);
		
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 240);
			App->tilemap->nextBlockSpawn1(32, 48);
			App->tilemap->nextBlockSpawn2(32, 176);
			App->tilemap->nextBlockSpawn3(160, 176);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}					
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl3 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(128, 48);
			App->tilemap->DestroyBlock2(192, 112);
			App->tilemap->DestroyBlock3(192, 208);
			App->tilemap->spawnfromBlock1(128, 48);
			App->tilemap->spawnfromBlock2(192, 112);
			App->tilemap->spawnfromBlock3(192, 208);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 128, 48);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 112);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 208);
			App->tilemap->nextBlockSpawn1(96, 48);
			App->tilemap->nextBlockSpawn2(192, 80);
			App->tilemap->nextBlockSpawn3(32, 112);
			App->tilemap->nextBlockSpawn4(64, 112);
			App->tilemap->nextBlockSpawn5(64, 144);


		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}	
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl4 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(192, 144);
			App->tilemap->DestroyBlock2(128, 80);
			App->tilemap->DestroyBlock3(32, 112);
			App->tilemap->spawnfromBlock1(192, 144);
			App->tilemap->spawnfromBlock2(128, 80);
			App->tilemap->spawnfromBlock3(32, 112);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 144);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 80);
			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 112);
			App->tilemap->nextBlockSpawn1(64, 80);
			App->tilemap->nextBlockSpawn2(160, 48);
			App->tilemap->nextBlockSpawn3(160, 112);
			App->tilemap->nextBlockSpawn4(160, 176);
			App->tilemap->nextBlockSpawn5(192, 240);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}

			}
		}


		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl5 == true) {
		if (lvlRep == 0) {
		
			App->tilemap->DestroyBlock(192, 144);
			App->tilemap->DestroyBlock2(32, 176);
			App->tilemap->DestroyBlock3(64, 176);
			App->tilemap->DestroyBlock4(160, 240);
			App->tilemap->spawnfromBlock1(192, 144);
			App->tilemap->spawnfromBlock2(32, 176);
			App->tilemap->spawnfromBlock3(64, 176);
			App->tilemap->spawnfromBlock4(160, 240);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 144);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 176);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 64, 176);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 160, 240);
			App->tilemap->nextBlockSpawn1(192, 208);
			App->tilemap->nextBlockSpawn2(32, 48);
			App->tilemap->nextBlockSpawn3(64, 112);
			App->tilemap->nextBlockSpawn4(96, 32);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl6 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(96, 240);
			App->tilemap->DestroyBlock2(96, 208);
			App->tilemap->DestroyBlock3(64, 112);
			App->tilemap->DestroyBlock4(160, 112);
			App->tilemap->spawnfromBlock1(96, 240);
			App->tilemap->spawnfromBlock2(96, 208);
			App->tilemap->spawnfromBlock3(64, 112);
			App->tilemap->spawnfromBlock4(160, 112);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL,  96, 240);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL,  96, 208);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL,  64, 112);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 112);
			App->tilemap->nextBlockSpawn1(128, 48);
			App->tilemap->nextBlockSpawn2(192, 80);
			App->tilemap->nextBlockSpawn3(64, 144);
			App->tilemap->nextBlockSpawn4(64, 208);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl7 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(64, 80);
			App->tilemap->DestroyBlock2(32, 144);
			App->tilemap->DestroyBlock3(192, 144);
			App->tilemap->DestroyBlock4(64, 176);
			App->tilemap->spawnfromBlock1(64, 80);
			App->tilemap->spawnfromBlock2(32, 144);
			App->tilemap->spawnfromBlock3(192, 144);
			App->tilemap->spawnfromBlock4(64, 176);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 64, 80);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 144);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 144);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 64, 176);
			App->tilemap->nextBlockSpawn1(96, 112);
			App->tilemap->nextBlockSpawn2(192, 208);
			App->tilemap->nextBlockSpawn3(160, 240);
			App->tilemap->nextBlockSpawn4(32, 176);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl8 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(64, 80);
			App->tilemap->DestroyBlock2(32, 144);
			App->tilemap->DestroyBlock3(160, 176);
			App->tilemap->DestroyBlock4(192, 208);
			App->tilemap->spawnfromBlock1(64, 80);
			App->tilemap->spawnfromBlock2(32, 144);
			App->tilemap->spawnfromBlock3(160, 176);
			App->tilemap->spawnfromBlock4(192, 208);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL,    64, 80);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL,    32, 144);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 176);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL,    192, 208);
			App->tilemap->nextBlockSpawn1(192, 80);
			App->tilemap->nextBlockSpawn2(192, 112);
			App->tilemap->nextBlockSpawn3(160, 144);
			App->tilemap->nextBlockSpawn4(32, 112);
			App->tilemap->nextBlockSpawn5(96, 208);
			App->tilemap->nextBlockSpawn6(128, 176);
			
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl9 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(32, 48);
			App->tilemap->DestroyBlock2(128, 80);
			App->tilemap->DestroyBlock3(64, 208);
			App->tilemap->DestroyBlock4(64, 240);
			App->tilemap->spawnfromBlock1(32, 48);
			App->tilemap->spawnfromBlock2(128, 80);
			App->tilemap->spawnfromBlock3(64, 208);
			App->tilemap->spawnfromBlock4(64, 240);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 48);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL,	128, 80);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 208);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 64, 240);		
			App->tilemap->nextBlockSpawn1(96, 48);
			App->tilemap->nextBlockSpawn2(192, 144);
			App->tilemap->nextBlockSpawn3(64, 176);
			App->tilemap->nextBlockSpawn4(32, 176);
			App->tilemap->nextBlockSpawn5(192, 208);
			App->tilemap->nextBlockSpawn6(160, 240);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl10 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(160, 48);
			App->tilemap->DestroyBlock2(128, 80);
			App->tilemap->DestroyBlock3(32, 112);
			App->tilemap->DestroyBlock4(192, 144);
			App->tilemap->spawnfromBlock1(160, 48);
			App->tilemap->spawnfromBlock2(128, 80);
			App->tilemap->spawnfromBlock3(32, 112);
			App->tilemap->spawnfromBlock4(192, 144);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 160, 48);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 128, 80);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 112);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 144);
			App->tilemap->nextBlockSpawn1(64, 80);
			App->tilemap->nextBlockSpawn2(192, 112);
			App->tilemap->nextBlockSpawn3(160, 176);
			App->tilemap->nextBlockSpawn4(64, 240);
			App->tilemap->nextBlockSpawn5(192, 240);
			App->tilemap->nextBlockSpawn6(160, 112);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					if (App->tilemap->tilemap[15][12] == TILE_BLOCK && App->tilemap->tilemap[14][13] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);
					}
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl11 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(96, 80);
			App->tilemap->DestroyBlock2(128, 80);
			App->tilemap->DestroyBlock3(192, 112);
			App->tilemap->DestroyBlock4(32, 240);
			App->tilemap->spawnfromBlock1(96, 80);
			App->tilemap->spawnfromBlock2(128, 80);
			App->tilemap->spawnfromBlock3(192, 112);
			App->tilemap->spawnfromBlock4(32, 240);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 96, 80);		
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 128, 80);		
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 112);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 240);
			App->tilemap->nextBlockSpawn1(64, 208);
			App->tilemap->nextBlockSpawn2(192, 240);
			App->tilemap->nextBlockSpawn3(64, 144);
			App->tilemap->nextBlockSpawn4(128, 48);
			App->tilemap->nextBlockSpawn5(192, 80);
			App->tilemap->nextBlockSpawn6(160, 144);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					if (App->tilemap->tilemap[15][12] == TILE_BLOCK && App->tilemap->tilemap[14][13] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);
					}
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl12 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(96, 48);
			App->tilemap->DestroyBlock2(128, 48);
			App->tilemap->DestroyBlock3(32, 112);
			App->tilemap->DestroyBlock4(160, 144);
			App->tilemap->spawnfromBlock1(96, 48);
			App->tilemap->spawnfromBlock2(128, 48);
			App->tilemap->spawnfromBlock3(32, 112);
			App->tilemap->spawnfromBlock4(160, 144);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 48);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 128, 48);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 112);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 160, 144);
			App->tilemap->nextBlockSpawn1(192, 48);
			App->tilemap->nextBlockSpawn2(160, 48);
			App->tilemap->nextBlockSpawn3(128, 80);
			App->tilemap->nextBlockSpawn4(32, 144);
			App->tilemap->nextBlockSpawn5(32, 176);
			App->tilemap->nextBlockSpawn6(64, 144);
			App->tilemap->nextBlockSpawn7(128, 176);
			App->tilemap->nextBlockSpawn8(96, 240);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					if (App->tilemap->tilemap[15][12] == TILE_BLOCK && App->tilemap->tilemap[14][13] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);
					}
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl13 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(160, 48);
			App->tilemap->DestroyBlock2(128, 80);
			App->tilemap->DestroyBlock3(32, 112);
			App->tilemap->DestroyBlock4(192, 144);
			App->tilemap->spawnfromBlock1(160, 48);
			App->tilemap->spawnfromBlock2(128, 80);
			App->tilemap->spawnfromBlock3(32, 112);
			App->tilemap->spawnfromBlock4(192, 144);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 160, 48);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 128, 80);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 112);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 144);
			App->tilemap->nextBlockSpawn1(64, 80);
			App->tilemap->nextBlockSpawn2(192, 112);
			App->tilemap->nextBlockSpawn3(160, 112);
			App->tilemap->nextBlockSpawn4(160, 176);
			App->tilemap->nextBlockSpawn5(128, 176);
			App->tilemap->nextBlockSpawn6(64, 224);
			App->tilemap->nextBlockSpawn7(64, 208);
			App->tilemap->nextBlockSpawn8(192, 240);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					if (App->tilemap->tilemap[15][12] == TILE_BLOCK && App->tilemap->tilemap[14][13] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);
					}
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl14 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(32, 176);
			App->tilemap->DestroyBlock2(64, 176);
			App->tilemap->DestroyBlock3(160, 240);
			App->tilemap->DestroyBlock4(192, 144);
			App->tilemap->spawnfromBlock1(32, 176);
			App->tilemap->spawnfromBlock2(64, 176);
			App->tilemap->spawnfromBlock3(160, 240);
			App->tilemap->spawnfromBlock4(192, 144);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 32, 176);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 64, 176);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 160, 240);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 192, 144);
			App->tilemap->nextBlockSpawn1(192, 208);
			App->tilemap->nextBlockSpawn2(128, 80);
			App->tilemap->nextBlockSpawn3(192, 112);
			App->tilemap->nextBlockSpawn4(192, 80);
			App->tilemap->nextBlockSpawn5(32, 48);
			App->tilemap->nextBlockSpawn6(96, 48);
			App->tilemap->nextBlockSpawn7(96, 80);
			App->tilemap->nextBlockSpawn8(64, 112);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					if (App->tilemap->tilemap[15][12] == TILE_BLOCK && App->tilemap->tilemap[14][13] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);
					}
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}
	else if (lvlCont == i && App->tilemap->scenelvl15 == true) {
		if (lvlRep == 0) {
			App->tilemap->DestroyBlock(64, 80);
			App->tilemap->DestroyBlock2(32, 144);
			App->tilemap->DestroyBlock3(64, 176);
			App->tilemap->DestroyBlock4(192, 128);
			App->tilemap->spawnfromBlock1(64, 80);
			App->tilemap->spawnfromBlock2(32, 144);
			App->tilemap->spawnfromBlock3(64, 176);
			App->tilemap->spawnfromBlock4(192, 128);
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 64, 80);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 144);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 64, 176);			
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 128);
			App->tilemap->nextBlockSpawn1(32, 48);
			App->tilemap->nextBlockSpawn2(96, 48);
			App->tilemap->nextBlockSpawn3(192, 208);
			App->tilemap->nextBlockSpawn4(160, 240);
			App->tilemap->nextBlockSpawn5(128, 80);
			App->tilemap->nextBlockSpawn6(96, 80);
			App->tilemap->nextBlockSpawn7(64, 112);
			App->tilemap->nextBlockSpawn8(32, 176);
		}
		else if (lvlRep > 0) {

			for (int j = 0; j < enemiesAlive; j++) {

				if (j == 0) {
					if (App->tilemap->tilemap[1][2] == TILE_BLOCK && App->tilemap->tilemap[2][1] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);
					}
					enemiesAlive--;
				}
				else if (j == 1) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);
					enemiesAlive--;
				}
				else if (j == 2) {
					if (App->tilemap->tilemap[15][12] == TILE_BLOCK && App->tilemap->tilemap[14][13] == TILE_BLOCK) {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);
					}
					else {
						App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);
					}

					
					enemiesAlive--;
				}
				else if (j == 3) {
					App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);
					enemiesAlive--;
				}

			}

		}
		lvlRep++;
	}



	App->sceneWin->SpacePressed = false;

	if (App->tilemap->scenelvl1) {
		App->tilemap->scenelvl1 = true;
		App->tilemap->scenelvl2 = false;
		App->tilemap->scenelvl3 = false;
		App->tilemap->scenelvl4 = false;
		App->tilemap->scenelvl5 = false;
		App->tilemap->scenelvl6 = false;
		App->tilemap->scenelvl7 = false;
		App->tilemap->scenelvl8 = false;
		App->tilemap->scenelvl9 = false;
		App->tilemap->scenelvl10 = false;
		App->tilemap->scenelvl11 = false;
		App->tilemap->scenelvl12 = false;
		App->tilemap->scenelvl13 = false;
		App->tilemap->scenelvl14 = false;
		App->tilemap->scenelvl15 = false;

	}
	else {
		App->tilemap->scenelvl1 = false;
	}

	
	if (App->sceneLose->losed || App->sceneFinish->losed) {
		App->player->Enable();
		App->enemies->Enable();
		App->tilemap->Enable();
		//App->blocks->Enable();


		App->particles->Enable();
		App->sceneLose->losed = false;
		App->sceneFinish->losed = false;
	}
	else {
		App->tilemap->Enable();
		App->enemies->Enable();
		//App->blocks->Enable();
		App->player->Enable();
		App->particles->Enable();
	}

	music1 = true;
	music2 = true;
	music3 = true;
	oneTimeSound = false;
	App->tilemap->threeDiamondsFinish = false;

	return ret;
}

update_status ModuleScene::Update()
{

	/*if (App->input->keys[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		enemiesAlive = 0;
	}

	if (App->input->keys[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->player->lifes = 0;
		App->player->destroyed = true;

	}*/
	if (App->tilemap->threeDiamondsFinish && !oneTimeSound) {
		if (App->player->minutes < 1) {
			music1 = true;
			oneTimeSound = true;
		}
		else if (App->player->minutes == 1) {
			music2 = true;
			oneTimeSound = true;
		}

		else if (App->player->minutes == 2) {
			music3 = true;
			oneTimeSound = true;
		}

	}
	if (!App->tilemap->threeDiamonds) {

		if (App->player->minutes < 1 && music1 == true) {
			App->audio->PlayMusic("Assets/Audio/popcorn.ogg", 0.0f);
			music1 = false;
		}
		else if (App->player->minutes == 1 && music2 == true) {
			App->audio->PlayMusic("Assets/Audio/popcorn fast.ogg", 0.0f);
			music2 = false;
		}

		else if (App->player->minutes == 2 && music3 == true) {
			App->audio->PlayMusic("Assets/Audio/popcorn faster.ogg", 0.0f);
			music3 = false;
		}
	}
	if (App->tilemap->threeDiamonds) {
		App->audio->PlayMusic("Assets/Audio/nothing.ogg", 0.0f);
	}



	if (App->tilemap->scenelvl1 == true) {   //1


		if (App->tilemap->tilemap[12][6] == TILE_BLOCK) {

			App->tilemap->tilemap[12][6] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][10] == TILE_BLOCK) {

			App->tilemap->tilemap[8][10] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

			App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[4][8] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[8][12] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 2) {

			if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}

		if (enemiesAlive == 2 && cont == 0) {
			if (App->tilemap->tilemap[2][8] == TILE_BLOCK) {

				App->tilemap->tilemap[2][8] = TILE_NOBLOCK;
				App->tilemap->nextBlockSpawn1(128, 80);
				App->tilemap->nextBlockSpawn2(192, 144);
				App->tilemap->DestroyBlock(128, 48);
				App->tilemap->spawnfromBlock1(128, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 48);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

				App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
				App->tilemap->nextBlockSpawn1(192, 144);
				App->tilemap->DestroyBlock(128, 80);
				App->tilemap->spawnfromBlock1(128, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 80);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 2) {
			if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

				App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 144);
				App->tilemap->spawnfromBlock1(192, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 144);
			}
		}


	}
	else if (App->tilemap->scenelvl2 == true) {   //2

		if (App->tilemap->tilemap[4][6] == TILE_BLOCK) {

			App->tilemap->tilemap[4][6] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[10][8] == TILE_BLOCK) {

			App->tilemap->tilemap[10][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[14][10] == TILE_BLOCK) {

			App->tilemap->tilemap[14][10] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[10][2] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[10][10] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 2) {

			if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}

		if (enemiesAlive == 2 && cont == 0) {
			if (App->tilemap->tilemap[2][2] == TILE_BLOCK) {

				App->tilemap->tilemap[2][2] = TILE_NOBLOCK;
				App->tilemap->nextBlockSpawn1(32, 176);
				App->tilemap->nextBlockSpawn2(160, 176);
				App->tilemap->DestroyBlock(32, 48);
				App->tilemap->spawnfromBlock1(32, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 48);
			}			
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			if (App->tilemap->tilemap[10][2] == TILE_BLOCK) {

				App->tilemap->tilemap[10][2] = TILE_NOBLOCK;
				App->tilemap->nextBlockSpawn1(160, 176);
				App->tilemap->DestroyBlock(32, 176);
				App->tilemap->spawnfromBlock1(32, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 176);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 2) {
			if (App->tilemap->tilemap[10][10] == TILE_BLOCK) {

				App->tilemap->tilemap[10][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 176);
				App->tilemap->spawnfromBlock1(160, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 176);
			}
		}


	}
	else if (App->tilemap->scenelvl3 == true) {   //3

		if (App->tilemap->tilemap[2][8] == TILE_BLOCK) {

			App->tilemap->tilemap[2][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][12] == TILE_BLOCK) {

			App->tilemap->tilemap[6][12] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

			App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[6][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[4][12] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[6][4] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[8][4] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 3) {
			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 4) {

			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK
				&& App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}

		if (enemiesAlive == 2 && cont == 0) {
			if (App->tilemap->tilemap[2][6] == TILE_BLOCK) {

				App->tilemap->tilemap[2][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 48);
				App->tilemap->spawnfromBlock1(96, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 48);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			if (App->tilemap->tilemap[4][12] == TILE_BLOCK) {

				App->tilemap->tilemap[4][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 80);
				App->tilemap->spawnfromBlock1(192, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 80);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 2) {
			if (App->tilemap->tilemap[6][2] == TILE_BLOCK) {

				App->tilemap->tilemap[6][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 112);
				App->tilemap->spawnfromBlock1(32, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 112);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 3) {
			if (App->tilemap->tilemap[6][4] == TILE_BLOCK) {

				App->tilemap->tilemap[6][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 112);
				App->tilemap->spawnfromBlock1(64, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 112);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[8][4] == TILE_BLOCK) {

				App->tilemap->tilemap[8][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 144);
				App->tilemap->spawnfromBlock1(64, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			}
		}

	}
	else if (App->tilemap->scenelvl4 == true) {   //4

		if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

			App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

			App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][2] == TILE_BLOCK) {

			App->tilemap->tilemap[6][2] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[2][10] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[6][10] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[10][10] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[14][12] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 3) {
			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 4) {

			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}

		if (enemiesAlive == 2 && cont == 0) {
			if (App->tilemap->tilemap[4][4] == TILE_BLOCK) {

				App->tilemap->tilemap[4][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 80);
				App->tilemap->spawnfromBlock1(64, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 80);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			if (App->tilemap->tilemap[2][10] == TILE_BLOCK) {

				App->tilemap->tilemap[2][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 48);
				App->tilemap->spawnfromBlock1(160, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 48);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 2) {
			if (App->tilemap->tilemap[6][10] == TILE_BLOCK) {

				App->tilemap->tilemap[6][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 112);
				App->tilemap->spawnfromBlock1(160, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 112);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 3) {
			if (App->tilemap->tilemap[10][10] == TILE_BLOCK) {

				App->tilemap->tilemap[10][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 176);
				App->tilemap->spawnfromBlock1(160, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 176);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[14][12] == TILE_BLOCK) {

				App->tilemap->tilemap[14][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 240);
				App->tilemap->spawnfromBlock1(192, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 240);
			}
		}


	}
	else if (App->tilemap->scenelvl5 == true) {   //5
		
		if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

			App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[10][2] == TILE_BLOCK) {

			App->tilemap->tilemap[10][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[10][4] == TILE_BLOCK) {

			App->tilemap->tilemap[10][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[14][10] == TILE_BLOCK) {

			App->tilemap->tilemap[14][10] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[2][2] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[6][4] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[2][6] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 3) {

			if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][2] == TILE_NOBLOCK && App->tilemap->tilemap[6][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}

		if (enemiesAlive == 2 && cont == 0) {
			if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

				App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 208);
				App->tilemap->spawnfromBlock1(192, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 208);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			if (App->tilemap->tilemap[2][2] == TILE_BLOCK) {

				App->tilemap->tilemap[2][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 48);
				App->tilemap->spawnfromBlock1(32, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 48);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 2) {
			if (App->tilemap->tilemap[6][4] == TILE_BLOCK) {

				App->tilemap->tilemap[6][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 112);
				App->tilemap->spawnfromBlock1(64, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 112);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 3) {
			if (App->tilemap->tilemap[2][6] == TILE_BLOCK) {

				App->tilemap->tilemap[2][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 32);
				App->tilemap->spawnfromBlock1(96, 32);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 32);
			}
		}

	}
	else if (App->tilemap->scenelvl6 == true) {   //6
		
		if (App->tilemap->tilemap[14][6] == TILE_BLOCK) {

			App->tilemap->tilemap[14][6] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[12][6] == TILE_BLOCK) {

			App->tilemap->tilemap[12][6] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][4] == TILE_BLOCK) {

			App->tilemap->tilemap[6][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][10] == TILE_BLOCK) {

			App->tilemap->tilemap[6][10] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[4][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[8][4] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[12][4] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[12][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][4] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 3) {

			if (App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][4] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}

		if (enemiesAlive == 2 && cont == 0) {
			if (App->tilemap->tilemap[2][8] == TILE_BLOCK) {

				App->tilemap->tilemap[2][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 48);
				App->tilemap->spawnfromBlock1(128, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 48);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			if (App->tilemap->tilemap[4][12] == TILE_BLOCK) {

				App->tilemap->tilemap[4][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 80);
				App->tilemap->spawnfromBlock1(192, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 80);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 2) {
			if (App->tilemap->tilemap[8][4] == TILE_BLOCK) {

				App->tilemap->tilemap[8][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 144);
				App->tilemap->spawnfromBlock1(64, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 3) {
			if (App->tilemap->tilemap[12][4] == TILE_BLOCK) {

				App->tilemap->tilemap[12][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 208);
				App->tilemap->spawnfromBlock1(64, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 208);
			}
		}
	}
	else if (App->tilemap->scenelvl7 == true) {   //7

		if (App->tilemap->tilemap[4][4] == TILE_BLOCK) {

			App->tilemap->tilemap[4][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][2] == TILE_BLOCK) {

			App->tilemap->tilemap[8][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

			App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[10][4] == TILE_BLOCK) {

			App->tilemap->tilemap[10][4] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[2][6] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[14][10] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[10][2] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 3) {

			if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[10][2] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}

		if (enemiesAlive == 2 && cont == 0) {
			if (App->tilemap->tilemap[2][6] == TILE_BLOCK) {

				App->tilemap->tilemap[2][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 112);
				App->tilemap->spawnfromBlock1(96, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 112);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

				App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 208);
				App->tilemap->spawnfromBlock1(192, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 208);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 2) {
			if (App->tilemap->tilemap[14][10] == TILE_BLOCK) {

				App->tilemap->tilemap[14][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 240);
				App->tilemap->spawnfromBlock1(160, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 240);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 3) {
			if (App->tilemap->tilemap[10][2] == TILE_BLOCK) {

				App->tilemap->tilemap[10][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 176);
				App->tilemap->spawnfromBlock1(32, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 176);
			}
		}
	}
	else if (App->tilemap->scenelvl8 == true) {   //8

		if (App->tilemap->tilemap[4][4] == TILE_BLOCK) {

			App->tilemap->tilemap[4][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][2] == TILE_BLOCK) {

			App->tilemap->tilemap[8][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[10][10] == TILE_BLOCK) {

			App->tilemap->tilemap[10][10] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

			App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[6][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[8][10] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[6][2] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[12][6] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[10][8] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 3) {
			if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 4) {
			if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 5) {

			if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[4][12] == TILE_BLOCK) {

				App->tilemap->tilemap[4][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 80);
				App->tilemap->spawnfromBlock1(192, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 80);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[6][12] == TILE_BLOCK) {

				App->tilemap->tilemap[6][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 112);
				App->tilemap->spawnfromBlock1(192, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 112);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[8][10] == TILE_BLOCK) {

				App->tilemap->tilemap[8][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 144);
				App->tilemap->spawnfromBlock1(160, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 144);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[6][2] == TILE_BLOCK) {

				App->tilemap->tilemap[6][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 112);
				App->tilemap->spawnfromBlock1(32, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 112);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[12][6] == TILE_BLOCK) {

				App->tilemap->tilemap[12][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 208);
				App->tilemap->spawnfromBlock1(96, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 208);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[10][8] == TILE_BLOCK) {

				App->tilemap->tilemap[10][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 176);
				App->tilemap->spawnfromBlock1(128, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 176);
			}
		}
	}
	else if (App->tilemap->scenelvl9 == true) {   //9

		if (App->tilemap->tilemap[2][2] == TILE_BLOCK) {

			App->tilemap->tilemap[2][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

			App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[12][4] == TILE_BLOCK) {

			App->tilemap->tilemap[12][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[14][4] == TILE_BLOCK) {

			App->tilemap->tilemap[14][4] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[8][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[10][4] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[10][2] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[12][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[14][10] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 3) {
			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 4) {
			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK
				&& App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 5) {

			if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[10][2] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[2][6] == TILE_BLOCK) {

				App->tilemap->tilemap[2][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 48);
				App->tilemap->spawnfromBlock1(96, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 48);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

				App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 144);
				App->tilemap->spawnfromBlock1(192, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 144);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[10][4] == TILE_BLOCK) {

				App->tilemap->tilemap[10][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 176);
				App->tilemap->spawnfromBlock1(64, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 176);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[10][2] == TILE_BLOCK) {

				App->tilemap->tilemap[10][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 176);
				App->tilemap->spawnfromBlock1(32, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 176);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

				App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 208);
				App->tilemap->spawnfromBlock1(192, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 208);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[14][10] == TILE_BLOCK) {

				App->tilemap->tilemap[14][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 240);
				App->tilemap->spawnfromBlock1(160, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 240);
			}
		}
	}
	else if (App->tilemap->scenelvl10 == true) { //10

		if (App->tilemap->tilemap[2][10] == TILE_BLOCK) {

			App->tilemap->tilemap[2][10] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

			App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][2] == TILE_BLOCK) {

			App->tilemap->tilemap[6][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

			App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[6][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[6][10] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[14][4] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[14][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[10][10] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 3) {
			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 4) {
			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 5) {

			if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && App->tilemap->tilemap[6][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][10] == TILE_NOBLOCK
				&& App->tilemap->tilemap[14][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[4][4] == TILE_BLOCK) {

				App->tilemap->tilemap[4][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 80);
				App->tilemap->spawnfromBlock1(64, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 80);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[6][12] == TILE_BLOCK) {

				App->tilemap->tilemap[6][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 112);
				App->tilemap->spawnfromBlock1(192, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 112);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[6][10] == TILE_BLOCK) {

				App->tilemap->tilemap[6][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 112);
				App->tilemap->spawnfromBlock1(160, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 112);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[10][10] == TILE_BLOCK) {

				App->tilemap->tilemap[10][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 176);
				App->tilemap->spawnfromBlock1(160, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 176);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[14][4] == TILE_BLOCK) {

				App->tilemap->tilemap[14][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 240);
				App->tilemap->spawnfromBlock1(64, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 240);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[14][12] == TILE_BLOCK) {

				App->tilemap->tilemap[14][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 240);
				App->tilemap->spawnfromBlock1(192, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 240);
			}
		}
	}
	else if (App->tilemap->scenelvl11 == true) { //11

		if (App->tilemap->tilemap[4][6] == TILE_BLOCK) {

			App->tilemap->tilemap[4][6] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

			App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][12] == TILE_BLOCK) {

			App->tilemap->tilemap[6][12] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[14][2] == TILE_BLOCK) {

			App->tilemap->tilemap[14][2] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[14][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[8][4] == TILE_NOBLOCK && eggsCont == 0
			|| App->tilemap->tilemap[2][8] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[4][12] == TILE_NOBLOCK && eggsCont == 0 || App->tilemap->tilemap[8][10] == TILE_NOBLOCK && eggsCont == 0) {

			eggsCont++;

		}
		if (eggsCont == 1) {
			if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 2) {
			if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[6][2] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[14][10] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[6][2] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 3) {
			if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[10][4] == TILE_NOBLOCK && App->tilemap->tilemap[12][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[12][6] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}

		}
		if (eggsCont == 4) {
			if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK
				&& App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK
				&& App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
			else if (App->tilemap->tilemap[8][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[2][8] == TILE_NOBLOCK
				&& App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}
		if (eggsCont == 5) {

			if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && App->tilemap->tilemap[14][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][4] == TILE_NOBLOCK
				&& App->tilemap->tilemap[2][8] == TILE_NOBLOCK && App->tilemap->tilemap[4][12] == TILE_NOBLOCK && App->tilemap->tilemap[8][10] == TILE_NOBLOCK) {
				eggsCont++;
			}
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[12][4] == TILE_BLOCK) {

				App->tilemap->tilemap[12][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 208);
				App->tilemap->spawnfromBlock1(64, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 208);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[14][12] == TILE_BLOCK) {

				App->tilemap->tilemap[14][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 240);
				App->tilemap->spawnfromBlock1(192, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 240);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[8][4] == TILE_BLOCK) {

				App->tilemap->tilemap[8][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 144);
				App->tilemap->spawnfromBlock1(64, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[2][8] == TILE_BLOCK) {

				App->tilemap->tilemap[2][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 48);
				App->tilemap->spawnfromBlock1(128, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 48);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[4][12] == TILE_BLOCK) {

				App->tilemap->tilemap[4][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 80);
				App->tilemap->spawnfromBlock1(192, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 80);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[8][10] == TILE_BLOCK) {

				App->tilemap->tilemap[8][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 144);
				App->tilemap->spawnfromBlock1(160, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 144);
			}
		}
	}
	else if (App->tilemap->scenelvl12 == true) {  //12

		if (App->tilemap->tilemap[2][6] == TILE_BLOCK) {

			App->tilemap->tilemap[2][6] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[2][8] == TILE_BLOCK) {

			App->tilemap->tilemap[2][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][2] == TILE_BLOCK) {

			App->tilemap->tilemap[6][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][10] == TILE_BLOCK) {

			App->tilemap->tilemap[8][10] = TILE_NOBLOCK;
		}


		if (App->tilemap->tilemap[2][12] == TILE_NOBLOCK && eggsCont == 0) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[2][10] == TILE_NOBLOCK && eggsCont == 1) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[4][8] == TILE_NOBLOCK && eggsCont == 2) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[8][2] == TILE_NOBLOCK && eggsCont == 3) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[10][2] == TILE_NOBLOCK && eggsCont == 4) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[8][4] == TILE_NOBLOCK && eggsCont == 5) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[10][8] == TILE_NOBLOCK && eggsCont == 6) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[14][6] == TILE_NOBLOCK && eggsCont == 7) {
			eggsCont++;
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[2][12] == TILE_BLOCK) {

				App->tilemap->tilemap[2][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 48);
				App->tilemap->spawnfromBlock1(192, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 48);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[2][10] == TILE_BLOCK) {

				App->tilemap->tilemap[2][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 48);
				App->tilemap->spawnfromBlock1(160, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 48);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

				App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 80);
				App->tilemap->spawnfromBlock1(128, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 80);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[8][2] == TILE_BLOCK) {

				App->tilemap->tilemap[8][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 144);
				App->tilemap->spawnfromBlock1(32, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 144);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[10][2] == TILE_BLOCK) {

				App->tilemap->tilemap[10][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 176);
				App->tilemap->spawnfromBlock1(32, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 176);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[8][4] == TILE_BLOCK) {

				App->tilemap->tilemap[8][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 144);
				App->tilemap->spawnfromBlock1(64, 144);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 6) {
			if (App->tilemap->tilemap[10][8] == TILE_BLOCK) {

				App->tilemap->tilemap[10][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 176);
				App->tilemap->spawnfromBlock1(128, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 176);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 7) {
			if (App->tilemap->tilemap[14][6] == TILE_BLOCK) {

				App->tilemap->tilemap[14][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 240);
				App->tilemap->spawnfromBlock1(96, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 240);
			}
		}
	}
	else if (App->tilemap->scenelvl13 == true) {  //13

		if (App->tilemap->tilemap[2][10] == TILE_BLOCK) {

			App->tilemap->tilemap[2][10] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

			App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[6][2] == TILE_BLOCK) {

			App->tilemap->tilemap[6][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

			App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[4][4] == TILE_NOBLOCK && eggsCont == 0) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && eggsCont == 1) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[6][10] == TILE_NOBLOCK && eggsCont == 2) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[10][10] == TILE_NOBLOCK && eggsCont == 3) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[10][8] == TILE_NOBLOCK && eggsCont == 4) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[14][4] == TILE_NOBLOCK && eggsCont == 5) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[12][4] == TILE_NOBLOCK && eggsCont == 6) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[14][12] == TILE_NOBLOCK && eggsCont == 7) {
			eggsCont++;
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[4][4] == TILE_BLOCK) {

				App->tilemap->tilemap[4][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 80);
				App->tilemap->spawnfromBlock1(64, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 80);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[6][12] == TILE_BLOCK) {

				App->tilemap->tilemap[6][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 112);
				App->tilemap->spawnfromBlock1(192, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 112);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[6][10] == TILE_BLOCK) {

				App->tilemap->tilemap[6][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 112);
				App->tilemap->spawnfromBlock1(160, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 112);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[10][10] == TILE_BLOCK) {

				App->tilemap->tilemap[10][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 176);
				App->tilemap->spawnfromBlock1(160, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 176);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[10][8] == TILE_BLOCK) {

				App->tilemap->tilemap[10][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 176);
				App->tilemap->spawnfromBlock1(128, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 176);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[14][4] == TILE_BLOCK) {

				App->tilemap->tilemap[14][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 224);
				App->tilemap->spawnfromBlock1(64, 224);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 224);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 6) {
			if (App->tilemap->tilemap[12][4] == TILE_BLOCK) {

				App->tilemap->tilemap[12][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 208);
				App->tilemap->spawnfromBlock1(64, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 208);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 7) {
			if (App->tilemap->tilemap[14][12] == TILE_BLOCK) {

				App->tilemap->tilemap[14][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 240);
				App->tilemap->spawnfromBlock1(192, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 240);
			}
		}
	}
	else if (App->tilemap->scenelvl14 == true) {  //14

		if (App->tilemap->tilemap[10][2] == TILE_BLOCK) {

			App->tilemap->tilemap[10][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[10][4] == TILE_BLOCK) {

			App->tilemap->tilemap[10][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[14][10] == TILE_BLOCK) {

			App->tilemap->tilemap[14][10] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

			App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && eggsCont == 0) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[4][8] == TILE_NOBLOCK && eggsCont == 1) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[6][12] == TILE_NOBLOCK && eggsCont == 2) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[4][12] == TILE_NOBLOCK && eggsCont == 3) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && eggsCont == 4) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && eggsCont == 5) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[4][6] == TILE_NOBLOCK && eggsCont == 6) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[6][4] == TILE_NOBLOCK && eggsCont == 7) {
			eggsCont++;
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

				App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 208);
				App->tilemap->spawnfromBlock1(192, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 208);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

				App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 80);
				App->tilemap->spawnfromBlock1(128, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 80);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[6][12] == TILE_BLOCK) {

				App->tilemap->tilemap[6][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 112);
				App->tilemap->spawnfromBlock1(192, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 112);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[4][12] == TILE_BLOCK) {

				App->tilemap->tilemap[4][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 80);
				App->tilemap->spawnfromBlock1(192, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 80);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[2][2] == TILE_BLOCK) {

				App->tilemap->tilemap[2][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 48);
				App->tilemap->spawnfromBlock1(32, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 48);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[2][6] == TILE_BLOCK) {

				App->tilemap->tilemap[2][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 48);
				App->tilemap->spawnfromBlock1(96, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 48);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 6) {
			if (App->tilemap->tilemap[4][6] == TILE_BLOCK) {

				App->tilemap->tilemap[4][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 80);
				App->tilemap->spawnfromBlock1(96, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 80);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 7) {
			if (App->tilemap->tilemap[6][4] == TILE_BLOCK) {

				App->tilemap->tilemap[6][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 112);
				App->tilemap->spawnfromBlock1(64, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 112);
			}
		}
	}
	else if (App->tilemap->scenelvl15 == true) { //15

		if (App->tilemap->tilemap[4][4] == TILE_BLOCK) {

			App->tilemap->tilemap[4][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][2] == TILE_BLOCK) {

			App->tilemap->tilemap[8][2] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[10][4] == TILE_BLOCK) {

			App->tilemap->tilemap[10][4] = TILE_NOBLOCK;
		}
		if (App->tilemap->tilemap[8][12] == TILE_BLOCK) {

			App->tilemap->tilemap[8][12] = TILE_NOBLOCK;
		}

		if (App->tilemap->tilemap[2][2] == TILE_NOBLOCK && eggsCont == 0) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[2][6] == TILE_NOBLOCK && eggsCont == 1) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[12][12] == TILE_NOBLOCK && eggsCont == 2) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[14][10] == TILE_NOBLOCK && eggsCont == 3) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[4][8] == TILE_NOBLOCK && eggsCont == 4) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[4][6] == TILE_NOBLOCK && eggsCont == 5) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[6][4] == TILE_NOBLOCK && eggsCont == 6) {
			eggsCont++;
		}
		else if (App->tilemap->tilemap[10][2] == TILE_NOBLOCK && eggsCont == 7) {
			eggsCont++;
		}

		if (enemiesAlive == 3 && cont == 0) {
			if (App->tilemap->tilemap[2][2] == TILE_BLOCK) {

				App->tilemap->tilemap[2][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 48);
				App->tilemap->spawnfromBlock1(32, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 48);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			if (App->tilemap->tilemap[2][6] == TILE_BLOCK) {

				App->tilemap->tilemap[2][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 48);
				App->tilemap->spawnfromBlock1(96, 48);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 48);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			if (App->tilemap->tilemap[12][12] == TILE_BLOCK) {

				App->tilemap->tilemap[12][12] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(192, 208);
				App->tilemap->spawnfromBlock1(192, 208);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 192, 208);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			if (App->tilemap->tilemap[14][10] == TILE_BLOCK) {

				App->tilemap->tilemap[14][10] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(160, 240);
				App->tilemap->spawnfromBlock1(160, 240);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 160, 240);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 4) {
			if (App->tilemap->tilemap[4][8] == TILE_BLOCK) {

				App->tilemap->tilemap[4][8] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(128, 80);
				App->tilemap->spawnfromBlock1(128, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 80);
			}
			cont++;
		}
		if (enemiesAlive == 2 && cont == 5) {
			if (App->tilemap->tilemap[4][6] == TILE_BLOCK) {

				App->tilemap->tilemap[4][6] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(96, 80);
				App->tilemap->spawnfromBlock1(96, 80);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 96, 80);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 6) {
			if (App->tilemap->tilemap[6][4] == TILE_BLOCK) {

				App->tilemap->tilemap[6][4] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(64, 112);
				App->tilemap->spawnfromBlock1(64, 112);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 112);
			}
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 7) {
			if (App->tilemap->tilemap[10][2] == TILE_BLOCK) {

				App->tilemap->tilemap[10][2] = TILE_NOBLOCK;
				App->tilemap->DestroyBlock(32, 176);
				App->tilemap->spawnfromBlock1(32, 176);
				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 32, 176);
			}
		}
	}



	if (enemiesAlive == 0)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneWin, 30);

	}



	oneAnim.Update();
	miniEnemyEggAnim.Update();
	
	return update_status::UPDATE_CONTINUE;
}



// Update: draw background
update_status ModuleScene::PostUpdate()
{

	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 8, 24, NULL);

	App->tilemap->DrawMap();

	if (App->tilemap->scenelvl1 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 1");
	}
	else if (App->tilemap->scenelvl2 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 2");
	}
	else if (App->tilemap->scenelvl3 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 3");
	}
	else if (App->tilemap->scenelvl4 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 4");
	}
	else if (App->tilemap->scenelvl5 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 5");
	}
	else if (App->tilemap->scenelvl6 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 6");
	}
	else if (App->tilemap->scenelvl7 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 7");
	}
	else if (App->tilemap->scenelvl8 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 8");
	}
	else if (App->tilemap->scenelvl9 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act 9");
	}
	else if (App->tilemap->scenelvl10 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act10");
	}
	else if (App->tilemap->scenelvl11 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act11");
	}
	else if (App->tilemap->scenelvl12 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act12");
	}
	else if (App->tilemap->scenelvl13 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act13");
	}
	else if (App->tilemap->scenelvl14 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act14");
	}
	else if (App->tilemap->scenelvl15 == true)
	{
		App->fonts->BlitText(16, 280, whiteFont, "act15");
	}

	App->fonts->BlitText(144, 280, whiteFont, "© sega 1982");
	App->fonts->BlitText(88, 0, blueFont, "hi");
	if (App->player->score <= 20000) {
		App->fonts->BlitText(112, 0, whiteFont, "20000");
	}
	App->fonts->BlitText(160, 0, blueFont, "2p");
	App->fonts->BlitText(216, 0, whiteFont, "0");

	if (App->player->lifes == 4) {
		App->render->Blit(scTexture, 8, 8, &pRed);
		App->render->Blit(scTexture, 24, 8, &pRed);
		App->render->Blit(scTexture, 40, 8, &pRed);
	}
	if (App->player->lifes == 3) {
		App->render->Blit(scTexture, 8, 8, &pRed);
		App->render->Blit(scTexture, 24, 8, &pRed);
	}
	if (App->player->lifes == 2) {
		App->render->Blit(scTexture, 8, 8, &pRed);
	}
	if (App->player->lifes == 1) {

	}


	if (App->player->lifes > 0 && App->player->destroyed)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->scene, 60);
		App->player->colliderPlayer->pendingToDelete = true;
	}
	else if (App->player->lifes == 0 && App->player->destroyed)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneLose, 60);
		App->player->lifes = 4;
		//App->tilemap->scenelvl1 = true;
	}

	if (App->input->keys[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneLose, 60);
	}


	//if (App->player->scoreOneHundred)
	//{
	//	
	//	if (timescore != 0) {
	//		timescore++;
	//		App->render->Blit(onehundredPoints, posEnemyX, posEnemyY, &(oneHundred.GetCurrentFrame()), 0.1f);
	//		if (timescore > 100 ) {
	//			App->player->scoreOneHundred = false;
	//			
	//			timescore = false;
	//			timescore = 0;
	//			timescore = true;
	//			//App->player->snobeeStunned = false;
	//		}
	//	}

	//}


	if (App->tilemap->scenelvl1 == true || App->tilemap->scenelvl6 == true || App->tilemap->scenelvl11 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl2 == true || App->tilemap->scenelvl7 == true || App->tilemap->scenelvl12 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl3 == true || App->tilemap->scenelvl8 == true || App->tilemap->scenelvl13 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
		App->render->Blit(scTexture, 96, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl4 == true || App->tilemap->scenelvl9 == true || App->tilemap->scenelvl14 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
		App->render->Blit(scTexture, 96, 280, &pYellow);
		App->render->Blit(scTexture, 112, 280, &pYellow);
	}
	else if (App->tilemap->scenelvl5 == true || App->tilemap->scenelvl10 == true || App->tilemap->scenelvl15 == true)
	{
		App->render->Blit(scTexture, 64, 280, &pYellow);
		App->render->Blit(scTexture, 80, 280, &pYellow);
		App->render->Blit(scTexture, 96, 280, &pYellow);
		App->render->Blit(scTexture, 112, 280, &pYellow);
		App->render->Blit(scTexture, 128, 280, &pYellow);
	}

	if (App->tilemap->scenelvl6 == true || App->tilemap->scenelvl7 == true || App->tilemap->scenelvl8 == true || App->tilemap->scenelvl9 == true || App->tilemap->scenelvl10 == true)
	{
		App->render->Blit(scTexture, 216, 8, &pYellowFive);
	}
	else if (App->tilemap->scenelvl11 == true || App->tilemap->scenelvl12 == true || App->tilemap->scenelvl13 == true || App->tilemap->scenelvl14 == true || App->tilemap->scenelvl15 == true)
	{
		App->render->Blit(scTexture, 216, 8, &pYellowFive);
		App->render->Blit(scTexture, 200, 8, &pYellowFive);
	}
		
	if (App->tilemap->scenelvl1 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {}
		else {
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}

	}
	if (App->tilemap->scenelvl2 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {}
		else {
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}

	}
	if (App->tilemap->scenelvl3 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {}
		else {
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}

	}
	if (App->tilemap->scenelvl4 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {}
		else {
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}

	}
	if (App->tilemap->scenelvl5 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
		}
		else {
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		if (App->tilemap->scenelvl6 == true) {

			if (!App->tilemap->spawn1 && eggsCont == 0) {
				App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			}
			else if (eggsCont == 1) {
				App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			}
			else if (eggsCont == 2) {
				App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			}
			else if (eggsCont == 3) {
				App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			}
			else if (eggsCont == 4) {
			}
			else {
				App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
				App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			}
		}
	}
	if (App->tilemap->scenelvl7 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
		}
		else {
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl8 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
		}
		else {
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl9 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
		}
		else {
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl10 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
		}
		else {
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl11 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
		}
		else {
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl12 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 7) {
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 8) {
		}
		else {
			App->render->Blit(scTexture, 72, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl13 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 7) {
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 8) {
		}
		else {
			App->render->Blit(scTexture, 72, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl14 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 7) {
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 8) {
		}
		else {
			App->render->Blit(scTexture, 72, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}
	if (App->tilemap->scenelvl15 == true) {

		if (!App->tilemap->spawn1 && eggsCont == 0) {

			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 1) {
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 2) {
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 3) {
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 4) {
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 5) {
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 6) {
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 7) {
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
		else if (eggsCont == 8) {
		}
		else {
			App->render->Blit(scTexture, 72, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 80, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 88, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 144, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 152, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
			App->render->Blit(scTexture, 160, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
		}
	}

	App->render->Blit(oneTexture, 16, 0, &(oneAnim.GetCurrentFrame()), 0.1f);



	return update_status::UPDATE_CONTINUE;
}



bool ModuleScene::CleanUp()
{

	App->fonts->UnLoad(whiteFont);
	App->fonts->UnLoad(blueFont);

	App->textures->Unload(bgTexture);
	App->textures->Unload(chTexture);
	App->textures->Unload(blTexture);
	App->textures->Unload(scTexture);
	App->textures->Unload(oneTexture);
	App->textures->Unload(bgTexture);

	oneAnim.Reset();
	miniEnemyEggAnim.Reset();


	App->player->Disable();
	App->enemies->Disable();
	App->blocks->Disable();
	App->tilemap->Disable();
	App->particles->Disable();

	return true;
}

