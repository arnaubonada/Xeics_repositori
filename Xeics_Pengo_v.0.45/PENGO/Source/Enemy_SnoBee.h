#ifndef __ENEMY_SNOBEE_H__
#define __ENEMY_SNOBEE_H__

#include "Enemy.h"
#include "Path.h"
#include "time.h"
#include "ModuleTileMap.h"
#include "Particle.h"

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

	//uint enemiesAlive = 0;

	//bool enemiesStunned[10]{ false,false,false,false,false,false,false,false,false,false };

public:

	Path path;

	void enemyMovement();
	
	void OnCollision(Collider* c1, Collider* c2) override;

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

	Animation normalSnoUpAnim;
	Animation normalSnoDownAnim;
	Animation normalSnoLeftAnim;
	Animation normalSnoRightAnim;

	Animation dragEnemyLeftAnim;
	Animation dragEnemyRightAnim;
	Animation dragEnemyUpAnim;
	Animation dragEnemyDownAnim;

	Animation firstSmashLeftAnim;
	Animation firstSmashRightAnim;
	Animation firstSmashUpAnim;
	Animation firstSmashDownAnim;

	Animation secondSmashLeftAnim;
	Animation secondSmashRightAnim;
	Animation secondSmashUpAnim;
	Animation secondSmashDownAnim;
		
	Animation stunnedAnim;
	Animation stunnedBlueAnim;


	Particle oneHundredParticle;

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

	bool smashedEnemy = false;

	bool randfinish = false;

	int timeStunned = 0;
	int lastTimeStunned = 0;

	bool DiamondFinished = false;

	int j = 0;


	int positionEnemyX;
	int positionEnemyY;
	int movedEnemyX;
	int movedEnemyY;

	int EnemyToBlock;
	int EnemyToWall;


	int finalEnemyPositionX;
	int finalEnemyPositionY;
};

#endif // __ENEMY_SNOBEE_H__