#include "ModuleCollisions.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_Scancode.h"


ModuleCollisions::ModuleCollisions(bool startEnabled) : Module(startEnabled)
{
	name = "collisions";

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[Collider::Type::DIAMOND][Collider::Type::DIAMOND] = false;
	matrix[Collider::Type::DIAMOND][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::DIAMOND][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::DIAMOND][Collider::Type::ENEMY_STUNNED] = true;
	matrix[Collider::Type::DIAMOND][Collider::Type::BLOCK] = true;

	matrix[Collider::Type::PLAYER][Collider::Type::DIAMOND] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_STUNNED] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::BLOCK] = true;

	matrix[Collider::Type::ENEMY][Collider::Type::DIAMOND] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::ENEMY][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::ENEMY_STUNNED] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::BLOCK] = true;

    matrix[Collider::Type::ENEMY_STUNNED][Collider::Type::DIAMOND] = true;
	matrix[Collider::Type::ENEMY_STUNNED][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::ENEMY_STUNNED][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::ENEMY_STUNNED][Collider::Type::ENEMY_STUNNED] = false;
	matrix[Collider::Type::ENEMY_STUNNED][Collider::Type::BLOCK] = true;

	matrix[Collider::Type::BLOCK][Collider::Type::DIAMOND] = true;
	matrix[Collider::Type::BLOCK][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::BLOCK][Collider::Type::ENEMY] = true;
	matrix[Collider::Type::BLOCK][Collider::Type::ENEMY_STUNNED] = true;
	matrix[Collider::Type::BLOCK][Collider::Type::BLOCK] = false;
}

// Destructor
ModuleCollisions::~ModuleCollisions()
{

}

update_status ModuleCollisions::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr && colliders[i]->pendingToDelete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
			--colliderCount;
		}
	}

	Collider* c1;
	Collider* c2;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if(colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for(uint k = i+1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if(colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (matrix[c1->type][c2->type] && c1->Intersects(c2->rect))
			{
				for (uint i = 0; i < MAX_LISTENERS; ++i)
					if (c1->listeners[i] != nullptr) c1->listeners[i]->OnCollision(c1, c2);

				for (uint i = 0; i < MAX_LISTENERS; ++i)
					if (c2->listeners[i] != nullptr) c2->listeners[i]->OnCollision(c2, c1);

			}
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleCollisions::Update()
{
	if (App->input->keys[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleCollisions::PostUpdate()
{
	if (debug)
		DebugDraw();

	return update_status::UPDATE_CONTINUE;
}

void ModuleCollisions::DebugDraw()
{
	Uint8 alpha = 80;
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
			continue;
		
		switch(colliders[i]->type)
		{
			case Collider::Type::NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
			case Collider::Type::DIAMOND: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
			case Collider::Type::PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
			case Collider::Type::ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
			case Collider::Type::ENEMY_STUNNED: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
			case Collider::Type::BLOCK: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		}
	}
}

// Called before quitting
bool ModuleCollisions::CleanUp()
{
	LOG("Freeing all colliders");

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
			--colliderCount;
		}
	}

	return true;
}

Collider* ModuleCollisions::AddCollider(SDL_Rect rect, Collider::Type type, Module* listener)
{
	Collider* ret = nullptr;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, listener);
			++colliderCount;
			break;
		}
	}

	return ret;
}

void ModuleCollisions::RemoveCollider(Collider* collider)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == collider)
		{
			delete colliders[i];
			colliders[i] = nullptr;
			--colliderCount;
		}
	}
}

