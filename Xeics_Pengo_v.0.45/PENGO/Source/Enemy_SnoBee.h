#ifndef __ENEMY_SNOBEE_H__
#define __ENEMY_SNOBEE_H__

#include "Enemy.h"
#include "Path.h"
#include "time.h"

class Enemy_SnoBee : public Enemy
{
public:
	
	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_SnoBee(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment
	float waveRatio = 0.0f;

	// The speed at which the wave ratio is increased
	float waveRatioSpeed = 0.05f;

	// The original spawning position. The wave will be calculated from that
	int spawn_y = 0;

	

	int moveE = 1;
	
	void OnCollision(Collider* c2) override;
	// The total height of the wave
	int waveHeight = 15;

	Path path;

	// The enemy animation
	Animation snoUpAnim;
	Animation snoDownAnim;
	Animation snoLeftAnim;
	Animation snoRightAnim;
};

#endif // __ENEMY_SNOBEE_H__