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
#include "ModuleEnemies.h"
#include "Enemy_SnoBee.h"
#include "ModuleTileMap.h"
#include "ModuleParticles.h"

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
	deadAnim.PushBack({ 0, 32, 16, 16 });
	deadAnim.PushBack({ 16, 32, 16, 16 });
	deadAnim.speed = 0.1f;

	upPushAnim.PushBack({ 64, 16, 16, 16 });
	upPushAnim.PushBack({ 80, 16, 16, 16 });
	upPushAnim.PushBack({ 64, 16, 16, 16 });
	upPushAnim.PushBack({ 80, 16, 16, 16 });
	upPushAnim.loop = false;
	upPushAnim.speed = 0.1f;

	downPushAnim.PushBack({ 0, 16, 16, 16 });
	downPushAnim.PushBack({ 16, 16, 16, 16 });
	downPushAnim.PushBack({ 0, 16, 16, 16 });
	downPushAnim.PushBack({ 16, 16, 16, 16 });
	downPushAnim.loop = false;
	downPushAnim.speed = 0.1f;

	leftPushAnim.PushBack({ 32, 16, 16, 16 });
	leftPushAnim.PushBack({ 48, 16, 16, 16 });
	leftPushAnim.PushBack({ 32, 16, 16, 16 });
	leftPushAnim.PushBack({ 48, 16, 16, 16 });
	leftPushAnim.loop = false;
	leftPushAnim.speed = 0.1f;

	rightPushAnim.PushBack({ 96, 16, 16, 16 });
	rightPushAnim.PushBack({ 112, 16, 16, 16 });
	rightPushAnim.PushBack({ 96, 16, 16, 16 });
	rightPushAnim.PushBack({ 112, 16, 16, 16 });
	rightPushAnim.loop = false;
	rightPushAnim.speed = 0.1f;
	
	upShortPushAnim.PushBack({ 64, 16, 16, 16 });
	upShortPushAnim.PushBack({ 80, 16, 16, 16 });
	upShortPushAnim.loop = false;
	upShortPushAnim.speed = 0.1f;

	downShortPushAnim.PushBack({ 0, 16, 16, 16 });
	downShortPushAnim.PushBack({ 16, 16, 16, 16 });
	downShortPushAnim.loop = false;
	downShortPushAnim.speed = 0.1f;

	leftShortPushAnim.PushBack({ 32, 16, 16, 16 });
	leftShortPushAnim.PushBack({ 48, 16, 16, 16 });
	leftShortPushAnim.loop = false;
	leftShortPushAnim.speed = 0.1f;

	rightShortPushAnim.PushBack({ 96, 16, 16, 16 });
	rightShortPushAnim.PushBack({ 112, 16, 16, 16 });
	rightShortPushAnim.loop = false;
	rightShortPushAnim.speed = 0.1f;
	


	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.PushBack({ 0,0,16,16 });
	oneHundredParticle.anim.speed = 0.1f;
	oneHundredParticle.anim.loop = false;

}




ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	snobeeFx = App->audio->LoadFx("Assets/Audio/snobeekill.wav");
	destroyBlockFx= App->audio->LoadFx("Assets/Audio/Ice Block Destroyed.wav");
	pushBlockFx= App->audio->LoadFx("Assets/Audio/Push Ice Block.wav");
	pushWallFx= App->audio->LoadFx("Assets/Audio/Push Outside Walls.wav");

	texture = App->textures->Load("Assets/Characters.png");
	++activeTextures; ++totalTextures;
	currentAnimation = &downAnim;

	position.x = 112;
	position.y = 128;
	rep = 0;
	//position.x = 176;
	//position.y = 64;

	/*laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");*/

	collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::PLAYER, this);
	++activeColliders; ++totalColliders;
	destroyed = false;



	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;



	return ret;
}

update_status ModulePlayer::Update()
{

	GamePad& pad = App->input->pads[0];

	if (!Collide) {
		App->collisions->RemoveCollider(collider);
		--totalColliders;
	}
	

	if (rep == 16) {
		rep = 0;
	}

	//Debug key for gamepad rumble testing purposes
	if (App->input->keys[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
	{
		App->input->ShakeController(0, 12, 0.33f);
	}

	//Debug key for gamepad rumble testing purposes
	if (App->input->keys[SDL_SCANCODE_2] == KEY_STATE::KEY_DOWN)
	{
		App->input->ShakeController(0, 36, 0.66f);
	}

	//Debug key for gamepad rumble testing purposes
	if (App->input->keys[SDL_SCANCODE_3] == KEY_STATE::KEY_DOWN)
	{
		App->input->ShakeController(0, 60, 1.0f);
	}

	if (rep == 0) {
		if (!destroyed) {
			if (!animDone) {
			if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || pad.left == true)
			{
				currentAnimation = &leftAnim2;
				opcio = 'l';
				if (App->tilemap->isWalkable(position.x - 16, position.y)) {

					if (currentAnimation != &leftAnim)
					{
						
						//App->tilemap->tilemap[(position.y - 16) / 16][(position.x / 16)] = TILE_NOBLOCK;
						position.x -= move;
						rep++;
					}
				}
			}
			else {
				if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || pad.right == true)
				{
					currentAnimation = &rightAnim2;
					opcio = 'r';
					if (App->tilemap->isWalkable(position.x + 16, position.y)) {
						if (currentAnimation != &rightAnim)
						{
							//App->tilemap->tilemap[(position.y - 16) / 16][(position.x / 16)]  = TILE_NOBLOCK;
							position.x += move;
							rep++;

						}
					}
				}
				else {
					if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || pad.down == true)
					{
						currentAnimation = &downAnim2;
						opcio = 'd';

						if (App->tilemap->isWalkable(position.x, position.y + 16)) {

							if (currentAnimation != &downAnim)
							{
								//App->tilemap->tilemap[((position.y - 16) / 16)][position.x / 16] = TILE_NOBLOCK;
								position.y += move;
								rep++;

							}
						}
					}

					else {
						if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || pad.up == true)
						{
							currentAnimation = &upAnim2;
							opcio = 'u';

							if (App->tilemap->isWalkable(position.x, position.y - 16)) {

								if (currentAnimation != &upAnim)
								{
									//App->tilemap->tilemap[((position.y - 16) / 16)][position.x / 16] = TILE_NOBLOCK;								
									position.y -= move;
									rep++;

								}
							}
						}
					}

				}
			}


			}
		}
	}
	else {


		if (!destroyed && !App->tilemap->threeDiamonds) {

			if (opcio == 'l')
			{
				position.x -= move;
				opcio = 'l';
				rep++;

			}

			else {

				{
					if (opcio == 'r')
					{
						position.x += move;
						opcio = 'r';
						rep++;


					}

					else {

						if (opcio == 'd')
						{
							position.y += move;
							opcio = 'd';
							rep++;


						}


						else {

							if (opcio == 'u')
							{
								position.y -= move;
								opcio = 'u';

								rep++;

							}
						}


					}


				}
			}



		}
	}
	collider->SetPos(position.x, position.y);


	int posBlock = 1;

	if (!destroyed && !App->tilemap->threeDiamonds) {
		if (App->input->keys[SDL_SCANCODE_W] != KEY_STATE::KEY_DOWN && App->input->keys[SDL_SCANCODE_D] != KEY_STATE::KEY_DOWN && App->input->keys[SDL_SCANCODE_S] != KEY_STATE::KEY_DOWN && App->input->keys[SDL_SCANCODE_A] != KEY_STATE::KEY_DOWN) {
		
			if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || pad.a == true)
		{
			
				if (opcio == 'l')
				{
					if (App->tilemap->thereIsABlock(position.x - 1, position.y))
					{
						currentAnimation = &leftPushAnim;
						animDone = true;

						if (App->tilemap->thereIsABlock(position.x - 32, position.y) || App->tilemap->thereIsAWall(position.x - 32, position.y) || App->tilemap->thereIsADiamond(position.x - 32, position.y))
						{
							

							App->tilemap->DestroyBlock(position.x - 16, position.y);
							App->audio->PlayFx(destroyBlockFx, 0);

							score += 30;

						}
						else {
							currentAnimation = &leftShortPushAnim;
							App->tilemap->MoveBlock(position.x - 16, position.y, LEFT);
							App->audio->PlayFx(pushBlockFx, 0);

						}


					}
					else if (App->tilemap->thereIsADiamond(position.x - 16, position.y))
					{
						currentAnimation = &leftShortPushAnim;
						animDone = true;
						if (!App->tilemap->thereIsABlock(position.x - 32, position.y) || !App->tilemap->thereIsAWall(position.x - 32, position.y) || !App->tilemap->thereIsADiamond(position.x - 32, position.y))
						{
							App->tilemap->MoveDiamond(position.x - 16, position.y, LEFT);
							App->audio->PlayFx(pushBlockFx, 0);
						}
					}
					else if (App->tilemap->thereIsAWall(position.x - 1, position.y))
					{
						currentAnimation = &leftPushAnim;
						animDone = true;
						App->tilemap->PushLeftWall();
						App->audio->PlayFx(pushWallFx, 0);
					}
				}
				if (opcio == 'r')
				{
					if (App->tilemap->thereIsABlock(position.x + 16, position.y))
					{
						
						animDone = true;
						if (App->tilemap->thereIsABlock(position.x + 32, position.y) || App->tilemap->thereIsAWall(position.x + 32, position.y) || App->tilemap->thereIsADiamond(position.x + 32, position.y))
						{
							currentAnimation = &rightPushAnim;
							App->tilemap->DestroyBlock(position.x + 16, position.y);
							App->audio->PlayFx(destroyBlockFx, 0);
							score += 30;
						}
						else {
							currentAnimation = &rightShortPushAnim;
							App->tilemap->MoveBlock(position.x + 16, position.y, RIGHT);
							App->audio->PlayFx(pushBlockFx, 0);
						}

					}
					else if (App->tilemap->thereIsADiamond(position.x + 16, position.y))
					{
						currentAnimation = &rightShortPushAnim;
						animDone = true;
						if (!App->tilemap->thereIsABlock(position.x + 32, position.y) || !App->tilemap->thereIsAWall(position.x + 32, position.y) || !App->tilemap->thereIsADiamond(position.x + 32, position.y))
						{
							App->tilemap->MoveDiamond(position.x + 16, position.y, RIGHT);
							App->audio->PlayFx(pushBlockFx, 0);
						}
					}
					else if (App->tilemap->thereIsAWall(position.x + 16, position.y))
					{
						currentAnimation = &rightPushAnim;
						animDone = true;
						App->tilemap->PushRightWall();
						App->audio->PlayFx(pushWallFx, 0);
					}
				}
				if (opcio == 'u')
				{
					if (App->tilemap->thereIsABlock(position.x, position.y - 1))
					{
						
						animDone = true;
						if (App->tilemap->thereIsABlock(position.x, position.y - 32) || App->tilemap->thereIsAWall(position.x, position.y - 32) || App->tilemap->thereIsADiamond(position.x, position.y - 32))
						{
							currentAnimation = &upPushAnim;
							App->tilemap->DestroyBlock(position.x, position.y - 16);
							App->audio->PlayFx(destroyBlockFx, 0);
							score += 30;
						}
						else {
							currentAnimation = &upShortPushAnim;
							App->tilemap->MoveBlock(position.x, position.y - 16, UP);
							App->audio->PlayFx(pushBlockFx, 0);
						}
					}

					else if (App->tilemap->thereIsADiamond(position.x, position.y - 16))
					{
						currentAnimation = &upShortPushAnim;
						animDone = true;
						if (!App->tilemap->thereIsABlock(position.x, position.y - 32) || !App->tilemap->thereIsAWall(position.x, position.y - 32) || !App->tilemap->thereIsADiamond(position.x, position.y - 32))
						{
							App->tilemap->MoveDiamond(position.x, position.y - 16, UP);
							App->audio->PlayFx(pushBlockFx, 0);
						}
					}
					else if (App->tilemap->thereIsAWall(position.x, position.y - 1))
					{
						currentAnimation = &upPushAnim;
						animDone = true;
						App->tilemap->PushUpWall();
						App->audio->PlayFx(pushWallFx, 0);
					}

				}

				if (opcio == 'd')
				{

					if (App->tilemap->thereIsABlock(position.x, position.y + 16))
					{
						
						animDone = true;
						if (App->tilemap->thereIsABlock(position.x, position.y + 32) || App->tilemap->thereIsAWall(position.x, position.y + 32) || App->tilemap->thereIsADiamond(position.x, position.y + 32))
						{
							currentAnimation = &downPushAnim;
							App->tilemap->DestroyBlock(position.x, position.y + 16);
							App->audio->PlayFx(destroyBlockFx, 0);
							score += 30;
						}
						else {
							currentAnimation = &downShortPushAnim;
							App->tilemap->MoveBlock(position.x, position.y + 16, DOWN);
							App->audio->PlayFx(pushBlockFx, 0);
						}
					}
					else if (App->tilemap->thereIsADiamond(position.x, position.y + 16))
					{
						currentAnimation = &downShortPushAnim;
						animDone = true;
						if (!App->tilemap->thereIsABlock(position.x, position.y + 32) || !App->tilemap->thereIsAWall(position.x, position.y + 32) || !App->tilemap->thereIsADiamond(position.x, position.y + 32))
						{
							App->tilemap->MoveDiamond(position.x, position.y + 16, DOWN);
							App->audio->PlayFx(pushBlockFx, 0);
						}
					}
					else if (App->tilemap->thereIsAWall(position.x, position.y + 16))
					{
						currentAnimation = &downPushAnim;
						animDone = true;
						App->tilemap->PushDownWall();
						App->audio->PlayFx(pushWallFx, 0);
					}
				}

				
			}
			if (leftPushAnim.HasFinished()) {
					animDone = false;
					leftPushAnim.Reset();
					currentAnimation = &leftAnim;
				}
			if (rightPushAnim.HasFinished()) {
					animDone = false;
					rightPushAnim.Reset();
					currentAnimation = &rightAnim;
				}
			if (upPushAnim.HasFinished()) {
					animDone = false;
					upPushAnim.Reset();
					currentAnimation = &upAnim;
				}
			if (downPushAnim.HasFinished()) {
					animDone = false;
					downPushAnim.Reset();
					currentAnimation = &downAnim;
				}
			if (leftShortPushAnim.HasFinished()) {
					animDone = false;
					leftShortPushAnim.Reset();
					currentAnimation = &leftAnim;
				}
			if (rightShortPushAnim.HasFinished()) {
					animDone = false;
					rightShortPushAnim.Reset();
					currentAnimation = &rightAnim;
				}
			if (upShortPushAnim.HasFinished()) {
					animDone = false;
					upShortPushAnim.Reset();
					currentAnimation = &upAnim;
				}
			if (downShortPushAnim.HasFinished()) {
					animDone = false;
					downShortPushAnim.Reset();
					currentAnimation = &downAnim;
				}
		}
		
	}
			

	if (!destroyed) {
		timerLevel++;
		if (timerLevel == 3600) {
			timerLevel = 0;
			minutes++;
		}
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
	App->fonts->BlitText(56, 0, whiteFont, scoreText);

	sprintf_s(secondsText, 10, "%d", timerLevel/60);
	sprintf_s(minutesText, 10, "%d", minutes);

	return update_status::UPDATE_CONTINUE;
}


bool ModulePlayer::CleanUp()
{
	activeTextures = activeColliders = activeFonts = activeFx = 0;

	// TODO 1: Remove ALL remaining resources. Update resource count properly

	App->textures->Unload(texture);
	--totalTextures;

	App->audio->UnloadFx(snobeeFx);
	--totalFx;

	App->audio->UnloadFx(destroyBlockFx);
	--totalFx;

	App->audio->UnloadFx(pushBlockFx);
	--totalFx;

	App->audio->UnloadFx(pushWallFx);
	--totalFx;

	App->collisions->RemoveCollider(collider);
	--totalColliders;

	App->fonts->UnLoad(whiteFont);
	--totalFonts;
	

	return true;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{







	if (c1->type == Collider::Type::PLAYER) {

				if (c2->type == Collider::Type::ENEMY)
				{
					destroyed = true;
					rep = 0;
					c1->pendingToDelete = true;
					c2->pendingToDelete = true;
					lifes--;
					
				}
				if(c2->type == Collider::Type::ENEMY_STUNNED)
				{
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesStunned[i]) {
							App->particles->AddParticle(oneHundredParticle, App->enemies->enemies[i]->position.x, App->enemies->enemies[i]->position.y, Collider::Type::NONE, 0);

							App->audio->PlayFx(snobeeFx, 0);
							delete App->enemies->enemies[i];

							App->enemies->enemies[i] = nullptr;
							scoreOneHundred = true;
							score += 100;
							App->scene->enemiesAlive--;
							break;

						}
					}
					c2->pendingToDelete = true;
					
				}

			
		
	
	}

}
