#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModuleScene.h"

#include <stdio.h>

#include "SDL/include/SDL_scancode.h"



ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	name = "player";

	// move up
	upAnim2.PushBack({ 64, 0, 16, 16 });
	upAnim2.PushBack({ 80, 0, 16, 16 });
	upAnim2.speed = 0.1f;

	// Move down
	downAnim2.PushBack({ 0, 0, 16, 16 });
	downAnim2.PushBack({ 16, 0, 16, 16 });
	downAnim2.speed = 0.1f;

	// move left
	leftAnim2.PushBack({ 32, 0, 16, 16 });
	leftAnim2.PushBack({ 48, 0, 16, 16 });
	leftAnim2.speed = 0.1f;

	// Move right
	rightAnim2.PushBack({ 96, 0, 16, 16 });
	rightAnim2.PushBack({ 112, 0, 16, 16 });
	rightAnim2.speed = 0.1f;




	// move up
	upAnim.PushBack({ 64, 0, 16, 16 });
	upAnim.PushBack({ 80, 0, 16, 16 });
	upAnim.speed = 0.1f;

	// Move down
	downAnim.PushBack({ 0, 0, 16, 16 });
	downAnim.PushBack({ 16, 0, 16, 16 });
	downAnim.speed = 0.1f;

	// move left
	leftAnim.PushBack({ 32, 0, 16, 16 });
	leftAnim.PushBack({ 48, 0, 16, 16 });
	leftAnim.speed = 0.1f;

	// Move right
	rightAnim.PushBack({ 96, 0, 16, 16 });
	rightAnim.PushBack({ 112, 0, 16, 16 });
	rightAnim.speed = 0.1f;

	deadAnim.PushBack({ 0, 32, 16, 16 });
	deadAnim.PushBack({ 16, 32, 16, 16 });
	deadAnim.speed = 0.1f;

}




ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Characters.png");
	currentAnimation = &downAnim;

	position.x = 104;
	position.y = 128;


	/*laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");*/

	collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::PLAYER, this);
	destroyed = false;



	char lookupTable[] = { "0123456789.,&!'-�abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	blueFont = App->fonts->Load("Assets/blueFont.png", lookupTable, 3);
	return ret;
}

update_status ModulePlayer::Update()
{

	if (k == 16) {
		k = 0;
	}

	switch (opcio)
	{

	case 'a':
		currentAnimation = &downAnim2;
		break;

	case 'l':
		currentAnimation = &leftAnim2;
		break;

	case 'r':
		currentAnimation = &rightAnim2;
		break;
	case 'd':
		currentAnimation = &downAnim2;
		break;

	case 'u':
		currentAnimation = &upAnim2;
		break;


	default:
		break;
	}

	if (k == 0) {
		if (!destroyed) {
			if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				if (currentAnimation != &leftAnim)
				{
					position.x -= move;
					opcio = 'l';
					k++;
				}
			}
			else {

				if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					if (currentAnimation != &rightAnim)
					{
						position.x += move;
						opcio = 'r';
						k++;


					}
				}
				else {
					if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
					{
						if (currentAnimation != &downAnim)
						{
							position.y += move;
							opcio = 'd';
							k++;


						}
					}

					else {
						if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
						{
							if (currentAnimation != &upAnim)
							{
								position.y -= move;
								opcio = 'u';

								k++;

							}
						}
					}

				}


			}
		}
	}
	else {


		if (!destroyed) {

			if (opcio == 'l')
			{
				position.x -= move;
				opcio = 'l';
				k++;

			}

			else {

				{
					if (opcio == 'r')
					{
						position.x += move;
						opcio = 'r';
						k++;


					}

					else {

						if (opcio == 'd')
						{
							position.y += move;
							opcio = 'd';
							k++;


						}


						else {

							if (opcio == 'u')
							{
								position.y -= move;
								opcio = 'u';

								k++;

							}
						}


					}


				}
			}



		}
	}
	collider->SetPos(position.x, position.y);
	if (position.x == 104 && position.y == 32) {
		score = 1;
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneWin, 60);
	}
	currentAnimation->Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	if (!destroyed)
	{
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	if (destroyed) {
		currentAnimation = &deadAnim;
		rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}
	sprintf_s(scoreText, 10, "%d", score);

	App->fonts->BlitText(64, 0, whiteFont, scoreText);
	App->fonts->BlitText(136, 280, whiteFont, "� sega 1982");
	App->fonts->BlitText(8, 280, whiteFont, "act 1");
	App->fonts->BlitText(8, 0, blueFont, "1p");
	App->fonts->BlitText(80, 0, blueFont, "hi");
	App->fonts->BlitText(104, 0, whiteFont, "20000");
	App->fonts->BlitText(152, 0, blueFont, "2p");
	App->fonts->BlitText(208, 0, whiteFont, "0");

	return update_status::UPDATE_CONTINUE;
}


bool ModulePlayer::CleanUp()
{
	activeTextures = activeColliders = activeFonts = activeFx = 0;

	// TODO 1: Remove ALL remaining resources. Update resource count properly

	App->textures->Unload(texture);
	--totalTextures;

	App->audio->UnloadFx(laserFx);
	--totalFx;

	App->audio->UnloadFx(explosionFx);
	--totalFx;

	App->collisions->RemoveCollider(collider);
	--totalColliders;

	App->fonts->UnLoad(whiteFont);
	--totalFonts;
	
	App->fonts->UnLoad(blueFont);
	--totalFonts;

	return true;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == Collider::Type::PLAYER) {

		//if (c2 == App->scene->leftWall) {
		//	position.x = 8;
		//}
		//if (c2 == App->scene->rightWall) {
		//	position.x = 200;
		//}
		//if (c2 == App->scene->bottomWall) {
		//	position.y = 256;
		//}
		//if (c2 == App->scene->topWall) {
		//	position.y = 32;
		//}
		if (c2->type == Collider::Type::ENEMY)
		{
			destroyed = true;
			c1->pendingToDelete = true;
			c2->pendingToDelete = true;
			lifes--;

		}
	/*	if (c2->type == Collider::Type::BLOCK && opcio == 'l')
		{
			position.x += move;

		}
		if (c2->type == Collider::Type::BLOCK && opcio == 'r')
		{
			position.x -= move;

		}if (c2->type == Collider::Type::BLOCK && opcio == 'd')
		{
			position.y -= move;

		}
		if (c2->type == Collider::Type::BLOCK && opcio == 'u')
		{
			position.y += move;

		}*/
	}













	//if (c1 == collider && opcio == 'l')
	//{
	//
	//	position.x += move;
	//	//collidatoL = true;

	//}


	//if (c1 == collider && opcio == 'r')
	//{

	//	position.x -= move;
	//	//collidatoR = true;
	//}


	//if (c1 == collider && opcio == 'd')
	//{

	//	position.y -= move;
	//	//collidatoD = true;

	//}


	//if (c1 == collider && opcio == 'u')
	//{
	//	position.y += move;
	//	//collidatoU = true;

	//}


	//collider->SetPos(position.x, position.y);




	//App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneIntro, 60);

	//App->audio->PlayFx(explosionFx);
	//destroyed = true;

}

//void ModulePlayer::OnCollision2(Collider* c1, Collider* c2)
//{
//	if (c1 == collider && c2 == )
//	{
//		//App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneIntro, 60);
//
//		App->audio->PlayFx(explosionFx);
//		destroyed = true;
//	}
//
//}