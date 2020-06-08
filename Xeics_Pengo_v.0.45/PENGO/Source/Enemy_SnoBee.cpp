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

	stunnedAnim.PushBack({ 96, 128, 16, 16 });
	stunnedAnim.PushBack({ 112, 128, 16, 16 });
	stunnedAnim.speed = 0.1f;
	
	stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
	stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
	stunnedBlueAnim.PushBack({ 96, 128, 16, 16 });
	stunnedBlueAnim.PushBack({ 112, 128, 16, 16 });
	stunnedBlueAnim.speed = 0.1f;


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
		if (!App->tilemap->threeDiamonds) {
			if (stunnedEnemy) {
				dirEnemy = NOMOVE;
			}

		if (dirEnemy == NOMOVE) {
			enemyMovement();
		}

		if (dirEnemy != NOMOVE) {


			if (dirEnemy == LEFT) {
				if (App->tilemap->isWalkable(position.x - 16, position.y)) {
					position.x--;
					if (position.x == finalEnemyPositionX) {
						dirEnemy = NOMOVE;
					}
					//positionEnemyX--;


				}
				else {
					dirEnemy = NOMOVE;
				}
			}

			else if (dirEnemy == RIGHT) {
				if (App->tilemap->isWalkable(position.x + 16, position.y)) {
					position.x++;

					if (position.x == finalEnemyPositionX) {
						dirEnemy = NOMOVE;
					}
					//	positionEnemyX++;
				}
				else {
					dirEnemy = NOMOVE;
				}
			}
			else if (dirEnemy == UP) {
				if (App->tilemap->isWalkable(position.x, position.y - 16)) {
					position.y--;

					if (position.y == finalEnemyPositionY) {
						dirEnemy = NOMOVE;
					}
					//positionEnemyY--;

				}
				else {
					dirEnemy = NOMOVE;
				}
			}
			else if (dirEnemy == DOWN) {
				if (App->tilemap->isWalkable(position.x, position.y + 16)) {
					position.y++;
					if (position.y == finalEnemyPositionY) {
						dirEnemy = NOMOVE;
					}
					//positionEnemyY++;

				}
				else {
					dirEnemy = NOMOVE;
					}

				}
			}
		}


		if (App->tilemap->pushLeft) {
			if (position.x == 16) {
				currentAnim = &stunnedAnim;
				stunnedEnemy = true;
				App->player->snobeeStunned = true;
				timeStunned = 1;
				App->scene->timescore = 1;

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
			}
		}
		if (App->tilemap->pushRight) {
			if (position.x == 208) {
				currentAnim = &stunnedAnim;
				stunnedEnemy = true;
				App->player->snobeeStunned = true;
				timeStunned = 1;
				App->scene->timescore = 1;

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
			}
		}
		if (App->tilemap->pushUp) {
			if (position.y == 32) {
				currentAnim = &stunnedAnim;
				stunnedEnemy = true;
				App->player->snobeeStunned = true;
				timeStunned = 1;
				App->scene->timescore = 1;

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
			}
		}
		if (App->tilemap->pushDown) {
			if (position.y == 256) {
				currentAnim = &stunnedAnim;
				stunnedEnemy = true;
				App->player->snobeeStunned = true;
				timeStunned = 1;
				App->scene->timescore = 1;

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
			}
		}
		if (timeStunned != 0) {
			stunnedEnemy = true;
			App->player->snobeeStunned = true;
			timeStunned++;
			if (timeStunned < 300 && timeStunned>120) {
				currentAnim = &stunnedBlueAnim;
			}
			if (timeStunned > 300) {
				stunnedEnemy = false;
				App->player->snobeeStunned = false;
				timeStunned = 0;
			}
		}
		Enemy::Update();
	}

	



	
	//else if (App->player->destroyed)
	//{
	//	collider->pendingToDelete = true;

	//}

	//Enemy::Update();
}


void Enemy_SnoBee::enemyMovement()
{
	//movement nou

	

	//positionEnemyX = x;
	//positionEnemyY = y;

	if (stunnedEnemy) {
		EnemyToBlock = 0;
	}
	//dirEnemy = rand() % RIGHT + 1; //enemy direction
	if (!App->tilemap->threeDiamonds && !stunnedEnemy) {
		dirEnemy = static_cast<Direction>(rand() % UP + 1);
	}

	if (App->tilemap->spaceToBlock(position.x, position.y, dirEnemy) != 0) {
		EnemyToBlock = rand() % App->tilemap->spaceToBlock(position.x, position.y, dirEnemy)+1;
	}
	else {
		EnemyToBlock = 0;
	}



	if (dirEnemy == LEFT) {
		

		//dirEnemy = LEFT;
		if (App->tilemap->isWalkable(position.x - 16, position.y)) {
			currentAnim = &snoLeftAnim2;
			finalEnemyPositionX = position.x - (EnemyToBlock * 16);
			dirEnemy = LEFT;

		}
	}
	else if (dirEnemy == RIGHT) {
		//dirEnemy = RIGHT;
		if (App->tilemap->isWalkable(position.x + 16, position.y)) {
			currentAnim = &snoRightAnim2;
			finalEnemyPositionX = position.x + (EnemyToBlock * 16);
			dirEnemy = RIGHT;
		}
	}
	else if (dirEnemy == UP) {
		//dirEnemy = UP;
		if (App->tilemap->isWalkable(position.x, position.y-16)) {
			currentAnim = &snoUpAnim2;
			finalEnemyPositionY = position.y - (EnemyToBlock * 16);
			dirEnemy = UP;
		}
	}
	else if (dirEnemy == DOWN) {
		//dirEnemy = DOWN;
		if (App->tilemap->isWalkable(position.x, position.y + 16)) {
			currentAnim = &snoDownAnim2;
			finalEnemyPositionY = position.y + (EnemyToBlock * 16);
			dirEnemy = DOWN;
		}
	
	}




	/*if (dirEnemy != NOMOVE) {


		if (dirEnemy == LEFT) {

			if (positionEnemyX == finalEnemyPositionX) {
				dirEnemy = NOMOVE;
			}
			positionEnemyX--;
			position.x--;
		}

		else if (dirEnemy == RIGHT) {

			if (positionEnemyX == finalEnemyPositionX) {
				dirEnemy = NOMOVE;
			}
			positionEnemyX++;
			position.x++;

		}
		else if (dirEnemy == UP) {

			if (positionEnemyY == finalEnemyPositionY) {
				dirEnemy = NOMOVE;
			}
			positionEnemyY--;
			position.y--;

		}
		else if (dirEnemy == DOWN) {

			if (positionEnemyY == finalEnemyPositionY) {
				dirEnemy = NOMOVE;
			}
			positionEnemyY++;
			position.y++;
		}


	}*/


	// movement antic



	//if (j == 0 && !App->tilemap->threeDiamonds) {
	//	opcio = rand() % 4 + 1;
	//	j++;
	//}
	////while (longer != 0) {
	//if (j < 17) {
	//	j++;
	//}
	//if (j == 17) {
	//	j = 0;
	//}
	////longer--;
	////}


	//if (rep == 16) {
	//	rep = 0;

	//}

	//switch (opcio)
	//{

	//	//case 0:
	//	//	currentAnim = &snoDownAnim2;
	//	//	break;

	//case 1:
	//	currentAnim = &snoLeftAnim2;
	//	break;

	//case 2:
	//	currentAnim = &snoRightAnim2;
	//	break;
	//case 3:
	//	currentAnim = &snoDownAnim2;
	//	break;

	//case 4:
	//	currentAnim = &snoUpAnim2;
	//	break;


	//default:
	//	break;
	//}

	//if (rep == 0) {
	//	if (!destroyedEnemy) {
	//		if (opcio == 1)
	//		{
	//			if (App->tilemap->isWalkable(position.x - 16, position.y)) {
	//				if (currentAnim != &snoLeftAnim)
	//				{
	//					position.x -= move;
	//					opcio = 1;
	//					rep++;

	//				}
	//			}
	//		}
	//		else {

	//			if (opcio == 2)
	//			{
	//				if (App->tilemap->isWalkable(position.x + 16, position.y)) {
	//					if (currentAnim != &snoRightAnim)
	//					{
	//						position.x += move;
	//						opcio = 2;
	//						rep++;

	//					}
	//				}
	//			}
	//			else {
	//				if (opcio == 3)
	//				{
	//					if (App->tilemap->isWalkable(position.x, position.y + 16)) {
	//						if (currentAnim != &snoDownAnim)
	//						{
	//							position.y += move;
	//							opcio = 3;
	//							rep++;

	//						}
	//					}
	//				}

	//				else {
	//					if (opcio == 4)
	//					{
	//						if (App->tilemap->isWalkable(position.x, position.y - 16)) {
	//							if (currentAnim != &snoUpAnim)
	//							{
	//								position.y -= move;
	//								opcio = 4;
	//								rep++;


	//							}

	//						}
	//					}
	//				}

	//			}


	//		}
	//	}
	//}
	//else {


	//	if (!destroyedEnemy) {

	//		if (opcio == 1)
	//		{
	//			position.x -= move;
	//			opcio = 1;
	//			rep++;

	//		}

	//		else {

	//			{
	//				if (opcio == 2)
	//				{
	//					position.x += move;
	//					opcio = 2;
	//					rep++;


	//				}

	//				else {

	//					if (opcio == 3)
	//					{
	//						position.y += move;
	//						opcio = 3;
	//						rep++;


	//					}


	//					else {

	//						if (opcio == 4)
	//						{
	//							position.y -= move;
	//							opcio = 4;

	//							rep++;

	//						}
	//					}


	//				}


	//			}
	//		}



	//	}
	//}
	/*if (!destroyedEnemy) {
		if (App->tilemap->thereIsABlock(position.x, position.y)) {
			destroyedEnemy = true;

		}
	}*/
}


void Enemy_SnoBee::OnCollision(Collider* c2) {

	/*SDL_Rect r = this->collider->rect;


	if (c2->type == Collider::Type::PLAYER)
	{
		if (c2->Intersects(r) == true) {
			collider->pendingToDelete = true;

		}

	}*/
}