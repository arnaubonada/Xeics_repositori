#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleBlocks.h"

ModuleScene::ModuleScene(bool startEnabled) :Module (startEnabled)
{
	noBlocks = SDL_Rect{ 50,50,16,16 }; blocks = SDL_Rect{ 708,0,16,16 }; pengo = SDL_Rect{ 0,0,16,16 }; snobees = SDL_Rect{ 0,160,16,16 };

	A = SDL_Rect{ 9,184,8,8 }; C = SDL_Rect{ 27,184,8,8 }; T = SDL_Rect{ 36,193,8,8 }; 
	oneblue= SDL_Rect{ 9,202,8,8 }; P = SDL_Rect{ 0,220,8,8 }; twoblue = SDL_Rect{ 18,202,8,8 };
	one= SDL_Rect{ 9,175,8,8 }; pYellow =SDL_Rect{ 54,158,16,8 }; pRed = SDL_Rect{ 0,150,16,16 };
	zero = SDL_Rect{ 0,175,8,8 }; Hblue = SDL_Rect{ 72,211,8,8 }; Iblue = SDL_Rect{ 81,211,8,8 };

	pmatriux = 0;
	pmatriuy = 0;

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
	segaTexture = App->textures->Load("Assets/SEGA1982.png");
	App->audio->PlayMusic("Assets/stage1.ogg", 1.0f);
	


	//MATRIU
	
	map.x = 8;
	map.y = 8;
	
	for (pmatriux = 0; pmatriux < 13; pmatriux++) {
		map.y = 8;
		for (pmatriuy = 0; pmatriuy < 15; pmatriuy++) {

			matriu[pmatriux][pmatriuy] = NOBLOCKS;
			map.y += 16;

		}
		map.x += 16;
	}





	//Bottomside
	App->collisions->AddCollider({ 0, 272, 224, 8 }, Collider::Type::WALL);

	//leftside
	App->collisions->AddCollider({ 0, 24, 8, 256 }, Collider::Type::WALL);

	//topside
	App->collisions->AddCollider({ 0, 24, 224, 8 }, Collider::Type::WALL);

	//rightside
	App->collisions->AddCollider({ 216, 24, 8, 256 }, Collider::Type::WALL);



	




	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE, 50, 50);

	//blocks 
	//App->blocks->AddBlock(BLOCK_TYPE::NORMAL, 200, 200);

	App->player->Enable();
	App->enemies->Enable();
	App->blocks->Enable();

	return ret;
}

update_status ModuleScene::Update()
{
	//App->render->camera.x += 3;



	return update_status::UPDATE_CONTINUE;
}



int ModuleScene::getState(int x, int y)
{
	return _state;
}

int ModuleScene::borrar(int state)
{

	App->render->Blit(bgTexture, map.x, map.y, &noBlocks);
	matriu[map.x][map.y] = NOBLOCKS;
	_state = NOBLOCKS;
	return _state;
}

int ModuleScene::pintarBlock(int state)
{
	App->render->Blit(blTexture, map.x, map.y, &blocks);
	matriu[map.x][map.y] = BLOCKS;

	_state = BLOCKS;
	return _state;
}

int ModuleScene::pintarPengo(int state)
{
	App->render->Blit(chTexture, map.x, map.y, &pengo);
	matriu[map.x][map.y] = PENGO;

	_state = PENGO;
	return _state;
}





// Update: draw background
update_status ModuleScene::PostUpdate()
{

	// Draw everything --------------------------------------
	//App->render->Blit(bgTexture, 0, 24, NULL);

	App->render->Blit(segaTexture, 136, 280, NULL);

	App->render->Blit(scTexture, 8, 280, &A);
	App->render->Blit(scTexture, 16, 280, &C);
	App->render->Blit(scTexture, 24, 280, &T);
	App->render->Blit(scTexture, 40, 280, &one);

	App->render->Blit(scTexture, 56, 280, &pYellow);

	App->render->Blit(scTexture, 8, 0, &oneblue);
	App->render->Blit(scTexture, 16, 0, &P);
	App->render->Blit(scTexture, 152, 0, &twoblue);
	App->render->Blit(scTexture, 160, 0, &P);

	App->render->Blit(scTexture, 0, 8, &pRed);
	App->render->Blit(scTexture, 16, 8, &pRed);
	App->render->Blit(scTexture, 32, 8, &pRed);

	App->render->Blit(scTexture, 64, 0, &zero);
	App->render->Blit(scTexture, 136, 0, &zero);
	App->render->Blit(scTexture, 208, 0, &zero);
	
	App->render->Blit(scTexture, 80, 0, &Hblue); 
	App->render->Blit(scTexture, 88, 0, &Iblue);
	
	App->render->Blit(scTexture, 88, 0, &Iblue);




	
	//App->render->Blit(chTexture, pmatriux, pmatriuy, &pengo);
	if (_state == NOBLOCKS) {
		App->render->Blit(bgTexture, map.x, map.y, &noBlocks);
	}
	else if (_state == BLOCKS) {
		App->render->Blit(scTexture, map.x, map.y, &blocks);
	}
	else if (_state == PENGO) {
		App->render->Blit(chTexture, map.x, map.y, &pengo);
	}
	else if (_state == SNOBEES){
		App->render->Blit(chTexture, map.x, map.y, &snobees);
	}

	return update_status::UPDATE_CONTINUE;
}



bool ModuleScene::CleanUp()
{
	App->player->Disable();
	App->enemies->Disable();
	App->blocks->Disable();

	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}

