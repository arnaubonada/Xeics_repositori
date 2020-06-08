#ifndef __ENEMY_SNOBEE_H__
#define __ENEMY_SNOBEE_H__

#include "Enemy.h"
#include "Path.h"
#include "time.h"
#include "ModuleTileMap.h"

class Enemy_SnoBee : public Enemy
{
public:
	
	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_SnoBee(int x, int y, enum class ENEMY_TYPE type);
	Enemy_SnoBee() {};

	// The enemy is going to perform a sinusoidal movement
	void Update() override;


	uint snobeeFx = 0;

	uint enemiesAlive = 0;

public:

	Path path;

	void enemyMovement();

	
	void OnCollision(Collider* c2) override;

	enum class ENEMY_TYPE typeEnemy;

	// The enemy animation
	Animation snoUpAnim;
	Animation snoDownAnim;
	Animation snoLeftAnim;
	Animation snoRightAnim;

	Animation snoUpAnim2;
	Animation snoDownAnim2;
	Animation snoLeftAnim2;
	Animation snoRightAnim2;

	Animation stunnedAnim;
	Animation stunnedBlueAnim;


	//Direction direct = NOMOVE;

	Direction dirEnemy;
	// The speed in which we move the player (pixels per frame)
	int move = 1;

	//Where the player goes
	//int opcio = 1;

	//int rep = 0;
	//int longer;

	// A flag to detect when the enemy has been destroyed
	bool destroyedEnemy = false;

	bool stunnedEnemy = false;

	int timeStunned = 0;

	int j = 0;


	int positionEnemyX;
	int positionEnemyY;
	int movedEnemyX;
	int movedEnemyY;

	int EnemyToBlock;

	int finalEnemyPositionX;
	int finalEnemyPositionY;
};

#endif // __ENEMY_SNOBEE_H__