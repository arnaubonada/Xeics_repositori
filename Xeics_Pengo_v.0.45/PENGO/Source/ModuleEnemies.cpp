#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModuleScene.h"
#include "ModuleTileMap.h"

#include <stdio.h>

#include "SDL/include/SDL_scancode.h"

#include "time.h"



ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	name = "enemies";

	// move up
	snoUpAnim.PushBack({ 64, 160, 16, 16 });
	snoUpAnim.PushBack({ 80, 160, 16, 16 });
	snoUpAnim.speed = 0.1f;
	//currentAnim = &snoUpAnim;

	// Move down
	snoDownAnim.PushBack({ 0, 160, 16, 16 });
	snoDownAnim.PushBack({ 16, 160, 16, 16 });
	snoDownAnim.speed = 0.1f;

	// move left
	snoLeftAnim.PushBack({ 32, 160, 16, 16 });
	snoLeftAnim.PushBack({ 48, 160, 16, 16 });
	snoLeftAnim.speed = 0.1f;

	// Move right
	snoRightAnim.PushBack({ 96, 160, 16, 16 });
	snoRightAnim.PushBack({ 112, 160, 16, 16 });
	snoRightAnim.speed = 0.1f;


	// move up
	snoUpAnim2.PushBack({ 64, 160, 16, 16 });
	snoUpAnim2.PushBack({ 80, 160, 16, 16 });
	snoUpAnim2.speed = 0.1f;
	//currentAnim = &snoUpAnim;

	// Move down
	snoDownAnim2.PushBack({ 0, 160, 16, 16 });
	snoDownAnim2.PushBack({ 16, 160, 16, 16 });
	snoDownAnim2.speed = 0.1f;

	// move left
	snoLeftAnim2.PushBack({ 32, 160, 16, 16 });
	snoLeftAnim2.PushBack({ 48, 160, 16, 16 });
	snoLeftAnim2.speed = 0.1f;

	// Move right
	snoRightAnim2.PushBack({ 96, 160, 16, 16 });
	snoRightAnim2.PushBack({ 112, 160, 16, 16 });
	snoRightAnim2.speed = 0.1f;


	//currentAnim = &flyAnim;

	//collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
}




ModuleEnemies::~ModuleEnemies()
{

}

bool ModuleEnemies::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Characters.png");
	snobeeFx = App->audio->LoadFx("Assets/Audio/snobeekill.wav");
	currentAnim = &snoDownAnim;

	position.x = 176;
	position.y = 64;
	//position.x = 112;
	//position.y = 128;

	/*laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");*/

	collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, this);
	destroyedEnemy = false;


	srand(time(NULL));

	
	return ret;
}

update_status ModuleEnemies::Update()
{


	longer = rand() % 2;


	if (j == 0) {
		opcio = rand() % 5;
		j++;
	}
		if (j < 17) {
			j++;
		}
		if (j == 17) {
			j = 0;
		}

	if (rep == 16) {
		rep = 0;

	}

	switch (opcio)
	{

	case 0:
		currentAnim = &snoDownAnim2;
		break;

	case 1:
		currentAnim = &snoLeftAnim2;
		break;

	case 2:
		currentAnim = &snoRightAnim2;
		break;
	case 3:
		currentAnim = &snoDownAnim2;
		break;

	case 4:
		currentAnim = &snoUpAnim2;
		break;


	default:
		break;
	}

	if (rep == 0) {
		if (!destroyedEnemy) {
			if (opcio == 1)
			{
				if (App->tilemap->isWalkable(position.x - 16, position.y)) {
					if (currentAnim != &snoLeftAnim)
					{
						position.x -= move;
						opcio = 1;
						rep++;

					}
				}
			}
			else {

				if (opcio == 2)
				{
					if (App->tilemap->isWalkable(position.x + 16, position.y)) {
						if (currentAnim != &snoRightAnim)
						{
							position.x += move;
							opcio = 2;
							rep++;

						}
					}
				}
				else {
					if (opcio == 3)
					{
						if (App->tilemap->isWalkable(position.x, position.y + 16)) {
							if (currentAnim != &snoDownAnim)
							{
								position.y += move;
								opcio = 3;
								rep++;

							}
						}
					}

					else {
						if (opcio == 4)
						{
							if (App->tilemap->isWalkable(position.x, position.y - 16)) {
								if (currentAnim != &snoUpAnim)
								{
									position.y -= move;
									opcio = 4;
									rep++;


								}

							}
						}
					}

				}


			}
		}
	}
	else {


		if (!destroyedEnemy) {

			if (opcio == 1)
			{
				position.x -= move;
				opcio = 1;
				rep++;

			}

			else {

				{
					if (opcio == 2)
					{
						position.x += move;
						opcio = 2;
						rep++;


					}

					else {

						if (opcio == 3)
						{
							position.y += move;
							opcio = 3;
							rep++;


						}


						else {

							if (opcio == 4)
							{
								position.y -= move;
								opcio = 4;

								rep++;

							}
						}


					}


				}
			}



		}
	}
	if (!destroyedEnemy) {
		if (App->tilemap->thereIsABlock(position.x, position.y)) {
			destroyedEnemy = true;

		}
	}

	collider->SetPos(position.x, position.y);

	currentAnim->Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	SDL_Rect rect = currentAnim->GetCurrentFrame();
	if (!destroyedEnemy)
	{
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	if (destroyedEnemy) {
		currentAnim = &deadAnim;
		rect = currentAnim->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}


	return update_status::UPDATE_CONTINUE;
}


void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == Collider::Type::ENEMY) {

		if (c2 == App->scene->leftWall) {
			position.x = 8;
		}
		if (c2 == App->scene->rightWall) {
			position.x = 200;
		}
		if (c2 == App->scene->bottomWall) {
			position.y = 256;
		}
		if (c2 == App->scene->topWall) {
			position.y = 32;
		}
		/*
		if (c2->type == Collider::Type::BLOCK && opcio == 1)
		{
			position.x += move;

		}
		if (c2->type == Collider::Type::BLOCK && opcio == 2)
		{
			position.x -= move;

		}if (c2->type == Collider::Type::BLOCK && opcio == 3)
		{
			position.y -= move;

		}
		if (c2->type == Collider::Type::BLOCK && opcio == 4)
		{
			position.y += move;

		}

		if (c2->type == Collider::Type::PLAYER)
		{
			App->audio->PlayFx(snobeeFx);
			destroyedEnemy = true;


			//c2->pendingToDelete = true;

		}

		*/
	}
}



