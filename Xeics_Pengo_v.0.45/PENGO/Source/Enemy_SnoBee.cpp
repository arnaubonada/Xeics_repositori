#include "Enemy_SnoBee.h"

#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleScene.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleTileMap.h"

#include "time.h"

#include "SDL/include/SDL.h"


Enemy_SnoBee::Enemy_SnoBee(int x, int y, enum class ENEMY_TYPE type) : Enemy(x, y)
{
	snobeeFx = App->audio->LoadFx("Assets/Audio/snobeekill.wav");

	typeEnemy = type;

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

	currentAnim = &snoDownAnim;

	if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER)
	{
		collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
		currentAnim = &snoDownAnim;
	}
	else if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL)
	{
		collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
		currentAnim = &snoDownAnim;
	}
}

void Enemy_SnoBee::Update()
{
	if (!App->player->destroyed) {
		enemyMovement(position.x, position.y);
	}
	else if (App->player->destroyed)
	{
		collider->pendingToDelete = true;

	}

	Enemy::Update();
}


void Enemy_SnoBee::enemyMovement(int x, int y)
{
	//movement nou

	//

	//positionEnemyX = x;
	//positionEnemyY = y;


	////dirEnemy = rand() % RIGHT + 1; //enemy direction
	//dirEnemy = static_cast<Direction>(rand() % last);

	//if (App->tilemap->spaceToBlock(positionEnemyX, positionEnemyY, dirEnemy) != 0) {
	//	EnemyToBlock = rand() % App->tilemap->spaceToBlock(positionEnemyX, positionEnemyY, dirEnemy);
	//}



	//if (dirEnemy == LEFT) {
	//	//dirEnemy = LEFT;
	//	//currentAnim = &snoLeftAnim2;
	//	finalEnemyPositionX = x - (EnemyToBlock * 16);
	//}
	//else if (dirEnemy == RIGHT) {
	//	//dirEnemy = RIGHT;
	//	//currentAnim = &snoRightAnim2;
	//	finalEnemyPositionX = x + (EnemyToBlock * 16);
	//}
	//else if (dirEnemy == UP) {
	//	//dirEnemy = UP;
	//	//currentAnim = &snoUpAnim2;
	//	finalEnemyPositionY = y - (EnemyToBlock * 16);
	//}
	//else if (dirEnemy == DOWN) {
	//	//dirEnemy = DOWN;
	//	//currentAnim = &snoDownAnim2;
	//	finalEnemyPositionY = y + (EnemyToBlock * 16);
	//}



	//if (dirEnemy != NOMOVE) {


	//	if (dirEnemy == LEFT) {

	//		if (positionEnemyX == finalEnemyPositionX) {
	//			dirEnemy = NOMOVE;
	//		}
	//		positionEnemyX-=16;
	//		position.x-=16;
	//	}

	//	else if (dirEnemy == RIGHT) {

	//		if (positionEnemyX == finalEnemyPositionX) {
	//			dirEnemy = NOMOVE;
	//		}
	//		positionEnemyX+=16;
	//		position.x+=16;

	//	}
	//	else if (dirEnemy == UP) {

	//		if (positionEnemyY == finalEnemyPositionY) {
	//			dirEnemy = NOMOVE;
	//		}
	//		positionEnemyY-=16;
	//		position.y-=16;

	//	}
	//	else if (dirEnemy == DOWN) {

	//		if (positionEnemyY == finalEnemyPositionY) {
	//			dirEnemy = NOMOVE;
	//		}
	//		positionEnemyY+=16;
	//		position.y+=16;
	//	}


	//}


	// movement antic



	if (j == 0 && !App->tilemap->threeDiamonds) {
		opcio = rand() % 4 + 1;
		j++;
	}
	//while (longer != 0) {
	if (j < 17) {
		j++;
	}
	if (j == 17) {
		j = 0;
	}
	//longer--;
	//}


	if (rep == 16) {
		rep = 0;

	}

	switch (opcio)
	{

		//case 0:
		//	currentAnim = &snoDownAnim2;
		//	break;

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
	/*if (!destroyedEnemy) {
		if (App->tilemap->thereIsABlock(position.x, position.y)) {
			destroyedEnemy = true;

		}
	}*/
}


void Enemy_SnoBee::OnCollision(Collider* c1) {

	/*SDL_Rect r = this->collider->rect;

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
	if (c2->type == Collider::Type::BLOCK && App->enemies->RandomDirection() == 0)
	{
		if (c2->Intersects(r) == true) {
			position.x -= moveE;
		}

	}
	if (c2->type == Collider::Type::BLOCK && App->enemies->RandomDirection() == 1)
	{
		if (c2->Intersects(r) == true) {
			position.x += moveE;
		}

	}
	if (c2->type == Collider::Type::BLOCK && App->enemies->RandomDirection() == 2)
	{
		if (c2->Intersects(r) == true) {
			position.y -= moveE;
		}

	}
	if (c2->type == Collider::Type::BLOCK && App->enemies->RandomDirection() == 3)
	{
		if (c2->Intersects(r) == true) {
			position.y += moveE;
		}

	}*/
}