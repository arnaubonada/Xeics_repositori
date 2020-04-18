#ifndef __BLOCK_NORMAL_H__
#define __BLOCK_NORMAL_H__

#include "Block.h"
#include "Path.h"

class Block_Normal : public Block
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Block_Normal(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment
	float waveRatio = 0.0f;

	// The speed at which the wave ratio is increased
	float waveRatioSpeed = 0.05f;

	// The original spawning position. The wave will be calculated from that
	int spawn_y = 0;

	// The total height of the wave
	int waveHeight = 15;

	Path path;

	// The enemy animation
	//SDL_Texture* Btexture = nullptr;
	//SDL_Rect bnormal;

	Animation bnormal;
};

#endif // __BLOCK_NORMAL_H__