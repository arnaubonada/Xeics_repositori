#include "Enemy_SnoBee.h"

#include "Application.h"
#include "ModuleScene.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "time.h"



Enemy_SnoBee::Enemy_SnoBee(int x, int y) : Enemy(x, y)
{
	

	//// idle animation (arcade sprite sheet)
	//idleAnim.PushBack({ 0, 0, 16, 16 });
	//idleAnim.PushBack({ 16, 0, 16, 16 });
	////upAnim.loop = false;
	//idleAnim.speed = 0.1f;


	// move up
	snoUpAnim.PushBack({ 64, 160, 16, 16 });
	snoUpAnim.PushBack({ 80, 160, 16, 16 });
	snoUpAnim.speed = 0.1f;
	currentAnim = &snoUpAnim;

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


	//currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_SnoBee::Update()
{
	
	switch (App->enemies->RandomDirection())
	{
	case 0:
		position.x += 1;
		break;
	case 1:
		position.x -= 1;
		break;
	case 2:
		position.y += 1;
		break;
	case 3:
		position.y -= 1;
		break;
	case 4:
		position.x = position.x;
		position.y = position.y;
		break;
	default:
		break;
	}

	if (App->player->destroyed)
	{

		collider->pendingToDelete = true;
	}

	Enemy::Update();
}

void Enemy_SnoBee::OnCollision(Collider* c2) {

		SDL_Rect r = this->collider->rect;

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

		}
	}