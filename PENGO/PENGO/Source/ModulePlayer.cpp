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



#include "SDL/include/SDL_scancode.h"


//bool collidatoL = false;
//bool collidatoR = false;
//bool collidatoD = false;
//bool collidatoU = false;

//char dir = 'i';

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{

	
	
	
	/*
	// idle animation (arcade sprite sheet)
	idleAnim.PushBack({ 0, 0, 16, 16 });
	idleAnim.PushBack({ 16, 0, 16, 16 });
	//upAnim.loop = false;
	idleAnim.speed = 0.1f;
	*/

	// move up
	//upAnim2.PushBack({ 64, 0, 16, 16 });
	//upAnim2.PushBack({ 80, 0, 16, 16 });
	//upAnim2.speed = 0.1f;

	//// Move down
	//downAnim2.PushBack({ 0, 0, 16, 16 });
	//downAnim2.PushBack({ 16, 0, 16, 16 });
	//downAnim2.speed = 0.1f;

	//// move left
	//leftAnim2.PushBack({ 32, 0, 16, 16 });
	//leftAnim2.PushBack({ 48, 0, 16, 16 });
	//leftAnim2.speed = 0.1f;

	//// Move right
	//rightAnim2.PushBack({ 96, 0, 16, 16 });
	//rightAnim2.PushBack({ 112, 0, 16, 16 });
	//rightAnim2.speed = 0.1f;




	//// move up
	//upAnim.PushBack({ 64, 0, 16, 16 });
	//upAnim.PushBack({ 80, 0, 16, 16 });
	//upAnim.speed = 0.1f;

	//// Move down
	//downAnim.PushBack({ 0, 0, 16, 16 });
	//downAnim.PushBack({ 16, 0, 16, 16 });
	//downAnim.speed = 0.1f;

	//// move left
	//leftAnim.PushBack({ 32, 0, 16, 16 });
	//leftAnim.PushBack({ 48, 0, 16, 16 });
	//leftAnim.speed = 0.1f;

	//// Move right
	//rightAnim.PushBack({ 96, 0, 16, 16 });
	//rightAnim.PushBack({ 112, 0, 16, 16 });
	//rightAnim.speed = 0.1f;
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

	position.x = 8;
	position.y = 32;
	

	/*laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");*/

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
	
	if (App->scene->matriu[position.x][position.y] == PENGO) {
		//currentAnimation = &downAnim;
	}

	//App->scene->state = 1;
	//App->scene->matriu[25][25] = BLOCKS;

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

	
	App->scene->pintarPengo(App->scene->getState(position.x, position.y));


		if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			if (currentAnimation != &leftAnim)
			{
				for (int i = 0; i < 16; i++) {
					position.x -= 1;
					Sleep(8);
				}
				//App->scene->state = 0;

				if (App->scene->matriu[position.x - 16][position.y] == NOBLOCKS) {
					App->scene->borrar(App->scene->getState(position.x, position.y));
					//App->scene->state = 2;
					//App->scene->pintarPengo(App->scene->getState(position.x-16, position.y));

				}
				//App->scene->state = 2;
				//App->scene->matriu[position.x - 16][position.y] = PENGO;
				//currentAnimation = &leftAnim;

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
					for (int i = 0; i < 16; i++) {
						position.x += 1;
						Sleep(8);
					}
					//App->scene->state = 0;

					if (App->scene->matriu[position.x + 16][position.y] == NOBLOCKS) {
						App->scene->borrar(App->scene->getState(position.x, position.y));
						//App->scene->state = 2;
						//App->scene->pintarPengo(App->scene->getState(position.x+16, position.y));

					}
					//App->scene->state = 2;
					//App->scene->matriu[position.x - 16][position.y] = PENGO;
					//currentAnimation = &leftAnim;

					opcio = 'r';

			
				}
			}
			else {
				if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{


					if (currentAnimation != &downAnim)
					{
						for (int i = 0; i < 16; i++) {
							position.y += 1;
							Sleep(8);
						}
						//App->scene->state = 0;

						if (App->scene->matriu[position.x][position.y+16] == NOBLOCKS) {
							//->scene->pintarPengo(App->scene->getState(position.x, position.y + 16));
							App->scene->borrar(App->scene->getState(position.x, position.y));
							//App->scene->state = 2;
							//App->scene->pintarPengo(App->scene->getState(position.x, position.y+16));

						}
						//App->scene->state = 2;
						//App->scene->matriu[position.x - 16][position.y] = PENGO;
						//currentAnimation = &leftAnim;

						opcio = 'd';

					
					}
				}

				else {
					if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
					{
						if (currentAnimation != &upAnim)
						{
							for (int i = 0; i < 16; i++) {
								position.y -= 1;
								Sleep(8);
							}
							//App->scene->state = 0;

							if (App->scene->matriu[position.x][position.y - 16] == NOBLOCKS) {
								App->scene->borrar(App->scene->getState(position.x, position.y));
								//	App->scene->state = 2;
								//App->scene->pintarPengo(App->scene->getState(position.x, position.y-16));
								
								

							}
							//App->scene->state = 2;
							//App->scene->matriu[position.x - 16][position.y] = PENGO;
							//currentAnimation = &leftAnim;

							opcio = 'u';
							

						}
					}
				}

			}

		
		}
		
		collider->SetPos(position.x, position.y);
		App->scene->map.x = position.x;
		App->scene->map.y = position.y;
		//App->scene->pintarPengo(App->scene->getState(position.x, position.y));

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
		
			position.x += move;
			//collidatoL = true;

		}


		if (c1 == collider && opcio == 'r')
		{

			position.x -= move;
			//collidatoR = true;
		}


		if (c1 == collider && opcio == 'd')
		{

			position.y -= move;
			//collidatoD = true;

		}


		if (c1 == collider && opcio == 'u')
		{
			position.y += move;
			//collidatoU = true;

		}

	
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