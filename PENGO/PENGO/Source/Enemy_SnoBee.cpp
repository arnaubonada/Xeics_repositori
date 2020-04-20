#include "Enemy_SnoBee.h"

#include "Application.h"
#include "ModuleCollisions.h"
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

	collider = App->collisions->AddCollider({ 0, 0, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_SnoBee::Update()
{
	srand(time(NULL));
	direction = rand() % 4;
	switch (direction)
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

	Enemy::Update();
}
