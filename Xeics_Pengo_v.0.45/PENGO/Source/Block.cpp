#include "Block.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleInput.h"



#include "SDL/include/SDL_scancode.h"

char opcio = 'a';

Block::Block(int x, int y) : position(x, y)
{
	/*position.x = 70;
	position.y = 70;*/

	bnormal.PushBack({ 708, 0, 16, 16 });
	bnormal.speed = 0.1f;
	currentAnim = &bnormal;

	collider = App->collisions->AddCollider({ 0, 0, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);

}

Block::~Block()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
}

const Collider* Block::GetCollider() const
{
	return collider;
}

void Block::Update()
{
	/*if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);*/
}

void Block::Draw()
{
	/*if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));*/
}

void Block::OnCollision(Collider* c1)
{

	//if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) {
	//	opcio = 'l';
	//}
	//else {

	//	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	//	{
	//		opcio = 'r';
	//	}
	//	else {
	//		if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	//		{
	//			opcio = 'd';
	//		}

	//		else {
	//			if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	//			{
	//				opcio = 'u';
	//			}
	//		}
	//	}
	//}


	//if (c1 == collider && opcio == 'l')
	//{

	//	position.x = position.x - 1;

	//}


	//if (c1 == collider && opcio == 'r')
	//{
	//	position.x += 1;
	//}


	//if (c1 == collider && opcio == 'd')
	//{

	//	position.y += 1;

	//}


	//if (c1 == collider && opcio == 'u')
	//{
	//	position.y -= 1;

	//}

	//
	//


	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->audio->PlayFx(destroyedFx);

	SetToDelete();
}

void Block::SetToDelete()
{
	pendingToDelete = true;
	if (collider != nullptr)
		collider->pendingToDelete = true;
}