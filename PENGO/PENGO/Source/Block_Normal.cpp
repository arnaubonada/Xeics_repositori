#include "Block_Normal.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"

Block_Normal::Block_Normal(int x, int y) : Block(x, y)
{
	//Btexture = App->textures->Load("Assets/Blocks.png");

	//bnormal = SDL_Rect{ 708,0,16,16 };
	//currentAnim = &flyAnim;
	bnormal.PushBack({ 708, 0, 16, 16 });
	currentAnim = &bnormal;


	collider = App->collisions->AddCollider({ 0, 0, 16, 16 }, Collider::Type::ENEMY, (Module*)App->blocks);
}

void Block_Normal::Update()
{

	//App->render->Blit(Btexture, 70, 70, &bnormal);

	/*waveRatio += waveRatioSpeed;

	position.y = spawnPos.y + (waveHeight * sinf(waveRatio));
	position.x -= 1;*/

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Block::Update();
}
