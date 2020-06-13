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
	oneTexture = App->textures->Load("Assets/1p.png");
	//onehundredPoints = App->textures->Load("Assets/100points.png");

	App->audio->PlayMusic("Assets/Audio/popcorn.ogg", 1.0f);

	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);

	blueFont = App->fonts->Load("Assets/blueFont.png", lookupTable, 3);

	if (lvlCont == i && App->tilemap->scenelvl1 == true) {
		if (lvlRep == 0) {

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);


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

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);


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

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);

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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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


			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 208, 32);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 208, 256);

			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, 16, 256);


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

	
	if (App->sceneLose->losed) {
		App->player->Enable();
		App->enemies->Enable();
		App->tilemap->Enable();
		//App->blocks->Enable();


		App->particles->Enable();
		App->sceneLose->losed = false;
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
	if (App->player->minutes == 1 && music1 == true) {
		music1 = false;
		App->audio->PlayMusic("Assets/Audio/popcorn fast.ogg", 0.0f);
	}

	if (App->player->minutes == 2 && music2 == true) {
		music2 = false;
		App->audio->PlayMusic("Assets/Audio/popcorn faster.ogg", 0.0f);
	}


	if (App->tilemap->scenelvl1 == true) {   //4

		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 144);
		}


	}
	else if (App->tilemap->scenelvl2 == true) {   //4

		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 144);
		}


	}
	else if (App->tilemap->scenelvl3 == true) {   //4

		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
		}

	}
	else if (App->tilemap->scenelvl4 == true) {   //4

		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
		}


	}
	else if (App->tilemap->scenelvl5 == true) {   //5

		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
		}

	}
	else if (App->tilemap->scenelvl6 == true) {   //6

		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
		}
	}
	else if (App->tilemap->scenelvl7 == true) {   //7

		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 144);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
		}
	}
	else if (App->tilemap->scenelvl8 == true) {   //8

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);		
		}
	}
	else if (App->tilemap->scenelvl9 == true) {   //9

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
		}
	}
	else if (App->tilemap->scenelvl10 == true) { //10

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
		}
	}
	else if (App->tilemap->scenelvl11 == true) { //11

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
		}
	}
	else if (App->tilemap->scenelvl12 == true) {  //12

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);	
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
		}
	}
	else if (App->tilemap->scenelvl13 == true) {  //13

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
		}
	}
	else if (App->tilemap->scenelvl14 == true) {  //14

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
		}
	}
	else if (App->tilemap->scenelvl15 == true) { //15

		if (enemiesAlive == 3 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 0) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 32);
			cont++;
		}
		if (enemiesAlive == 2 && cont == 1) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 64, 144);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 2) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 128, 256);
			cont++;
		}
		else if (enemiesAlive == 3 && cont == 3) {
			App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, 16, 32);
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
		App->player->collider->pendingToDelete = true;
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


	


	App->render->Blit(scTexture, 96, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 104, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 112, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 120, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 128, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);
	App->render->Blit(scTexture, 136, 16, &(miniEnemyEggAnim.GetCurrentFrame()), 0.1f);

	App->render->Blit(oneTexture, 16, 0, &(oneAnim.GetCurrentFrame()), 0.1f);



	return update_status::UPDATE_CONTINUE;
}



bool ModuleScene::CleanUp()
{
	App->player->Disable();
	App->enemies->Disable();
	App->blocks->Disable();
	App->tilemap->Disable();
	App->particles->Disable();


	App->fonts->UnLoad(whiteFont);
	App->fonts->UnLoad(blueFont);

	App->textures->Unload(bgTexture);
	App->textures->Unload(chTexture);
	App->textures->Unload(blTexture);
	App->textures->Unload(scTexture);
	App->textures->Unload(oneTexture);





	return true;
}

