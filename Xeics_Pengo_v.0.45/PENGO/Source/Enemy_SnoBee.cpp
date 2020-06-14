#include "Enemy_SnoBee.h"

#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleScene.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleTileMap.h"
#include "Particle.h"
#include "ModuleParticles.h"

#include "time.h"

#include "SDL/include/SDL.h"


Enemy_SnoBee::Enemy_SnoBee(int x, int y, enum class ENEMY_TYPE type) : Enemy(x, y)
{
	App->audio->UnloadFx(App->enemies->snobeeFx);
	App->audio->UnloadFx(App->enemies->snobeeSmashedFx);
	App->audio->UnloadFx(App->enemies->snobeeStunnedFx);

	//App->collisions->RemoveCollider(collider);
	//App->collisions->RemoveCollider(App->enemies->colliderStunned);

	App->enemies->snobeeFx = App->audio->LoadFx("Assets/Audio/snobeekill.wav");
	App->enemies->snobeeSmashedFx = App->audio->LoadFx("Assets/Audio/SnoBee Smashed.wav");
	App->enemies->snobeeStunnedFx = App->audio->LoadFx("Assets/Audio/SnoBee Stunned.wav");

	typeEnemy = type;
	if (App->tilemap->scenelvl1 || App->tilemap->scenelvl9) {
		snoUpAnim.PushBack({ 64, 160, 16, 16 });
		snoUpAnim.PushBack({ 80, 160, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 0, 160, 16, 16 });
		snoDownAnim.PushBack({ 16, 160, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 32, 160, 16, 16 });
		snoLeftAnim.PushBack({ 48, 160, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 96, 160, 16, 16 });
		snoRightAnim.PushBack({ 112, 160, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 64, 144, 16, 16 });
		normalSnoUpAnim.PushBack({ 80, 144, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 0, 144, 16, 16 });
		normalSnoDownAnim.PushBack({ 16, 144, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 32, 144, 16, 16 });
		normalSnoLeftAnim.PushBack({ 48, 144, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 96, 144, 16, 16 });
		normalSnoRightAnim.PushBack({ 112, 144, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 96, 128, 16, 16 });
		stunnedAnim.PushBack({ 112, 128, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 96, 128, 16, 16 });
		stunnedBlueAnim.PushBack({ 112, 128, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 96, 144, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 32, 144, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 0, 144, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 64, 144, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}
	if (App->tilemap->scenelvl2 || App->tilemap->scenelvl10) {
		snoUpAnim.PushBack({ 192, 160, 16, 16 });
		snoUpAnim.PushBack({ 208, 160, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 128, 160, 16, 16 });
		snoDownAnim.PushBack({ 144, 160, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 160, 160, 16, 16 });
		snoLeftAnim.PushBack({ 176, 160, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 224, 160, 16, 16 });
		snoRightAnim.PushBack({ 240, 160, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 192, 144, 16, 16 });
		normalSnoUpAnim.PushBack({ 208, 144, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 128, 144, 16, 16 });
		normalSnoDownAnim.PushBack({ 144, 144, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 160, 144, 16, 16 });
		normalSnoLeftAnim.PushBack({ 176, 144, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 224, 144, 16, 16 });
		normalSnoRightAnim.PushBack({ 240, 144, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 224, 128, 16, 16 });
		stunnedAnim.PushBack({ 240, 128, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 224, 128, 16, 16 });
		stunnedBlueAnim.PushBack({ 240, 128, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 224, 144, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 160, 144, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 128, 144, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 192, 144, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}
	if (App->tilemap->scenelvl3 || App->tilemap->scenelvl11) {
		snoUpAnim.PushBack({ 320, 160, 16, 16 });
		snoUpAnim.PushBack({ 336, 160, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 256, 160, 16, 16 });
		snoDownAnim.PushBack({ 272, 160, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 288, 160, 16, 16 });
		snoLeftAnim.PushBack({ 304, 160, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 352, 160, 16, 16 });
		snoRightAnim.PushBack({ 368, 160, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 320, 144, 16, 16 });
		normalSnoUpAnim.PushBack({ 336, 144, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 256, 144, 16, 16 });
		normalSnoDownAnim.PushBack({ 272, 144, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 288, 144, 16, 16 });
		normalSnoLeftAnim.PushBack({ 304, 144, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 352, 144, 16, 16 });
		normalSnoRightAnim.PushBack({ 368, 144, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 352, 128, 16, 16 });
		stunnedAnim.PushBack({ 368, 128, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 352, 128, 16, 16 });
		stunnedBlueAnim.PushBack({ 368, 128, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 352, 144, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 288, 144, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 256, 144, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 320, 144, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}
	
	if (App->tilemap->scenelvl4 || App->tilemap->scenelvl12) {
		snoUpAnim.PushBack({ 448, 160, 16, 16 });
		snoUpAnim.PushBack({ 464, 160, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 384, 160, 16, 16 });
		snoDownAnim.PushBack({ 400, 160, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 416, 160, 16, 16 });
		snoLeftAnim.PushBack({ 432, 160, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 480, 160, 16, 16 });
		snoRightAnim.PushBack({ 496, 160, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 448, 144, 16, 16 });
		normalSnoUpAnim.PushBack({ 464, 144, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 384, 144, 16, 16 });
		normalSnoDownAnim.PushBack({ 400, 144, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 416, 144, 16, 16 });
		normalSnoLeftAnim.PushBack({ 432, 144, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 480, 144, 16, 16 });
		normalSnoRightAnim.PushBack({ 496, 144, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 480, 128, 16, 16 });
		stunnedAnim.PushBack({ 496, 128, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 480, 128, 16, 16 });
		stunnedBlueAnim.PushBack({ 496, 128, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 480, 144, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 416, 144, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 384, 144, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 448, 144, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}
	if (App->tilemap->scenelvl5 || App->tilemap->scenelvl13) {
		snoUpAnim.PushBack({ 64, 240, 16, 16 });
		snoUpAnim.PushBack({ 80, 240, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 0, 240, 16, 16 });
		snoDownAnim.PushBack({ 16, 240, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 32, 240, 16, 16 });
		snoLeftAnim.PushBack({ 48, 240, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 96, 240, 16, 16 });
		snoRightAnim.PushBack({ 112, 240, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 64, 224, 16, 16 });
		normalSnoUpAnim.PushBack({ 80, 224, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 0, 224, 16, 16 });
		normalSnoDownAnim.PushBack({ 16, 224, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 32, 224, 16, 16 });
		normalSnoLeftAnim.PushBack({ 48, 224, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 96, 224, 16, 16 });
		normalSnoRightAnim.PushBack({ 112, 224, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 96, 208, 16, 16 });
		stunnedAnim.PushBack({ 112, 208, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 96, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 112, 208, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 96, 224, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 32, 224, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 0, 224, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 64, 224, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}
	if (App->tilemap->scenelvl6 || App->tilemap->scenelvl14) {
		snoUpAnim.PushBack({ 192, 240, 16, 16 });
		snoUpAnim.PushBack({ 208, 240, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 128, 240, 16, 16 });
		snoDownAnim.PushBack({ 144, 240, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 160, 240, 16, 16 });
		snoLeftAnim.PushBack({ 176, 240, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 224, 240, 16, 16 });
		snoRightAnim.PushBack({ 240, 240, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 192, 224, 16, 16 });
		normalSnoUpAnim.PushBack({ 208, 224, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 128, 224, 16, 16 });
		normalSnoDownAnim.PushBack({ 144, 224, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 160, 224, 16, 16 });
		normalSnoLeftAnim.PushBack({ 176, 224, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 224, 224, 16, 16 });
		normalSnoRightAnim.PushBack({ 240, 224, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 224, 208, 16, 16 });
		stunnedAnim.PushBack({ 240, 208, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 224, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 240, 208, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 224, 224, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 160, 224, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 128, 224, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 192, 224, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}
	if (App->tilemap->scenelvl7 || App->tilemap->scenelvl15) {
		snoUpAnim.PushBack({ 320, 240, 16, 16 });
		snoUpAnim.PushBack({ 336, 240, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 256, 240, 16, 16 });
		snoDownAnim.PushBack({ 272, 240, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 288, 240, 16, 16 });
		snoLeftAnim.PushBack({ 304, 240, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 352, 240, 16, 16 });
		snoRightAnim.PushBack({ 368, 240, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 320, 224, 16, 16 });
		normalSnoUpAnim.PushBack({ 336, 224, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 256, 224, 16, 16 });
		normalSnoDownAnim.PushBack({ 272, 224, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 288, 224, 16, 16 });
		normalSnoLeftAnim.PushBack({ 304, 224, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 352, 224, 16, 16 });
		normalSnoRightAnim.PushBack({ 368, 224, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 352, 208, 16, 16 });
		stunnedAnim.PushBack({ 368, 208, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 352, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 368, 208, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 352, 224, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 288, 224, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 256, 224, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 320, 224, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}
	
	if (App->tilemap->scenelvl8) {
		snoUpAnim.PushBack({ 448, 240, 16, 16 });
		snoUpAnim.PushBack({ 464, 240, 16, 16 });
		snoUpAnim.speed = 0.1f;

		snoDownAnim.PushBack({ 384, 240, 16, 16 });
		snoDownAnim.PushBack({ 400, 240, 16, 16 });
		snoDownAnim.speed = 0.1f;

		snoLeftAnim.PushBack({ 416, 240, 16, 16 });
		snoLeftAnim.PushBack({ 432, 240, 16, 16 });
		snoLeftAnim.speed = 0.1f;

		snoRightAnim.PushBack({ 480, 240, 16, 16 });
		snoRightAnim.PushBack({ 496, 240, 16, 16 });
		snoRightAnim.speed = 0.1f;

		normalSnoUpAnim.PushBack({ 448, 224, 16, 16 });
		normalSnoUpAnim.PushBack({ 464, 224, 16, 16 });
		normalSnoUpAnim.speed = 0.1f;

		normalSnoDownAnim.PushBack({ 384, 224, 16, 16 });
		normalSnoDownAnim.PushBack({ 400, 224, 16, 16 });
		normalSnoDownAnim.speed = 0.1f;

		normalSnoLeftAnim.PushBack({ 416, 224, 16, 16 });
		normalSnoLeftAnim.PushBack({ 432, 224, 16, 16 });
		normalSnoLeftAnim.speed = 0.1f;

		normalSnoRightAnim.PushBack({ 480, 224, 16, 16 });
		normalSnoRightAnim.PushBack({ 496, 224, 16, 16 });
		normalSnoRightAnim.speed = 0.1f;

		stunnedAnim.PushBack({ 480, 208, 16, 16 });
		stunnedAnim.PushBack({ 496, 208, 16, 16 });
		stunnedAnim.speed = 0.1f;

		stunnedBlueAnim.PushBack({ 608, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 624, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 480, 208, 16, 16 });
		stunnedBlueAnim.PushBack({ 496, 208, 16, 16 });
		stunnedBlueAnim.speed = 0.1f;


		dragEnemyLeftAnim.PushBack({ 480, 224, 16, 16 });
		dragEnemyLeftAnim.speed = 0.1f;

		dragEnemyRightAnim.PushBack({ 416, 224, 16, 16 });
		dragEnemyRightAnim.speed = 0.1f;

		dragEnemyUpAnim.PushBack({ 384, 224, 16, 16 });
		dragEnemyUpAnim.speed = 0.1f;

		dragEnemyDownAnim.PushBack({ 448, 224, 16, 16 });
		dragEnemyDownAnim.speed = 0.1f;

		firstSmashLeftAnim.PushBack({ 96, 192, 16, 16 });
		firstSmashLeftAnim.speed = 0.1f;

		firstSmashRightAnim.PushBack({ 32, 192, 16, 16 });
		firstSmashRightAnim.speed = 0.1f;

		firstSmashUpAnim.PushBack({ 0, 192, 16, 16 });
		firstSmashUpAnim.speed = 0.1f;

		firstSmashDownAnim.PushBack({ 64, 192, 16, 16 });
		firstSmashDownAnim.speed = 0.1f;

		secondSmashLeftAnim.PushBack({ 112, 192, 16, 16 });
		secondSmashLeftAnim.speed = 0.1f;

		secondSmashRightAnim.PushBack({ 48, 192, 16, 16 });
		secondSmashRightAnim.speed = 0.1f;

		secondSmashUpAnim.PushBack({ 16, 192, 16, 16 });
		secondSmashUpAnim.speed = 0.1f;

		secondSmashDownAnim.PushBack({ 80, 192, 16, 16 });
		secondSmashDownAnim.speed = 0.1f;
	}

	fourHundredParticle.anim.PushBack({ 0,16,16,16 });
	fourHundredParticle.anim.PushBack({ 0,16,16,16 });
	fourHundredParticle.anim.PushBack({ 0,16,16,16 });
	fourHundredParticle.anim.PushBack({ 0,16,16,16 });
	fourHundredParticle.anim.PushBack({ 0,16,16,16 });
	fourHundredParticle.anim.PushBack({ 0,16,16,16 });
	fourHundredParticle.anim.speed = 0.1f;
	fourHundredParticle.anim.loop = false;

	currentAnim = &snoDownAnim;

	if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER)
	{
		collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
		currentAnim = &snoDownAnim;
	}
	else if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL)
	{
		collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
		currentAnim = &normalSnoDownAnim;
	}
	if (App->tilemap->threeDiamondsDone) {
		App->tilemap->threeDiamondsFinish = false;
		diamondComplete = true;
	}
}




void Enemy_SnoBee::Update()
{
	//if (App->player->destroyed) {
	//	App->collisions->RemoveCollider(App->enemies->colliderStunned);
	//}

	if (!App->player->destroyed) {
		if (!App->tilemap->threeDiamonds) {
			if (stunnedEnemy) {
				dirEnemy = NOMOVE;
			}
			if (smashedEnemy) {
				dirEnemy = NOMOVE;
			}
			if (randfinish) {
				dirEnemy = NOMOVE;
			}

		if (dirEnemy == NOMOVE ) {
			enemyMovement();
		}

		if (dirEnemy != NOMOVE) {

			if (dirEnemy == LEFT) {
				if (App->tilemap->isWalkable(position.x - 1, position.y)) {
					
					/*if (position.x % 2 != 0 && position.x - 1 == finalEnemyPositionX) {
						position.x--;
					}*/
					position.x--;
					if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
						if (App->tilemap->thereIsABlock(position.x - 1, position.y))
						{
							App->tilemap->DestroyBlock(position.x - 16, position.y);
							
						}

					}
					if (position.x == finalEnemyPositionX) {
						dirEnemy = NOMOVE;

					}
					//positionEnemyX--;
					

				}
				else {
					randfinish = true;
				}
				
			}

			else if (dirEnemy == RIGHT) {
				if (App->tilemap->isWalkable(position.x + 16, position.y)) {
					
					/*if (position.x % 2 != 0 && position.x + 1 == finalEnemyPositionX) {
						position.x++;
					}*/
					position.x++;
					if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
						if (App->tilemap->thereIsABlock(position.x + 16, position.y))
						{
							App->tilemap->DestroyBlock(position.x + 16, position.y);
							
						}
					}
					if (position.x == finalEnemyPositionX) {
						dirEnemy = NOMOVE;
					}
					
					//	positionEnemyX++;
				}
				else {
					randfinish = true;
				}
				
			}
			else if (dirEnemy == UP) {
				if (App->tilemap->isWalkable(position.x, position.y - 1)) {
					
					/*if (position.y % 2 != 0 && position.y - 1 == finalEnemyPositionY) {
						position.y--;
					}*/
					position.y--;
					if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
					if (App->tilemap->thereIsABlock(position.x, position.y - 1))
					{
						App->tilemap->DestroyBlock(position.x, position.y - 16);
						
					}
					}
					if (position.y == finalEnemyPositionY) {
						dirEnemy = NOMOVE;
					}
					
					//positionEnemyY--;

				}
				else {
					randfinish = true;
				}
			}
			else if (dirEnemy == DOWN) {
				if (App->tilemap->isWalkable(position.x, position.y + 16)) {
					
					/*if (position.y % 2 != 0 && position.y + 1 == finalEnemyPositionY) {
						position.y++;
					}*/
					position.y++;
					if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
						if (App->tilemap->thereIsABlock(position.x, position.y + 16))
						{
							App->tilemap->DestroyBlock(position.x, position.y + 16);
							
						}

					
					}
					if (position.y == finalEnemyPositionY) {
						dirEnemy = NOMOVE;
					}
					//positionEnemyY++;
					
				}
				
				else {
					randfinish = true;
				}
				}
			}
		}
		/*LOG("Pos x: %d", position.x);
		LOG("Pos y: %d", position.y);*/

		if (App->tilemap->pushLeft) {
			if (position.x == 16) {
				
				stunnedEnemy = true;
				for (uint i = 0; i < MAX_ENEMIES; ++i)
				{
					if (App->enemies->enemies[i] != nullptr)
					{
						if (App->enemies->enemies[i]->position.x == 16) {
							App->enemies->enemiesStunned[i] = true;
							if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;
								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;

							}
							else if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;
								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;
							}
							//colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
							App->collisions->RemoveCollider(collider);
							break;
						}
					}
				}
				
				App->scene->timescore = 1;

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
			}
		}
		if (App->tilemap->pushRight) {
			if (position.x == 208) {
				stunnedEnemy = true;
				for (uint i = 0; i < MAX_ENEMIES; ++i)
				{
					if (App->enemies->enemies[i] != nullptr)
					{
						if (App->enemies->enemies[i]->position.x == 208) {
							App->enemies->enemiesStunned[i] = true;
							if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;

								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;

							}
							else if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;

								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;

							}
							//colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
							App->collisions->RemoveCollider(collider);
							break;
						}
					}
				}
				App->scene->timescore = 1;

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
			}
		}
		if (App->tilemap->pushUp) {
			if (position.y == 32) {
				stunnedEnemy = true;

				for (uint i = 0; i < MAX_ENEMIES; ++i)
				{
					if (App->enemies->enemies[i] != nullptr)
					{
						if (App->enemies->enemies[i]->position.y == 32) {
							App->enemies->enemiesStunned[i] = true;
							if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;

								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;

							}
							else if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;

								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;

							}
							//colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
							App->collisions->RemoveCollider(collider);

							break;
						}
					}
				}
				App->scene->timescore = 1;

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
			}
		}
		if (App->tilemap->pushDown) {
			if (position.y == 256) {
				stunnedEnemy = true;
				for (uint i = 0; i < MAX_ENEMIES; ++i)
				{
					if (App->enemies->enemies[i] != nullptr)
					{
						if (App->enemies->enemies[i]->position.y == 256) {
							App->enemies->enemiesStunned[i] = true;
							if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;

								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;

							}
							else if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL && stunnedEnemy && !oneTime)
							{
								currentAnim = &stunnedAnim;

								App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
								oneTime = true;
								oneTimeRemove = true;
								App->audio->PlayFx(App->enemies->snobeeStunnedFx, 0);
								timeStunned = 1;

							}
							//colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
							App->collisions->RemoveCollider(collider);
							break;
						}
					}
				}
				App->scene->timescore = 1;
				//App->collisions->RemoveCollider(colliderStunned);
				

				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;
				//App->collisions->RemoveCollider(colliderStunned);
			}
		}

		if (!App->tilemap->threeDiamondsDone) {
			if (timeStunned != 0) {
				stunnedEnemy = true;
				App->player->snobeeStunned = true;
				timeStunned++;
				if (timeStunned < 300 && timeStunned>120) {
					currentAnim = &stunnedBlueAnim;
				}
				if (timeStunned > 300) {
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr)
						{
							if (App->enemies->enemiesStunned[i]) {
								App->enemies->enemiesStunned[i] = false;
								
							}
						}
					}
					
					stunnedEnemy = false;
					if (oneTimeRemove) {
						App->collisions->RemoveCollider(App->enemies->colliderStunned);
						oneTimeRemove = false;
						oneTime = false;
					}
					collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
					//App->player->colliderStunned->pendingToDelete = true;
					
					timeStunned = 0;

					//App->tilemap->threeDiamondsFinish = true;
					//	}
				}
			}
		}


		if (App->tilemap->threeDiamondsDone && !DiamondFinished && !diamondComplete)
		{
			if (App->tilemap->timeDiamondStunned != 0) {
				//currentAnim = &stunnedAnim;
				stunnedEnemy = true;
				App->tilemap->timeDiamondStunned++;
				App->player->snobeeStunned = true;
				/*if (App->tilemap->timeDiamondStunned < 300 && App->tilemap->timeDiamondStunned>120) {
					currentAnim = &stunnedBlueAnim;
				}*/
				if (App->tilemap->timeDiamondStunned > 900 && App->tilemap->timeDiamondStunned < 1200) {
					currentAnim = &stunnedAnim;
					stunnedEnemy = false;
					App->player->snobeeStunned = false;

					App->collisions->RemoveCollider(collider);
					App->enemies->colliderStunned = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY_STUNNED, (Module*)App->enemies);
					//App->tilemap->timeDiamondStunned = 1;
					if (lastTimeStunned == 0) {
						lastTimeStunned = 1;

					}
					timeStunned = 0;

					App->tilemap->threeDiamondsFinish = true;
					DiamondFinished = true;
					//	}
				}

			}
		}



		if (App->tilemap->threeDiamondsFinish && !diamondComplete) {
			if (lastTimeStunned != 0) {
				App->scene->timescore = 1;
				App->scene->posEnemyX = position.x;
				App->scene->posEnemyY = position.y;

				stunnedEnemy = true;
				App->player->snobeeStunned = true;
				lastTimeStunned++;
				if (lastTimeStunned < 300 && lastTimeStunned>120) {
					currentAnim = &stunnedBlueAnim;
				}
				if (lastTimeStunned > 300) {
					stunnedEnemy = false;
					App->player->snobeeStunned = false;
					lastTimeStunned = 0;
					timeStunned = 0;

					App->collisions->RemoveCollider(App->enemies->colliderStunned);
					collider = App->collisions->AddCollider({ position.x, position.y, 16, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
					DiamondFinished = true;
					diamondComplete = true;
					//App->tilemap->threeDiamondsFinish = false;
					//App->tilemap->threeDiamonds = false;

					//	}
				}
			}
		}


		
		
		Enemy::Update();
	}
}


void Enemy_SnoBee::enemyMovement()
{
	//movement nou

	

	//positionEnemyX = x;
	//positionEnemyY = y;

	if (stunnedEnemy) {
		EnemyToBlock = 0;
		EnemyToWall = 0;

	}
	if (smashedEnemy) {
		EnemyToBlock = 0;
		EnemyToWall = 0;

	}
	//dirEnemy = rand() % RIGHT + 1; //enemy direction
	if (!App->tilemap->threeDiamonds && !stunnedEnemy &&!smashedEnemy && !App->tilemap->spawn1) {
		dirEnemy = static_cast<Direction>(rand() % UP + 1);
	}

	if (App->tilemap->spaceToBlock(position.x, position.y, dirEnemy) != 0) {
		EnemyToBlock = rand() % App->tilemap->spaceToBlock(position.x, position.y, dirEnemy)+1;
	}
	else {
		EnemyToBlock = 0;
	}
	if (App->tilemap->spaceToWall(position.x, position.y, dirEnemy) != 0) {
		EnemyToWall = rand() % App->tilemap->spaceToWall(position.x, position.y, dirEnemy);
	}
	else {
		EnemyToWall = 0;
	}

	LOG("dirEnemy: %d", dirEnemy);
	
	
	LOG("Enemy to block: %d", EnemyToBlock);


	if (dirEnemy == LEFT) {

		if (App->tilemap->isWalkable(position.x - 1, position.y)) {
			//dirEnemy = LEFT;

			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoLeftAnim;
				if (position.x % 16 == 0) {
					finalEnemyPositionX = position.x - (EnemyToBlock * 16);
					dirEnemy = LEFT;
				}
			}
		}
			if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
				currentAnim = &snoLeftAnim;
				if (position.x % 16 == 0) {
					finalEnemyPositionX = position.x - (EnemyToWall * 16);
					dirEnemy = LEFT;
				}
				if (App->tilemap->thereIsABlock(position.x - 1, position.y))
				{
				App->tilemap->DestroyBlock(position.x - 16, position.y);
				if (App->tilemap->destroyedAnimBlock) {
					currentAnim = &snoLeftAnim;
				}
			}

		}
		

	}
	else if (dirEnemy == RIGHT) {
		//dirEnemy = RIGHT;
		if (App->tilemap->isWalkable(position.x + 16, position.y)) {
			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoRightAnim;
				if (position.x % 16 == 0) {
					finalEnemyPositionX = position.x + (EnemyToBlock * 16);
					dirEnemy = RIGHT;
				}

			}
		}
			if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
			currentAnim = &snoRightAnim;
			if (position.x % 16 == 0) {
				finalEnemyPositionX = position.x + (EnemyToWall * 16);
				dirEnemy = RIGHT;
						}
			if (App->tilemap->thereIsABlock(position.x + 16, position.y))
			{
				App->tilemap->DestroyBlock(position.x + 16, position.y);
				if (App->tilemap->destroyedAnimBlock) {
					currentAnim = &snoRightAnim;

				}
			}
				
		}
		
	}
	else if (dirEnemy == UP) {
		//dirEnemy = UP;
		if (App->tilemap->isWalkable(position.x, position.y - 1)) {

			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoUpAnim;

				if (position.y % 16 == 0) {
					finalEnemyPositionY = position.y - (EnemyToBlock * 16);
					dirEnemy = UP;
				}
			}
		}
		if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
			currentAnim = &snoUpAnim;
			if (position.y % 16 == 0) {
				finalEnemyPositionY = position.y - (EnemyToWall * 16);
				dirEnemy = UP;
			}
			if (App->tilemap->thereIsABlock(position.x, position.y - 1))
			{
				App->tilemap->DestroyBlock(position.x, position.y - 16);
				if (App->tilemap->destroyedAnimBlock) {
					currentAnim = &snoUpAnim;

				}
			}


		}
			}

		
	
	else if (dirEnemy == DOWN) {
		//dirEnemy = DOWN;
		if (App->tilemap->isWalkable(position.x, position.y + 16)) {

			if (typeEnemy == ENEMY_TYPE::SNOBEE_NORMAL) {
				currentAnim = &normalSnoDownAnim;
				if (position.y % 16 == 0) {
					finalEnemyPositionY = position.y + (EnemyToBlock * 16);
					dirEnemy = DOWN;
				}

			}
		}
			if (typeEnemy == ENEMY_TYPE::SNOBEE_DESTROYER) {
				currentAnim = &snoDownAnim;
				if (position.y % 16 == 0) {
					finalEnemyPositionY = position.y + (EnemyToWall * 16);
					dirEnemy = DOWN;
				}

				if (App->tilemap->thereIsABlock(position.x, position.y + 16))
				{
					App->tilemap->DestroyBlock(position.x, position.y + 16);
					if (App->tilemap->destroyedAnimBlock) {
						currentAnim = &snoDownAnim;

					}
				}

				
			
		}


	}

	randfinish = false;

	LOG("Final x: %d", finalEnemyPositionX);
	LOG("Final y: %d", finalEnemyPositionY);


	
}


void Enemy_SnoBee::OnCollision(Collider* c1, Collider* c2) {



	if (c1->type == Collider::Type::ENEMY) {

		r = collider->rect;

		if (c2->type == Collider::Type::BLOCK)
		{

			if (App->tilemap->dirBlock == LEFT) {
				smashedEnemy = true;


				position.x = App->tilemap->positionBlock.x - 16;
				position.y = App->tilemap->positionBlock.y;
				currentAnim = &dragEnemyLeftAnim;
				if (App->tilemap->positionBlock.x <= (App->tilemap->finalpositionX + 16) && App->tilemap->positionBlock.x > App->tilemap->finalpositionX) {
					position.x = App->tilemap->positionBlock.x;
					position.y = App->tilemap->positionBlock.y;
					currentAnim = &firstSmashLeftAnim;
				}
				if (App->tilemap->positionBlock.x == App->tilemap->finalpositionX + 4) {
					currentAnim = &secondSmashLeftAnim;
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr) {
							if (App->enemies->enemies[i]->collider->Intersects(r)) {
								App->enemies->enemiesSmashed[i] = true;

							}
						}
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
							App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
							App->particles->AddParticle(fourHundredParticle, App->tilemap->positionBlock.x -4, App->tilemap->positionBlock.y, Collider::Type::NONE, 0);
							App->player->score += 400;
							delete App->enemies->enemies[i];
							App->enemies->enemies[i] = nullptr;
							App->scene->enemiesAlive--;
							App->enemies->enemiesSmashed[i] = false;
							smashedEnemy = false;


						}
					}

				}

			}
			else if (App->tilemap->dirBlock == RIGHT) {
				smashedEnemy = true;


				position.x = App->tilemap->positionBlock.x + 16;
				position.y = App->tilemap->positionBlock.y;
				currentAnim = &dragEnemyRightAnim;
				if (App->tilemap->positionBlock.x >= (App->tilemap->finalpositionX - 16) && App->tilemap->positionBlock.x < App->tilemap->finalpositionX) {
					position.x = App->tilemap->positionBlock.x;
					position.y = App->tilemap->positionBlock.y;
					currentAnim = &firstSmashRightAnim;
				}
				if (App->tilemap->positionBlock.x == App->tilemap->finalpositionX - 4) {
					currentAnim = &secondSmashRightAnim;
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr) {
							if (App->enemies->enemies[i]->collider->Intersects(r)) {
								App->enemies->enemiesSmashed[i] = true;
							}
						}
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
							App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
							App->particles->AddParticle(fourHundredParticle, App->tilemap->positionBlock.x + 4, App->tilemap->positionBlock.y, Collider::Type::NONE, 0);
							App->player->score += 400;
							delete App->enemies->enemies[i];
							App->enemies->enemies[i] = nullptr;
							App->scene->enemiesAlive--;
							App->enemies->enemiesSmashed[i] = false;
							smashedEnemy = false;

						}
					}
				}

			}
			else if (App->tilemap->dirBlock == UP) {
				smashedEnemy = true;

				position.x = App->tilemap->positionBlock.x;
				position.y = App->tilemap->positionBlock.y - 16;
				currentAnim = &dragEnemyUpAnim;
				if (App->tilemap->positionBlock.y <= (App->tilemap->finalpositionY + 16) && App->tilemap->positionBlock.y > App->tilemap->finalpositionY) {
					position.x = App->tilemap->positionBlock.x;
					position.y = App->tilemap->positionBlock.y;
					currentAnim = &firstSmashUpAnim;

				}
				if (App->tilemap->positionBlock.y == App->tilemap->finalpositionY + 4) {
					currentAnim = &secondSmashUpAnim;
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr) {
							if (App->enemies->enemies[i]->collider->Intersects(r)) {
								App->enemies->enemiesSmashed[i] = true;
							}
						}
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
							App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
							App->particles->AddParticle(fourHundredParticle, App->tilemap->positionBlock.x, App->tilemap->positionBlock.y-4, Collider::Type::NONE, 0);
							App->player->score += 400;
							delete App->enemies->enemies[i];
							App->enemies->enemies[i] = nullptr;
							App->scene->enemiesAlive--;
							App->enemies->enemiesSmashed[i] = false;
							smashedEnemy = false;
						}
					}
				}
			}


			else if (App->tilemap->dirBlock == DOWN) {
				smashedEnemy = true;

				position.x = App->tilemap->positionBlock.x;
				position.y = App->tilemap->positionBlock.y + 16;
				currentAnim = &dragEnemyDownAnim;
				if (App->tilemap->positionBlock.y >= (App->tilemap->finalpositionY - 16) && App->tilemap->positionBlock.y < App->tilemap->finalpositionY) {
					position.x = App->tilemap->positionBlock.x;
					position.y = App->tilemap->positionBlock.y;
					currentAnim = &firstSmashDownAnim;
				}
				if (App->tilemap->positionBlock.y == App->tilemap->finalpositionY - 4) {
					currentAnim = &secondSmashDownAnim;
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr) {
							if (App->enemies->enemies[i]->collider->Intersects(r)) {
								App->enemies->enemiesSmashed[i] = true;
							}
						}
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
							App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
							App->particles->AddParticle(fourHundredParticle, App->tilemap->positionBlock.x, App->tilemap->positionBlock.y+4, Collider::Type::NONE, 0);
							App->player->score += 400;
							delete App->enemies->enemies[i];
							App->enemies->enemies[i] = nullptr;
							App->scene->enemiesAlive--;
							App->enemies->enemiesSmashed[i] = false;
							smashedEnemy = false;
						}
					}
				}
			}
		}
		if (c2->type == Collider::Type::DIAMOND)
		{

			if (App->tilemap->dirDiamond == LEFT) {
				smashedEnemy = true;
				position.x = App->tilemap->positionDiamond.x - 16;
				position.y = App->tilemap->positionDiamond.y;
				currentAnim = &dragEnemyLeftAnim;
				if (App->tilemap->positionDiamond.x <= (App->tilemap->finalpositionX_diamond + 16) && App->tilemap->positionDiamond.x > App->tilemap->finalpositionX_diamond) {
					position.x = App->tilemap->positionDiamond.x;
					position.y = App->tilemap->positionDiamond.y;
					currentAnim = &firstSmashLeftAnim;
				}
				if (App->tilemap->positionDiamond.x == App->tilemap->finalpositionX_diamond + 4) {
					currentAnim = &secondSmashLeftAnim;
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr) {
							if (App->enemies->enemies[i]->collider->Intersects(r)) {
								App->enemies->enemiesSmashed[i] = true;

							}
						}
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
							App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
							App->particles->AddParticle(fourHundredParticle, App->tilemap->positionDiamond.x - 4, App->tilemap->positionDiamond.y, Collider::Type::NONE, 0);
							App->player->score += 400;
							delete App->enemies->enemies[i];
							App->enemies->enemies[i] = nullptr;
							App->scene->enemiesAlive--;
							App->enemies->enemiesSmashed[i] = false;
							smashedEnemy = false;



						}
					}

				}

			}
			else if (App->tilemap->dirDiamond == RIGHT) {
				smashedEnemy = true;


				position.x = App->tilemap->positionDiamond.x + 16;
				position.y = App->tilemap->positionDiamond.y;
				currentAnim = &dragEnemyRightAnim;
				if (App->tilemap->positionDiamond.x >= (App->tilemap->finalpositionX - 16) && App->tilemap->positionDiamond.x < App->tilemap->finalpositionX_diamond) {
					position.x = App->tilemap->positionDiamond.x;
					position.y = App->tilemap->positionDiamond.y;
					currentAnim = &firstSmashRightAnim;
				}
				if (App->tilemap->positionDiamond.x == App->tilemap->finalpositionX_diamond - 4) {
					currentAnim = &secondSmashRightAnim;
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr) {
							if (App->enemies->enemies[i]->collider->Intersects(r)) {
								App->enemies->enemiesSmashed[i] = true;
							}
						}
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
							App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
							App->particles->AddParticle(fourHundredParticle, App->tilemap->positionDiamond.x + 4, App->tilemap->positionDiamond.y, Collider::Type::NONE, 0);
							App->player->score += 400;
							delete App->enemies->enemies[i];
							App->enemies->enemies[i] = nullptr;
							App->scene->enemiesAlive--;
							App->enemies->enemiesSmashed[i] = false;
							smashedEnemy = false;

						}
					}
				}

			}
			else if (App->tilemap->dirDiamond == UP) {
				smashedEnemy = true;

				position.x = App->tilemap->positionDiamond.x;
				position.y = App->tilemap->positionDiamond.y - 16;
				currentAnim = &dragEnemyUpAnim;
				if (App->tilemap->positionDiamond.y <= (App->tilemap->finalpositionY_diamond + 16) && App->tilemap->positionDiamond.y > App->tilemap->finalpositionY_diamond) {
					position.x = App->tilemap->positionDiamond.x;
					position.y = App->tilemap->positionDiamond.y;
					currentAnim = &firstSmashUpAnim;

				}
				if (App->tilemap->positionDiamond.y == App->tilemap->finalpositionY_diamond + 4) {
					currentAnim = &secondSmashUpAnim;
					for (uint i = 0; i < MAX_ENEMIES; ++i)
					{
						if (App->enemies->enemies[i] != nullptr) {
							if (App->enemies->enemies[i]->collider->Intersects(r)) {
								App->enemies->enemiesSmashed[i] = true;
							}
						}
						if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
							App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
							App->particles->AddParticle(fourHundredParticle, App->tilemap->positionDiamond.x, App->tilemap->positionDiamond.y - 4, Collider::Type::NONE, 0);
							App->player->score += 400;
							delete App->enemies->enemies[i];
							App->enemies->enemies[i] = nullptr;
							App->scene->enemiesAlive--;
							App->enemies->enemiesSmashed[i] = false;
							smashedEnemy = false;
						}
					}
				}
			}

		}
		else if (App->tilemap->dirDiamond == DOWN) {
			smashedEnemy = true;

			position.x = App->tilemap->positionDiamond.x;
			position.y = App->tilemap->positionDiamond.y + 16;
			currentAnim = &dragEnemyDownAnim;
			if (App->tilemap->positionDiamond.y >= (App->tilemap->finalpositionY_diamond - 16) && App->tilemap->positionDiamond.y < App->tilemap->finalpositionY_diamond) {
				position.x = App->tilemap->positionDiamond.x;
				position.y = App->tilemap->positionDiamond.y;
				currentAnim = &firstSmashDownAnim;
			}
			if (App->tilemap->positionDiamond.y == App->tilemap->finalpositionY_diamond - 4) {
				currentAnim = &secondSmashDownAnim;
				for (uint i = 0; i < MAX_ENEMIES; ++i)
				{
					if (App->enemies->enemies[i] != nullptr) {
						if (App->enemies->enemies[i]->collider->Intersects(r)) {
							App->enemies->enemiesSmashed[i] = true;
						}
					}
					if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
						App->audio->PlayFx(App->enemies->snobeeSmashedFx, 0);
						App->particles->AddParticle(fourHundredParticle, App->tilemap->positionDiamond.x, App->tilemap->positionDiamond.y + 4, Collider::Type::NONE, 0);
						App->player->score += 400;
						delete App->enemies->enemies[i];
						App->enemies->enemies[i] = nullptr;
						App->scene->enemiesAlive--;
						App->enemies->enemiesSmashed[i] = false;
						smashedEnemy = false;
					}
				}
			}
		}

	}

}


	bool Enemy_SnoBee::CleanUp()
	{
		



		return true;
	}
