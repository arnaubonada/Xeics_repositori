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

#include "SDL/include/SDL_scancode.h"


char opcio = 'a';
//bool collidatoL = false;
//bool collidatoR = false;
//bool collidatoD = false;
//bool collidatoU = false;

//char dir = 'i';

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{

	position.x = 150;
	position.y = 120;
	
	
	/*
	// idle animation (arcade sprite sheet)
	idleAnim.PushBack({ 0, 0, 16, 16 });
	idleAnim.PushBack({ 16, 0, 16, 16 });
	//upAnim.loop = false;
	idleAnim.speed = 0.1f;
	*/

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
}




ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Characters.png");
	//currentAnimation = &idleAnim;

	laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::PLAYER, this);

	return ret;
}

update_status ModulePlayer::Update()
{
	/*Animation* current = NULL;
	current = new Animation;
	
	current = &idleAnim;

	currentAnimation = current;
	*/

	//currentAnimation = &leftAnim;
	
	switch (opcio)
	{

	case 'a':
		currentAnimation = &downAnim;
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

	
	

		if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			if (currentAnimation != &leftAnim)
			{

				position.x -= speed;
				currentAnimation = &leftAnim;
				opcio = 'l';
				//collidatoL = false;
				//collider->SetPos(position.x, position.y);
			
			}
		}
		else {

			if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				if (currentAnimation != &rightAnim)
				{
					position.x += speed;
					currentAnimation = &rightAnim;
					opcio = 'r';
					//collidatoR = false;

					//collider->SetPos(position.x, position.y);

				}
			}
			else {
				if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{


					if (currentAnimation != &downAnim)
					{

						position.y += speed;
						currentAnimation = &downAnim;
						opcio = 'd';
						//collidatoD = false;
						//collider->SetPos(position.x, position.y);


					}
				}

				else {
					if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
					{
						if (currentAnimation != &upAnim)
						{

							position.y -= speed;
							currentAnimation = &upAnim;
							opcio = 'u';
							//collidatoU = false;
							//collider->SetPos(position.x, position.y);


						}
					}
				}

			}

		
		}
		collider->SetPos(position.x, position.y);


/*
switch (App->input->keys[SDL_Scancode])
{
case SDL_SCANCODE_A:

	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &leftAnim)
		{
			position.x -= speed;
			currentAnimation = &leftAnim;
		}

	}


	break;

case SDL_SCANCODE_D:

	break;

case SDL_SCANCODE_W:

	break;

case SDL_SCANCODE_S:

	break;


default:
	break;
}
*/



	/*
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, Collider::Type::PLAYER_SHOT);
		App->audio->PlayFx(laserFx);
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		currentAnimation = &idleAnim;

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	*/

	currentAnimation->Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	
	return update_status::UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	
	
		if (c1 == collider && opcio == 'l')
		{
		
			position.x += speed;
			//collidatoL = true;

		}


		if (c1 == collider && opcio == 'r')
		{

			position.x -= speed;
			//collidatoR = true;
		}


		if (c1 == collider && opcio == 'd')
		{

			position.y -= speed;
			//collidatoD = true;

		}


		if (c1 == collider && opcio == 'u')
		{
			position.y += speed;
			//collidatoU = true;

		}

	
		//collider->SetPos(position.x, position.y);


		//OPCIO AMB SCANCODES
		//bool valid = false;

		/*
		if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{

			position.x = position.x + 1;
			//currentAnimation = &leftAnim;
			//opcio = 'l';
			//valid = true;
			collidatoL = true;

		}
	}

	if (c1 == collider && !collidatoR)
	{
		//bool valid = false;


		if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			//c1->SetPos(position.x, position.y);
			position.x = position.x - 1;
			//currentAnimation = &rightAnim;
			//opcio = 'r';
			//valid = true;
			collidatoR = true;


		}
	}
	if (c1 == collider && !collidatoD)
	{
		//bool valid = false;

		if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{

			position.y = position.y - 1;
			//currentAnimation = &downAnim;
			//valid = true;
			//opcio = 'd';
			collidatoD = true;


		}
	}
	if (c1 == collider && !collidatoU)
	{
		//bool valid = false;

		if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		{
			position.y = position.y + 1;
			//currentAnimation = &upAnim;
			//valid = true;
			//opcio = 'u';
			collidatoU = true;

		}
	}*/


	/*
		if (c1 == collider)
		{
			//bool valid = false;


			if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && !collidatoL)
			{

				position.x = position.x + 1;
				//currentAnimation = &leftAnim;
				//opcio = 'l';
				//valid = true;
				collidatoL = true;

			}
			else {
				if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && !collidatoR)
				{
					//c1->SetPos(position.x, position.y);
					position.x = position.x - 1;
					//currentAnimation = &rightAnim;
					//opcio = 'r';
					//valid = true;
					collidatoR = true;


				}
				else {
					if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && !collidatoD)
					{

						position.y = position.y - 1;
						//currentAnimation = &downAnim;
						//valid = true;
						//opcio = 'd';
						collidatoD = true;


					}
					else {

						if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && !collidatoU)
						{
							position.y = position.y + 1;
							//currentAnimation = &upAnim;
							//valid = true;
							//opcio = 'u';
							collidatoU = true;

						}

						//valid = false;

					}

				}
			}

		
	*/
	
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->sceneIntro, 60);

		App->audio->PlayFx(explosionFx);
		destroyed = true;
	
}