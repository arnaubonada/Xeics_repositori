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

	normalSnoUpAnim.PushBack({ 64, 144, 16, 16 });
	normalSnoUpAnim.PushBack({ 80, 144, 16, 16 });
	normalSnoUpAnim.speed = 0.1f;

	normalSnoDownAnim.PushBack({ 0, 144, 16, 16 });
	normalSnoDownAnim.PushBack({ 16, 144, 16, 16 });
	normalSnoDownAnim.speed = 0.1f;

	normalSnoLeftAnim.PushBack({ 32, 144, 16, 16 });
	normalSnoLeftAnim.PushBack({ 48, 144, 16, 16 });
	normalSnoLeftAnim.speed = 0.1f;

	normalSnoRightAnim.PushBack({ 96, 144, 16, 16 });
	normalSnoRightAnim.PushBack({ 112, 144, 16, 16 });
	normalSnoRightAnim.speed = 0.1f;

	stunnedAnim.PushBack({ 96, 128, 16, 16 });
	stunnedAnim.PushBack({ 112, 128, 16, 16 });
	stunnedAnim.speed = 0.1f;
	
	stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
	stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
	stunnedBlueAnim.PushBack({ 96, 128, 16, 16 });
	stunnedBlueAnim.PushBack({ 112, 128, 16, 16 });
	stunnedBlueAnim.speed = 0.1f;


	dragEnemyLeftAnim.PushBack({ 96, 144, 16, 16 });
	dragEnemyLeftAnim.speed = 0.1f;

	dragEnemyRightAnim.PushBack({ 32, 144, 16, 16 });
	dragEnemyRightAnim.speed = 0.1f;

	dragEnemyUpAnim.PushBack({ 0, 144, 16, 16 });
	dragEnemyUpAnim.speed = 0.1f;

	dragEnemyDownAnim.PushBack({ 64, 144, 16, 16 });
	dragEnemyDownAnim.speed = 0.1f;

	firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
	firstSmashLeftAnim.speed = 0.1f;
	
	firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
	firstSmashRightAnim.speed = 0.1f;
	
	firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
	firstSmashUpAnim.speed = 0.1f;
	
	firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
	firstSmashDownAnim.speed = 0.1f;
	
	secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
	secondSmashLeftAnim.speed = 0.1f;

	secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
	secondSmashRightAnim.speed = 0.1f;
	
	secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
	secondSmashUpAnim.speed = 0.1f;
	
	secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
	secondSmashDownAnim.speed = 0.1f;

	currentAnim = &snoDownAnim;

	if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER)
	{
		collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
		currentAnim = &snoDownAnim;
	}
	else if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL)
	{
		collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
		currentAnim = &normalSnoDownAnim;
	}
}




void Enemy_SnoBee::Update()
{
	if (!App->player->destroyed) {
		if (!App->tilemap->threeDiamonds) {
			if (stunnedEnemy) {
				dirEnemy = NOMOVE;
			}
			if (randfinish) {
				dirEnemy = NOMOVE;
			}
		if (dirEnemy == NOMOVE ) {
			enemyMovement();
		}

		if (dirEnemy != NOMOVE) {


			if (dirEnemy == LEFT) {
				if (App->tilemap->isWalkable(position.x - 1, position.y)) {
					
					/*if (position.x % 2 != 0 && position.x - 1 == finalEnemyPositionX) {
						position.x--;
					}*/
					position.x--;
					if (position.x == finalEnemyPositionX) {
						dirEnemy = NOMOVE;

					}
					//positionEnemyX--;
					

				}
				else {
					randfinish = true;
				}
				
			}

			else if (dirEnemy == RIGHT) {
				if (App->tilemap->isWalkable(position.x + 16, position.y)) {
					
					/*if (position.x % 2 != 0 && position.x + 1 == finalEnemyPositionX) {
						position.x++;
					}*/
					position.x++;
					if (position.x == finalEnemyPositionX) {
						dirEnemy = NOMOVE;
					}
					
					//	positionEnemyX++;
				}
				else {
					randfinish = true;
				}
				
			}
			else if (dirEnemy == UP) {
				if (App->tilemap->isWalkable(position.x, position.y - 1)) {
					
					/*if (position.y % 2 != 0 && position.y - 1 == finalEnemyPositionY) {
						position.y--;
					}*/
					position.y--;
					if (position.y == finalEnemyPositionY) {
						dirEnemy = NOMOVE;
					}
					
					//positionEnemyY--;

				}
				else {
					randfinish = true;
				}
			}
			else if (dirEnemy == DOWN) {
				if (App->tilemap->isWalkable(position.x, position.y + 16)) {
					
					/*if (position.y % 2 != 0 && position.y + 1 == finalEnemyPositionY) {
						position.y++;
					}*/
					position.y++;
					if (position.y == finalEnemyPositionY) {
						dirEnemy = NOMOVE;
					}
					//positionEnemyY++;
					
				}
				
				else {
					randfinish = true;
				}
				}
			}
		}
		/*LOG("Pos x: %d", position.x);
		LOG("Pos y: %d", position.y);*/

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
		if (!App->tilemap->threeDiamondsDone) {
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
					//App->tilemap->threeDiamondsFinish = true;
					//	}
				}
			}
		}



		if (App->tilemap->threeDiamondsDone && !DiamondFinished)
		{
			if (App->tilemap->timeDiamondStunned != 0) {
				//currentAnim = &stunnedAnim;
				stunnedEnemy = true;
				App->tilemap->timeDiamondStunned++;
				App->player->snobeeStunned = true;
				/*if (App->tilemap->timeDiamondStunned < 300 && App->tilemap->timeDiamondStunned>120) {
					currentAnim = &stunnedBlueAnim;
				}*/
				if (App->tilemap->timeDiamondStunned > 900 && App->tilemap->timeDiamondStunned < 1200) {
					currentAnim = &stunnedAnim;
					stunnedEnemy = false;
					App->player->snobeeStunned = false;
					//App->tilemap->timeDiamondStunned = 1;
					if (lastTimeStunned == 0) {
						lastTimeStunned = 1;
					}
					App->tilemap->threeDiamondsFinish = true;
					//	}
				}

			}
		}



		if (App->tilemap->threeDiamondsFinish) {
			if (lastTimeStunned != 0) {
				App->scene->timescore = 1;
				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;

				stunnedEnemy = true;
				App->player->snobeeStunned = true;
				lastTimeStunned++;
				if (lastTimeStunned < 300 && lastTimeStunned>120) {
					currentAnim = &stunnedBlueAnim;
				}
				if (lastTimeStunned > 300) {
					stunnedEnemy = false;
					App->player->snobeeStunned = false;
					lastTimeStunned = 0;
					DiamondFinished = true;
					//	}
				}
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
		EnemyToWall = 0;

	}
	//dirEnemy = rand() % RIGHT + 1; //enemy direction
	if (!App->tilemap->threeDiamonds && !stunnedEnemy ) {
		dirEnemy = static_cast<Direction>(rand() % UP + 1);
	}

	if (App->tilemap->spaceToBlock(position.x, position.y, dirEnemy) != 0) {
		EnemyToBlock = rand() % App->tilemap->spaceToBlock(position.x, position.y, dirEnemy)+1;
	}
	else {
		EnemyToBlock = 0;
	}
	if (App->tilemap->spaceToWall(position.x, position.y, dirEnemy) != 0) {
		EnemyToWall = rand() % App->tilemap->spaceToWall(position.x, position.y, dirEnemy);
	}

	LOG("dirEnemy: %d", dirEnemy);
	
	
	LOG("Enemy to block: %d", EnemyToBlock);


	if (dirEnemy == LEFT) {

		if (App->tilemap->isWalkable(position.x - 1, position.y)) {
			//dirEnemy = LEFT;

			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoLeftAnim;
			}
			if (position.x % 16 == 0) {
				finalEnemyPositionX = position.x - (EnemyToBlock * 16);
				dirEnemy = LEFT;
			}
		}
		if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
			currentAnim = &snoLeftAnim2;

			if (App->tilemap->thereIsABlock(position.x - 1, position.y))
			{

				App->tilemap->DestroyBlock(position.x - 16, position.y);
				if (App->tilemap->destroyedAnimBlock) {
					currentAnim = &snoLeftAnim2;

				}
			}

			/*if (position.x % 16 == 0) {
			finalEnemyPositionX = position.x - (EnemyToWall * 16);
			dirEnemy = LEFT;
			}*/

		}

	}
	else if (dirEnemy == RIGHT) {
		//dirEnemy = RIGHT;
		if (App->tilemap->isWalkable(position.x + 16, position.y)) {
			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoRightAnim;
			}
			if (position.x % 16 == 0) {
				finalEnemyPositionX = position.x + (EnemyToBlock * 16);
				dirEnemy = RIGHT;
			}
		}
		if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
			currentAnim = &snoRightAnim2;

			if (App->tilemap->thereIsABlock(position.x + 16, position.y))
			{
				App->tilemap->DestroyBlock(position.x + 16, position.y);
				if (App->tilemap->destroyedAnimBlock) {
					currentAnim = &snoRightAnim2;

				}
			}

			/*if (position.x % 16 == 0) {
				finalEnemyPositionX = position.x - (EnemyToWall * 16);
				dirEnemy = RIGHT;
			}*/

		}
	}
	else if (dirEnemy == UP) {
		//dirEnemy = UP;
		if (App->tilemap->isWalkable(position.x, position.y - 1)) {

			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoUpAnim;
			}
			if (position.y % 16 == 0) {
				finalEnemyPositionY = position.y - (EnemyToBlock * 16);
				dirEnemy = UP;
			}
			if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
				currentAnim = &snoUpAnim2;

				if (App->tilemap->thereIsABlock(position.x, position.y - 1))
				{
					App->tilemap->DestroyBlock(position.x, position.y - 16);
					if (App->tilemap->destroyedAnimBlock) {
						currentAnim = &snoUpAnim2;

					}
				}

				/*if (position.x % 16 == 0) {
					finalEnemyPositionX = position.x - (EnemyToWall * 16);
					dirEnemy = UP;
				}*/

			}

		}
	}
	else if (dirEnemy == DOWN) {
		//dirEnemy = DOWN;
		if (App->tilemap->isWalkable(position.x, position.y + 16)) {

			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoDownAnim;
			}
			if (position.y % 16 == 0) {
				finalEnemyPositionY = position.y + (EnemyToBlock * 16);
				dirEnemy = DOWN;
			}
		}
		if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
			currentAnim = &snoDownAnim2;

			if (App->tilemap->thereIsABlock(position.x, position.y + 16))
			{
				App->tilemap->DestroyBlock(position.x, position.y + 16);
				if (App->tilemap->destroyedAnimBlock) {
					currentAnim = &snoDownAnim2;

				}
			}

			/*if (position.x % 16 == 0) {
				finalEnemyPositionX = position.x - (EnemyToWall * 16);
				dirEnemy = DOWN;
			}*/

		}



	}

	randfinish = false;

	LOG("Final x: %d", finalEnemyPositionX);
	LOG("Final y: %d", finalEnemyPositionY);


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

	SDL_Rect r = this->collider->rect;


	if (c2->type == Collider::Type::BLOCK)
	{
		if (c2->Intersects(r) == true) {
			App->tilemap->collider->pendingToDelete = true;
			if (App->tilemap->dirBlock == LEFT) {
				smashedEnemy = true;
				position.x = App->tilemap->positionBlock.x - 16;
				currentAnim = &dragEnemyLeftAnim;
				if (App->tilemap->positionBlock.x <= (App->tilemap->finalpositionX + 16) && App->tilemap->positionBlock.x > App->tilemap->finalpositionX) {
					currentAnim = &firstSmashLeftAnim;
				}
				if (App->tilemap->positionBlock.x > App->tilemap->finalpositionX) {
					currentAnim = &secondSmashLeftAnim;
				}
			}
			else if (App->tilemap->dirBlock == RIGHT) {
				smashedEnemy = true;
				position.x = App->tilemap->positionBlock.x + 16;
				currentAnim = &dragEnemyRightAnim;
				if (App->tilemap->positionBlock.x <= (App->tilemap->finalpositionX - 16) && App->tilemap->positionBlock.x > App->tilemap->finalpositionX) {
					currentAnim = &firstSmashRightAnim;
				}
				if (App->tilemap->positionBlock.x > App->tilemap->finalpositionX) {
					currentAnim = &secondSmashRightAnim;
				}
				
			}
			else if (App->tilemap->dirBlock == UP) {
				smashedEnemy = true;
				position.y = App->tilemap->positionBlock.y - 16;
				currentAnim = &dragEnemyUpAnim;
				if (App->tilemap->positionBlock.y <= (App->tilemap->finalpositionY + 16) && App->tilemap->positionBlock.y > App->tilemap->finalpositionY) {
					currentAnim = &firstSmashUpAnim;
				}
				if (App->tilemap->positionBlock.y > App->tilemap->finalpositionY) {
					currentAnim = &secondSmashUpAnim;
				}
				
			}
			else if (App->tilemap->dirBlock == DOWN) {
				smashedEnemy = true;
				position.y = App->tilemap->positionBlock.y + 16;
				currentAnim = &dragEnemyDownAnim;
				if (App->tilemap->positionBlock.y <= (App->tilemap->finalpositionY - 16) && App->tilemap->positionBlock.y > App->tilemap->finalpositionY) {
					currentAnim = &firstSmashDownAnim;
				}
				if (App->tilemap->positionBlock.y > App->tilemap->finalpositionY) {
					currentAnim = &secondSmashDownAnim;
				}
				
			}
		}

	}

	if (c2->type == Collider::Type::PLAYER)
	{
		if (c2->Intersects(r) == true && stunnedEnemy == true) {
			App->player->scoreOneHundred = true;
		}
	}
}