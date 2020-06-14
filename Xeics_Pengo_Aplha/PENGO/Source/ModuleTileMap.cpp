#include "ModuleTileMap.h"

#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModuleScene.h"
#include "ModuleFonts.h"
#include "ModuleAudio.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/include/SDL.h>
#include "SDL/include/SDL_scancode.h"

ModuleTileMap::ModuleTileMap(bool start_enabled) : Module(start_enabled)
{
	blockAnim.PushBack({ 708, 0, 16, 16 });
	blockAnim.speed = 0.1f;

	diamondAnim.PushBack({ 708, 16, 16, 16 });
	diamondAnim.speed = 0.1f;

	twodiamondsAnim.PushBack({ 708, 16, 16, 16 });
	twodiamondsAnim.PushBack({ 708, 16, 16, 16 });
	twodiamondsAnim.PushBack({ 772, 32, 16, 16 });
	twodiamondsAnim.PushBack({ 772, 32, 16, 16 });
	twodiamondsAnim.speed = 0.2f;


	threediamondsAnim.PushBack({ 836, 16, 16, 16 });
	threediamondsAnim.PushBack({ 708, 16, 16, 16 });
	threediamondsAnim.PushBack({ 820, 16, 16, 16 });
	threediamondsAnim.PushBack({ 772, 32, 16, 16 });
	threediamondsAnim.PushBack({ 804, 16, 16, 16 });
	threediamondsAnim.PushBack({ 708, 16, 16, 16 });
	threediamondsAnim.PushBack({ 788, 16, 16, 16 });
	threediamondsAnim.PushBack({ 772, 32, 16, 16 });
	threediamondsAnim.PushBack({ 772, 16, 16, 16 });
	threediamondsAnim.PushBack({ 708, 16, 16, 16 });
	threediamondsAnim.PushBack({ 756, 16, 16, 16 });
	threediamondsAnim.PushBack({ 772, 32, 16, 16 });
	threediamondsAnim.PushBack({ 740, 16, 16, 16 });
	threediamondsAnim.PushBack({ 708, 16, 16, 16 });
	threediamondsAnim.PushBack({ 724, 16, 16, 16 });
	threediamondsAnim.PushBack({ 772, 32, 16, 16 });
	threediamondsAnim.speed = 0.4f;


	blockColoredAnim.PushBack({ 836, 0, 16, 16 });
	blockColoredAnim.PushBack({ 836, 0, 16, 16 });
	blockColoredAnim.PushBack({ 820, 0, 16, 16 });
	blockColoredAnim.PushBack({ 820, 0, 16, 16 });
	blockColoredAnim.PushBack({ 804, 0, 16, 16 });
	blockColoredAnim.PushBack({ 804, 0, 16, 16 });
	blockColoredAnim.PushBack({ 788, 0, 16, 16 });
	blockColoredAnim.PushBack({ 788, 0, 16, 16 });
	blockColoredAnim.PushBack({ 772, 0, 16, 16 });
	blockColoredAnim.PushBack({ 772, 0, 16, 16 });
	blockColoredAnim.PushBack({ 756, 0, 16, 16 });
	blockColoredAnim.PushBack({ 756, 0, 16, 16 });
	blockColoredAnim.PushBack({ 740, 0, 16, 16 });
	blockColoredAnim.PushBack({ 740, 0, 16, 16 });
	blockColoredAnim.PushBack({ 724, 0, 16, 16 });
	blockColoredAnim.PushBack({ 724, 0, 16, 16 });
	blockColoredAnim.speed = 0.4f;


	blockDestrAnim.PushBack({ 708, 48, 16, 16 });
	blockDestrAnim.PushBack({ 724, 48, 16, 16 });
	blockDestrAnim.PushBack({ 740, 48, 16, 16 });
	blockDestrAnim.PushBack({ 756, 48, 16, 16 });
	blockDestrAnim.PushBack({ 772, 48, 16, 16 });
	blockDestrAnim.PushBack({ 788, 48, 16, 16 });
	blockDestrAnim.PushBack({ 804, 48, 16, 16 });
	blockDestrAnim.PushBack({ 820, 48, 16, 16 });
	blockDestrAnim.PushBack({ 836, 48, 16, 16 });
	blockDestrAnim.loop = false;
	blockDestrAnim.speed = 0.2f;

	starsHorizontalRedAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalRedAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalRedAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalRedAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalRedAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalRedAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalRedAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalRedAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalRedAnim.speed = 0.2f;

	starsHorizontalGreenAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalGreenAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalGreenAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalGreenAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalGreenAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalGreenAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalGreenAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalGreenAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalGreenAnim.speed = 0.2f;

	starsHorizontalYellowAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalYellowAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalYellowAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalYellowAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalYellowAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalYellowAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalYellowAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalYellowAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalYellowAnim.speed = 0.2f;

	starsHorizontalPinkAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalPinkAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalPinkAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalPinkAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalPinkAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalPinkAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalPinkAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalPinkAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalPinkAnim.speed = 0.2f;

	starsHorizontalOrangeAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalOrangeAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalOrangeAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalOrangeAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalOrangeAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalOrangeAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalOrangeAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalOrangeAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalOrangeAnim.speed = 0.2f;


	starsHorizontalSoftYellowAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalSoftYellowAnim.speed = 0.4f;


	starsHorizontalPurpleAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalPurpleAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalPurpleAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalPurpleAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalPurpleAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalPurpleAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalPurpleAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalPurpleAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalPurpleAnim.speed = 0.2f;


	starsHorizontalBlueAnim.PushBack({ 968, 0, 16, 8 });
	starsHorizontalBlueAnim.PushBack({ 952, 0, 16, 8 });
	starsHorizontalBlueAnim.PushBack({ 936, 0, 16, 8 });
	starsHorizontalBlueAnim.PushBack({ 920, 0, 16, 8 });
	starsHorizontalBlueAnim.PushBack({ 904, 0, 16, 8 });
	starsHorizontalBlueAnim.PushBack({ 888, 0, 16, 8 });
	starsHorizontalBlueAnim.PushBack({ 872, 0, 16, 8 });
	starsHorizontalBlueAnim.PushBack({ 856, 0, 16, 8 });
	starsHorizontalBlueAnim.speed = 0.2f;


	starsVerticalRedAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalRedAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalRedAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalRedAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalRedAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalRedAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalRedAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalRedAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalRedAnim.speed = 0.2f;


	starsVerticalGreenAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalGreenAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalGreenAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalGreenAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalGreenAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalGreenAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalGreenAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalGreenAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalGreenAnim.speed = 0.2f;


	starsVerticalYellowAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalYellowAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalYellowAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalYellowAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalYellowAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalYellowAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalYellowAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalYellowAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalYellowAnim.speed = 0.2f;


	starsVerticalPinkAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalPinkAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalPinkAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalPinkAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalPinkAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalPinkAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalPinkAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalPinkAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalPinkAnim.speed = 0.2f;


	starsVerticalOrangeAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalOrangeAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalOrangeAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalOrangeAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalOrangeAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalOrangeAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalOrangeAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalOrangeAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalOrangeAnim.speed = 0.2f;


	starsVerticalSoftYellowAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalSoftYellowAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalSoftYellowAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalSoftYellowAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalSoftYellowAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalSoftYellowAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalSoftYellowAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalSoftYellowAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalSoftYellowAnim.speed = 0.2f;


	starsVerticalPurpleAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalPurpleAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalPurpleAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalPurpleAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalPurpleAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalPurpleAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalPurpleAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalPurpleAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalPurpleAnim.speed = 0.2f;


	starsVerticalBlueAnim.PushBack({ 856, 40, 8, 16 });
	starsVerticalBlueAnim.PushBack({ 856, 56, 8, 16 });
	starsVerticalBlueAnim.PushBack({ 856, 72, 8, 16 });
	starsVerticalBlueAnim.PushBack({ 856, 88, 8, 16 });
	starsVerticalBlueAnim.PushBack({ 856, 104, 8, 16 });
	starsVerticalBlueAnim.PushBack({ 856, 120, 8, 16 });
	starsVerticalBlueAnim.PushBack({ 856, 136, 8, 16 });
	starsVerticalBlueAnim.PushBack({ 856, 24, 8, 16 });
	starsVerticalBlueAnim.speed = 0.2f;



	sidesWallAnim.PushBack({ 684, 0, 8, 256 });
	sidesWallAnim.PushBack({ 696, 0, 8, 256 });
	sidesWallAnim.PushBack({ 684, 0, 8, 256 });
	sidesWallAnim.PushBack({ 696, 0, 8, 256 });
	sidesWallAnim.loop = false;
	sidesWallAnim.speed = 0.1f;

	topbotWallAnim.PushBack({ 456, 260, 224, 8 });
	topbotWallAnim.PushBack({ 456, 272, 224, 8 });
	topbotWallAnim.PushBack({ 456, 260, 224, 8 });
	topbotWallAnim.PushBack({ 456, 272, 224, 8 });
	topbotWallAnim.loop = false;
	topbotWallAnim.speed = 0.1f;

	nextSpawnBlock.PushBack({ 724, 0, 16, 16 });
	nextSpawnBlock.PushBack({ 708, 0, 16, 16 });
	nextSpawnBlock.PushBack({ 724, 0, 16, 16 });
	nextSpawnBlock.PushBack({ 708, 0, 16, 16 });
	nextSpawnBlock.PushBack({ 724, 0, 16, 16 });
	nextSpawnBlock.PushBack({ 708, 0, 16, 16 });
	nextSpawnBlock.loop = false;
	nextSpawnBlock.speed = 0.1f;

	if (scenelvl1 || scenelvl9) {
		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 16, 128, 16, 16 });
		spawnFromBlock.PushBack({ 64, 144, 16, 16 });
		spawnFromBlock.PushBack({ 32, 128, 16, 16 });
		spawnFromBlock.PushBack({ 48, 128, 16, 16 });
		spawnFromBlock.PushBack({ 64, 128, 16, 16 });
		spawnFromBlock.PushBack({ 80, 128, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;

	}
	if (scenelvl2 || scenelvl10) {
		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 144, 128, 16, 16 });
		spawnFromBlock.PushBack({ 192, 144, 16, 16 });
		spawnFromBlock.PushBack({ 160, 128, 16, 16 });
		spawnFromBlock.PushBack({ 176, 128, 16, 16 });
		spawnFromBlock.PushBack({ 192, 128, 16, 16 });
		spawnFromBlock.PushBack({ 208, 128, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;

	}
	if (scenelvl3 || scenelvl11) {
		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 272, 128, 16, 16 });
		spawnFromBlock.PushBack({ 320, 144, 16, 16 });
		spawnFromBlock.PushBack({ 288, 128, 16, 16 });
		spawnFromBlock.PushBack({ 304, 128, 16, 16 });
		spawnFromBlock.PushBack({ 320, 128, 16, 16 });
		spawnFromBlock.PushBack({ 336, 128, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;


	}

	if (scenelvl4 || scenelvl12) {
		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 400, 128, 16, 16 });
		spawnFromBlock.PushBack({ 448, 144, 16, 16 });
		spawnFromBlock.PushBack({ 416, 128, 16, 16 });
		spawnFromBlock.PushBack({ 432, 128, 16, 16 });
		spawnFromBlock.PushBack({ 448, 128, 16, 16 });
		spawnFromBlock.PushBack({ 464, 128, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;

	}
	if (scenelvl5 || scenelvl13) {
		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 16, 208, 16, 16 });
		spawnFromBlock.PushBack({ 64, 224, 16, 16 });
		spawnFromBlock.PushBack({ 32, 208, 16, 16 });
		spawnFromBlock.PushBack({ 48, 208, 16, 16 });
		spawnFromBlock.PushBack({ 64, 208, 16, 16 });
		spawnFromBlock.PushBack({ 80, 208, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;


	}
	if (scenelvl6 || scenelvl14) {
		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 144, 208, 16, 16 });
		spawnFromBlock.PushBack({ 192, 224, 16, 16 });
		spawnFromBlock.PushBack({ 160, 208, 16, 16 });
		spawnFromBlock.PushBack({ 176, 208, 16, 16 });
		spawnFromBlock.PushBack({ 192, 208, 16, 16 });
		spawnFromBlock.PushBack({ 208, 208, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;


	}
	if (scenelvl7 || scenelvl15) {

		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 272, 208, 16, 16 });
		spawnFromBlock.PushBack({ 320, 224, 16, 16 });
		spawnFromBlock.PushBack({ 288, 208, 16, 16 });
		spawnFromBlock.PushBack({ 304, 208, 16, 16 });
		spawnFromBlock.PushBack({ 320, 208, 16, 16 });
		spawnFromBlock.PushBack({ 336, 208, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;
	}

	if (scenelvl8) {
		spawnFromBlock.PushBack({ 576, 224, 16, 16 });
		spawnFromBlock.PushBack({ 400, 208, 16, 16 });
		spawnFromBlock.PushBack({ 448, 224, 16, 16 });
		spawnFromBlock.PushBack({ 416, 208, 16, 16 });
		spawnFromBlock.PushBack({ 432, 208, 16, 16 });
		spawnFromBlock.PushBack({ 448, 208, 16, 16 });
		spawnFromBlock.PushBack({ 464, 208, 16, 16 });
		spawnFromBlock.speed = 0.1f;
		spawnFromBlock.loop = false;

	}
	source.x = source.y = 0;
	source.w = source.h = 16;
	destination.w = destination.h = 16;
	destination.x = destination.y = 0;
}

ModuleTileMap::~ModuleTileMap()
{

}

bool ModuleTileMap::Start()
{
	texture = App->textures->Load("Assets/Blocks.png");
	scTexture = App->textures->Load("Assets/Score.png");
	chTexture = App->textures->Load("Assets/Characters.png");
	stoppedBlockFx = App->audio->LoadFx("Assets/Audio/Block Stopped.wav");
	threeDiamondsFx = App->audio->LoadFx("Assets/Audio/threeDiamonds.wav");
	countingbonusFx = App->audio->LoadFx("Assets/Audio/CountingBonusPoints.wav");

	noBlock = App->textures->Load("Assets/noBlock.png");
	Block = App->textures->Load("Assets/Block.png");
	Diamond = App->textures->Load("Assets/Diamond.png");

	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;
	blueFont = App->fonts->Load("Assets/blueFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;
	yellowFont = App->fonts->Load("Assets/yellowFont.png", lookupTable, 3);
	++activeFonts; ++totalFonts;

	if (!App->player->destroyed) {
		if (scenelvl1) {
			LoadMap(lvl1);
		}
		else if (scenelvl2) {
			LoadMap(lvl2);
		}
		else if (scenelvl3) {
			LoadMap(lvl3);
		}
		else if (scenelvl4) {
			LoadMap(lvl4);
		}
		else if (scenelvl5) {
			LoadMap(lvl5);
		}
		else if (scenelvl6) {
			LoadMap(lvl6);
		}
		else if (scenelvl7) {
			LoadMap(lvl7);
		}
		else if (scenelvl8) {
			LoadMap(lvl8);
		}
		else if (scenelvl9) {
			LoadMap(lvl9);
		}
		else if (scenelvl10) {
			LoadMap(lvl10);
		}
		else if (scenelvl11) {
			LoadMap(lvl11);
		}
		else if (scenelvl12) {
			LoadMap(lvl2);
		}
		else if (scenelvl13) {
			LoadMap(lvl13);
		}
		else if (scenelvl14) {
			LoadMap(lvl14);
		}
		else if (scenelvl15) {
			LoadMap(lvl15);
		}
	}

	else {
		LoadMap(tilemap);
	}

	oneTimeFx = false;
	oneTime2Fx = false;

	return true;
}

void ModuleTileMap::LoadMap(int arr[17][15])
{
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 15; j++) {
			tilemap[i][j] = arr[i][j];
		}
	}
}

void ModuleTileMap::DrawMap()
{
	int type = 0;

	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 15; j++) {
			type = tilemap[i][j];

			destination.x = j * 16;
			destination.y = 16 + i * 16;
			//App->render->Blit(Block, destination.x, destination.y, &source);
			switch (type)
			{
			case TILE_NOBLOCK:
				App->render->Blit(noBlock, destination.x, destination.y, &source);
				break;

			case TILE_BLOCK:
				App->render->Blit(Block, destination.x, destination.y, &source);
				break;

			case TILE_WALL:
				break;

			case TILE_DIAMOND:
				App->render->Blit(Diamond, destination.x, destination.y, &source);
				break;

			case TILE_CORNER:

				break;

			default:
				break;              //si treiem el break no compila
			}

		}
	}

}

bool ModuleTileMap::isWalkable(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_NOBLOCK)
	{
		valid = true;
	}
	LOG("pos x tile %d", posX);
	LOG("pos y tile %d", posY);
	return valid;

}

//bool ModuleTileMap::isWalkable_pixel(int x, int y)
//{
//	bool valid = false;
//
//	int posX;
//	int posY;
//	posX = x/16;
//	posY = (y-16)/16;
//
//	if (tilemap[posY][posX] == TILE_NOBLOCK)
//	{
//		valid = true;
//	}
//	
//	return valid;
//}

bool ModuleTileMap::thereIsABlock(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_BLOCK)
	{
		valid = true;
	}

	return valid;
}

bool ModuleTileMap::thereIsAWall(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_WALL)
	{
		valid = true;
	}

	return valid;
}

bool ModuleTileMap::thereIsADiamond(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_DIAMOND)
	{
		valid = true;
	}

	return valid;
}

bool ModuleTileMap::thereIsEnemy(int x, int y)
{
	bool valid = false;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;

	if (tilemap[posY][posX] == TILE_ENEMY)
	{
		valid = true;
	}
	return valid;
}

int ModuleTileMap::spaceToBlock(int x, int y, Direction d) {
	int space = 0;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;


	if (d == LEFT) {
		while (tilemap[posY][posX - 1] == TILE_NOBLOCK) {
			space++;
			posX--;
		}
	}
	else if (d == RIGHT) {
		while (tilemap[posY][posX + 1] == TILE_NOBLOCK) {
			space++;
			posX++;
		}
	}
	else if (d == DOWN) {
		while (tilemap[posY + 1][posX] == TILE_NOBLOCK) {
			space++;
			posY++;
		}
	}
	else if (d == UP) {
		while (tilemap[posY - 1][posX] == TILE_NOBLOCK) {
			space++;
			posY--;
		}
	}

	return space;

}

int ModuleTileMap::spaceToWall(int x, int y, Direction d) {
	int space = 0;
	int posX;
	int posY;
	posX = x / 16;
	posY = (y - 16) / 16;


	if (d == LEFT) {
		while (tilemap[posY][posX - 1] == TILE_NOBLOCK || tilemap[posY][posX - 1] == TILE_BLOCK) {
			space++;
			posX--;
		}
	}
	else if (d == RIGHT) {
		while (tilemap[posY][posX + 1] == TILE_NOBLOCK || tilemap[posY][posX + 1] == TILE_BLOCK) {
			space++;
			posX++;
		}
	}
	else if (d == DOWN) {
		while (tilemap[posY + 1][posX] == TILE_NOBLOCK || tilemap[posY + 1][posX] == TILE_BLOCK) {
			space++;
			posY++;
		}
	}
	else if (d == UP) {
		while (tilemap[posY - 1][posX] == TILE_NOBLOCK || tilemap[posY - 1][posX] == TILE_BLOCK) {
			space++;
			posY--;
		}
	}

	return space;

}


void ModuleTileMap::DestroyBlock(int x, int y)
{
	blockX = x / 16;
	blockY = (y - 16) / 16;

	destroyedBlock = true;
	currentAnimation = &blockDestrAnim;

	destroyedAnimBlock = false;
}

void ModuleTileMap::DestroyBlock2(int x, int y)
{
	block2X = x / 16;
	block2Y = (y - 16) / 16;

	destroyedBlock2 = true;
}

void ModuleTileMap::DestroyBlock3(int x, int y)
{
	block3X = x / 16;
	block3Y = (y - 16) / 16;

	destroyedBlock3 = true;
}

void ModuleTileMap::DestroyBlock4(int x, int y)
{
	block4X = x / 16;
	block4Y = (y - 16) / 16;

	destroyedBlock4 = true;
}

void ModuleTileMap::nextBlockSpawn1(int x, int y)
{
	nextSpawnX = x / 16;
	nextSpawnY = (y - 16) / 16;

	nextBlock1 = true;
}

void ModuleTileMap::nextBlockSpawn2(int x, int y)
{
	nextSpawn2X = x / 16;
	nextSpawn2Y = (y - 16) / 16;

	nextBlock2 = true;
}
void ModuleTileMap::nextBlockSpawn3(int x, int y)
{
	nextSpawn3X = x / 16;
	nextSpawn3Y = (y - 16) / 16;

	nextBlock3 = true;
}
void ModuleTileMap::nextBlockSpawn4(int x, int y)
{
	nextSpawn4X = x / 16;
	nextSpawn4Y = (y - 16) / 16;

	nextBlock4 = true;
}
void ModuleTileMap::nextBlockSpawn5(int x, int y)
{
	nextSpawn5X = x / 16;
	nextSpawn5Y = (y - 16) / 16;

	nextBlock5 = true;
}
void ModuleTileMap::nextBlockSpawn6(int x, int y)
{
	nextSpawn6X = x / 16;
	nextSpawn6Y = (y - 16) / 16;

	nextBlock6 = true;
}void ModuleTileMap::nextBlockSpawn7(int x, int y)
{
	nextSpawn7X = x / 16;
	nextSpawn7Y = (y - 16) / 16;

	nextBlock7 = true;
}
void ModuleTileMap::nextBlockSpawn8(int x, int y)
{
	nextSpawn8X = x / 16;
	nextSpawn8Y = (y - 16) / 16;

	nextBlock8 = true;
}

void ModuleTileMap::MoveBlock(int x, int y, Direction d)
{
	positionBlock.x = x;
	positionBlock.y = y;

	movedBlockX = x / 16;
	movedBlockY = (y - 16) / 16;

	dirBlock = d;

	spacestoblock = spaceToBlock(positionBlock.x, positionBlock.y, dirBlock);

	if (dirBlock == LEFT) {
		finalpositionX = x - (spacestoblock * 16);
	}
	else if (dirBlock == RIGHT) {
		finalpositionX = x + (spacestoblock * 16);
	}
	else if (dirBlock == UP) {
		finalpositionY = y - (spacestoblock * 16);
	}
	else if (dirBlock == DOWN) {
		finalpositionY = y + (spacestoblock * 16);
	}
	collider = App->collisions->AddCollider({ positionBlock.x, positionBlock.y, 16, 16 }, Collider::Type::BLOCK, (Module*)App->blocks);

	tilemap[movedBlockY][movedBlockX] = TILE_NOBLOCK;
}





void ModuleTileMap::MoveDiamond(int x, int y, Direction d)
{
	positionDiamond.x = x;
	positionDiamond.y = y;

	movedDiamondX = x / 16;
	movedDiamondY = (y - 16) / 16;

	dirDiamond = d;

	spacestoblock_diamond = spaceToBlock(positionDiamond.x, positionDiamond.y, dirDiamond);

	if (dirDiamond == LEFT) {
		finalpositionX_diamond = x - (spacestoblock_diamond * 16);
	}
	else if (dirDiamond == RIGHT) {
		finalpositionX_diamond = x + (spacestoblock_diamond * 16);
	}
	else if (dirDiamond == UP) {
		finalpositionY_diamond = y - (spacestoblock_diamond * 16);
	}
	else if (dirDiamond == DOWN) {
		finalpositionY_diamond = y + (spacestoblock_diamond * 16);
	}
	colliderDiamond = App->collisions->AddCollider({ positionDiamond.x, positionDiamond.y, 16, 16 }, Collider::Type::DIAMOND, (Module*)App->blocks);

	tilemap[movedDiamondY][movedDiamondX] = TILE_NOBLOCK;

}

void ModuleTileMap::PushLeftWall()
{
	pushLeft = true;
}
void ModuleTileMap::PushRightWall()
{
	pushRight = true;
}
void ModuleTileMap::PushUpWall()
{
	pushUp = true;
}
void ModuleTileMap::PushDownWall()
{
	pushDown = true;
}

void ModuleTileMap::checkDiamonds() {
	twoDiamonds = false;
	//threeDiamonds = false;

	if (App->input->keys[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN) {
		twoDiamonds = false;
		threeDiamonds = true;
		timeDiamond = 1;
	}


	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 15; j++) {
			if (tilemap[i][j] == TILE_DIAMOND) {
				if (tilemap[i + 1][j] == TILE_DIAMOND && !threeDiamondsDone) {
					twoDiamonds = true;
					if (tilemap[i + 2][j] == TILE_DIAMOND || tilemap[i - 1][j] == TILE_DIAMOND) {
						twoDiamonds = false;
						threeDiamonds = true;
						threeDiamondsAnimation = true;
						timeDiamond = 1;
						threeDiamondsDone = true;
						timeDiamondStunned = 1;
					}
				}
				else if (tilemap[i - 1][j] == TILE_DIAMOND && !threeDiamondsDone) {
					twoDiamonds = true;
					if (tilemap[i - 2][j] == TILE_DIAMOND || tilemap[i + 1][j] == TILE_DIAMOND) {
						twoDiamonds = false;
						threeDiamonds = true;
						threeDiamondsAnimation = true;
						timeDiamond = 1;
						threeDiamondsDone = true;
						timeDiamondStunned = 1;
					}
				}
				else if (tilemap[i][j + 1] == TILE_DIAMOND && !threeDiamondsDone) {
					twoDiamonds = true;
					if (tilemap[i][j + 2] == TILE_DIAMOND || tilemap[i][j - 1] == TILE_DIAMOND) {
						twoDiamonds = false;
						threeDiamonds = true;
						threeDiamondsAnimation = true;
						timeDiamond = 1;
						threeDiamondsDone = true;
						timeDiamondStunned = 1;
					}
				}
				else if (tilemap[i][j - 1] == TILE_DIAMOND && !threeDiamondsDone) {
					twoDiamonds = true;
					if (tilemap[i][j - 2] == TILE_DIAMOND || tilemap[i][j + 1] == TILE_DIAMOND) {
						twoDiamonds = false;
						threeDiamonds = true;
						threeDiamondsAnimation = true;
						timeDiamond = 1;
						threeDiamondsDone = true;
						timeDiamondStunned = 1;
					}
				}
			}
		}
	}



}

void ModuleTileMap::spawnfromBlock1(int x, int y) {
	posSpawnX = x;
	posSpawnY = y;

	spawn1 = true;
}

void ModuleTileMap::spawnfromBlock2(int x, int y) {
	posSpawn2X = x;
	posSpawn2Y = y;

	spawn2 = true;
}

void ModuleTileMap::spawnfromBlock3(int x, int y) {
	posSpawn3X = x;
	posSpawn3Y = y;

	spawn3 = true;
}

void ModuleTileMap::spawnfromBlock4(int x, int y) {
	posSpawn4X = x;
	posSpawn4Y = y;

	spawn4 = true;
}

void ModuleTileMap::MouseState() {

	SDL_GetMouseState(&mousePositionX, &mousePositionY);

	while (mousePositionX % 16 != 0) {
		mousePositionX--;
	}
	while (mousePositionY % 16 != 0) {
		mousePositionY--;
	}
	if (mousePositionX > 16 * SCREEN_SIZE && mousePositionX < 224 * SCREEN_SIZE && mousePositionY > 32 * SCREEN_SIZE && mousePositionY < 272 * SCREEN_SIZE) {

		if (App->input->keys[SDL_SCANCODE_Z] == KEY_STATE::KEY_DOWN) {

			if (mousePositionX % 16 == 0 && mousePositionY % 16 == 0) {

				iBlock = (mousePositionX / SCREEN_SIZE) / 16;
				jBlock = ((mousePositionY / SCREEN_SIZE) - 16) / 16;
				if (tilemap[jBlock][iBlock] == TILE_NOBLOCK) {
					tilemap[jBlock][iBlock] = TILE_BLOCK;
				}
			}

		}
		if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN) {

			if (mousePositionX % 16 == 0 && mousePositionY % 16 == 0) {

				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_DESTROYER, mousePositionX / SCREEN_SIZE, mousePositionY / SCREEN_SIZE);

				App->scene->enemiesAlive++;

			}
		}
		if (App->input->keys[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN) {

			if (mousePositionX % 16 == 0 && mousePositionY % 16 == 0) {

				App->enemies->AddEnemy(ENEMY_TYPE::SNOBEE_NORMAL, mousePositionX / SCREEN_SIZE, mousePositionY / SCREEN_SIZE);

				App->scene->enemiesAlive++;

			}
		}
	}
}

update_status ModuleTileMap::Update()
{

	if (!App->player->destroyed) {
		MouseState();
	}

	/*if(counter % 10==0) {
		tilemap[counter/10][1] = 1;
	}
	counter++;*/

	//tilemap[1][1]=1;


	/*int posXplayer;
	int posYplayer;
	posXplayer = (App->player->position.x) / 16;
	posYplayer = ((App->player->position.y) - 16) / 16;

	tilemap[posYplayer][posXplayer] = TILE_PLAYER;*/

	if (destroyedBlock || destroyedBlock2 || destroyedBlock3 || destroyedBlock4) {
		blockDestrAnim.Update();
		if (blockDestrAnim.HasFinished()) {
			destroyedBlock = false;
			destroyedBlock2 = false;
			destroyedBlock3 = false;
			destroyedBlock4 = false;
			destroyedAnimBlock = true;
			blockDestrAnim.Reset();
			tilemap[blockY][blockX] = TILE_NOBLOCK;
		}
		else {
			destroyedAnimBlock = true;
			tilemap[blockY][blockX] = TILE_NOBLOCK;
		}
	}

	if (nextBlock1 || nextBlock2 || nextBlock3 || nextBlock4 || nextBlock5 || nextBlock6 || nextBlock7 || nextBlock8) {
		nextSpawnBlock.Update();
		if (nextSpawnBlock.HasFinished()) {
			nextBlock1 = false;
			nextBlock2 = false;
			nextBlock3 = false;
			nextBlock4 = false;
			nextBlock5 = false;
			nextBlock6 = false;
			nextBlock7 = false;
			nextBlock8 = false;
			nextSpawnBlock.Reset();
		}
	}



	if (pushLeft) {
		sidesWallAnim.Update();
		if (sidesWallAnim.HasFinished()) {
			pushLeft = false;
			sidesWallAnim.Reset();
		}
	}
	if (pushRight) {
		sidesWallAnim.Update();
		if (sidesWallAnim.HasFinished()) {
			pushRight = false;
			sidesWallAnim.Reset();
		}
	}
	if (pushUp) {
		topbotWallAnim.Update();
		if (topbotWallAnim.HasFinished()) {
			pushUp = false;
			topbotWallAnim.Reset();
		}
	}
	if (pushDown) {
		topbotWallAnim.Update();
		if (topbotWallAnim.HasFinished()) {
			pushDown = false;
			topbotWallAnim.Reset();
		}
	}

	if (spawn1 || spawn2 || spawn3 || spawn4) {
		spawnFromBlock.Update();
		if (spawnFromBlock.HasFinished()) {
			spawn1 = false;
			spawn2 = false;
			spawn3 = false;
			spawn4 = false;
			spawnFromBlock.Reset();
		}
	}



	if (dirBlock != NOMOVE)
	{

		if (dirBlock == LEFT) {
			if (positionBlock.x % 16 == 0) {
				movedBlockX--;

			}
			positionBlock.x -= 4;

			if (positionBlock.x == finalpositionX) {
				dirBlock = NOMOVE;
				tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				App->collisions->RemoveCollider(collider);
				App->audio->PlayFx(stoppedBlockFx, 0);
			}
		}

		else if (dirBlock == RIGHT) {
			if (positionBlock.x % 16 == 0) {
				movedBlockX++;
			}
			positionBlock.x += 4;
			if (positionBlock.x == finalpositionX) {
				dirBlock = NOMOVE;
				tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				App->collisions->RemoveCollider(collider);
				App->audio->PlayFx(stoppedBlockFx, 0);
			}
		}

		else if (dirBlock == UP) {
			if (positionBlock.y % 16 == 0) {
				movedBlockY--;
			}
			positionBlock.y -= 4;
			if (positionBlock.y == finalpositionY) {
				dirBlock = NOMOVE;
				tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				App->collisions->RemoveCollider(collider);
				App->audio->PlayFx(stoppedBlockFx, 0);
			}
		}

		else if (dirBlock == DOWN) {
			if (positionBlock.y % 16 == 0) {
				movedBlockY++;
			}
			positionBlock.y += 4;
			if (positionBlock.y == finalpositionY) {
				dirBlock = NOMOVE;
				tilemap[movedBlockY][movedBlockX] = TILE_BLOCK;
				App->collisions->RemoveCollider(collider);
				App->audio->PlayFx(stoppedBlockFx, 0);
			}
		}
		collider->SetPos(positionBlock.x, positionBlock.y);

	}

	if (dirDiamond != NOMOVE)
	{

		if (dirDiamond == LEFT) {
			if (positionDiamond.x != finalpositionX_diamond) {
				if (positionDiamond.x % 16 == 0) {
					movedDiamondX--;
				}
				positionDiamond.x -= 4;
			}
			if (positionDiamond.x == finalpositionX_diamond) {
				dirDiamond = NOMOVE;
				tilemap[movedDiamondY][movedDiamondX] = TILE_DIAMOND;
				App->collisions->RemoveCollider(colliderDiamond);
			}
		}

		else if (dirDiamond == RIGHT) {
			if (positionDiamond.x != finalpositionX_diamond) {
				if (positionDiamond.x % 16 == 0) {
					movedDiamondX++;
				}
				positionDiamond.x += 4;
			}
			if (positionDiamond.x == finalpositionX_diamond) {
				dirDiamond = NOMOVE;
				tilemap[movedDiamondY][movedDiamondX] = TILE_DIAMOND;
				App->collisions->RemoveCollider(colliderDiamond);
			}
		}

		else if (dirDiamond == UP) {
			if (positionDiamond.y != finalpositionY_diamond) {
				if (positionDiamond.y % 16 == 0) {
					movedDiamondY--;
				}
				positionDiamond.y -= 4;
			}

			if (positionDiamond.y == finalpositionY_diamond) {
				dirDiamond = NOMOVE;
				tilemap[movedDiamondY][movedDiamondX] = TILE_DIAMOND;
				App->collisions->RemoveCollider(colliderDiamond);
			}
		}

		else if (dirDiamond == DOWN) {
			if (positionDiamond.y != finalpositionY_diamond) {
				if (positionDiamond.y % 16 == 0) {
					movedDiamondY++;
				}
				positionDiamond.y += 4;
			}
			if (positionDiamond.y == finalpositionY_diamond) {
				dirDiamond = NOMOVE;
				tilemap[movedDiamondY][movedDiamondX] = TILE_DIAMOND;
				App->collisions->RemoveCollider(colliderDiamond);
			}
		}
		colliderDiamond->SetPos(positionDiamond.x, positionDiamond.y);
	}


	checkDiamonds();

	if (timeDiamond != 0) {
		timeDiamond++;
		if (!oneTimeFx) {
			App->audio->PlayFx(threeDiamondsFx);

			oneTimeFx = true;
		}
		if (timeDiamond > 300 && timeDiamond <= 600) {

			threeDiamondsAnimation = false;
			bonusCounter = true;

		}
		if (timeDiamond > 600) {

			threeDiamonds = false;
			timeDiamond = 0;
			threeDiamondsDone = true;
			bonusCounter = false;
		}

	}
	if (bonusCounter) {
		if (!oneTime2Fx) {
			App->audio->PlayFx(countingbonusFx);

			oneTime2Fx = true;
		}
		if (scoreBonus > 0) {
			scoreBonus -= 50;
			App->player->score += 50;
		}
	}

	twodiamondsAnim.Update();
	threediamondsAnim.Update();
	blockColoredAnim.Update();

	starsHorizontalRedAnim.Update();
	starsHorizontalBlueAnim.Update();
	starsHorizontalPurpleAnim.Update();
	starsHorizontalYellowAnim.Update();
	starsHorizontalOrangeAnim.Update();
	starsHorizontalPinkAnim.Update();
	starsHorizontalSoftYellowAnim.Update();
	starsHorizontalGreenAnim.Update();

	starsVerticalRedAnim.Update();
	starsVerticalBlueAnim.Update();
	starsVerticalPurpleAnim.Update();
	starsVerticalYellowAnim.Update();
	starsVerticalOrangeAnim.Update();
	starsVerticalPinkAnim.Update();
	starsVerticalSoftYellowAnim.Update();
	starsVerticalGreenAnim.Update();


	return update_status::UPDATE_CONTINUE;
}


update_status ModuleTileMap::PostUpdate()
{

	if (spawn1) {
		App->render->Blit(chTexture, posSpawnX, posSpawnY, &(spawnFromBlock.GetCurrentFrame()), 0.1f);
	}
	if (spawn2) {
		App->render->Blit(chTexture, posSpawn2X, posSpawn2Y, &(spawnFromBlock.GetCurrentFrame()), 0.1f);
	}
	if (spawn3) {
		App->render->Blit(chTexture, posSpawn3X, posSpawn3Y, &(spawnFromBlock.GetCurrentFrame()), 0.1f);
	}
	if (spawn4) {
		App->render->Blit(chTexture, posSpawn4X, posSpawn4Y, &(spawnFromBlock.GetCurrentFrame()), 0.1f);
	}

	if (destroyedBlock) {
		App->render->Blit(texture, blockX * 16, (blockY * 16) + 16, &(blockDestrAnim.GetCurrentFrame()), 0.1f);
	}
	if (destroyedBlock2) {
		App->render->Blit(texture, block2X * 16, (block2Y * 16) + 16, &(blockDestrAnim.GetCurrentFrame()), 0.1f);
	}
	if (destroyedBlock3) {
		App->render->Blit(texture, block3X * 16, (block3Y * 16) + 16, &(blockDestrAnim.GetCurrentFrame()), 0.1f);
	}
	if (destroyedBlock4) {
		App->render->Blit(texture, block4X * 16, (block4Y * 16) + 16, &(blockDestrAnim.GetCurrentFrame()), 0.1f);
	}

	if (nextBlock1) {
		App->render->Blit(texture, nextSpawnX * 16, (nextSpawnY * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}
	if (nextBlock2) {
		App->render->Blit(texture, nextSpawn2X * 16, (nextSpawn2Y * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}
	if (nextBlock3) {
		App->render->Blit(texture, nextSpawn3X * 16, (nextSpawn3Y * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}
	if (nextBlock4) {
		App->render->Blit(texture, nextSpawn4X * 16, (nextSpawn4Y * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}
	if (nextBlock5) {
		App->render->Blit(texture, nextSpawn5X * 16, (nextSpawn5Y * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}
	if (nextBlock6) {
		App->render->Blit(texture, nextSpawn6X * 16, (nextSpawn6Y * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}
	if (nextBlock7) {
		App->render->Blit(texture, nextSpawn7X * 16, (nextSpawn7Y * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}
	if (nextBlock8) {
		App->render->Blit(texture, nextSpawn8X * 16, (nextSpawn8Y * 16) + 16, &(nextSpawnBlock.GetCurrentFrame()), 0.1f);
	}

	if (pushLeft) {
		App->render->Blit(texture, 8, 24, &(sidesWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (pushRight) {
		App->render->Blit(texture, 224, 24, &(sidesWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (pushUp) {
		App->render->Blit(texture, 8, 24, &(topbotWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (pushDown) {
		App->render->Blit(texture, 8, 272, &(topbotWallAnim.GetCurrentFrame()), 0.1f);
	}
	if (dirBlock != NOMOVE) {
		App->render->Blit(texture, positionBlock.x, positionBlock.y, &(blockAnim.GetCurrentFrame()), 0.2f);
	}

	if (dirDiamond != NOMOVE) {
		App->render->Blit(texture, positionDiamond.x, positionDiamond.y, &(diamondAnim.GetCurrentFrame()), 0.2f);
	}

	if (twoDiamonds) {
		for (int i = 0; i < 17; i++) {
			for (int j = 0; j < 15; j++) {
				if (tilemap[i][j] == TILE_DIAMOND) {
					App->render->Blit(texture, j * 16, i * 16 + 16, &(twodiamondsAnim.GetCurrentFrame()), 0.1f);
				}
			}
		}

	}

	if (threeDiamondsAnimation) {
		for (int i = 0; i < 17; i++) {
			for (int j = 0; j < 15; j++) {
				if (tilemap[i][j] == TILE_DIAMOND) {
					App->render->Blit(texture, j * 16, i * 16 + 16, &(threediamondsAnim.GetCurrentFrame()), 0.4f);
				}
				if (tilemap[i][j] == TILE_BLOCK) {
					App->render->Blit(texture, j * 16, i * 16 + 16, &(blockColoredAnim.GetCurrentFrame()), 0.4f);
				}

			}
		}
	}
	if (threeDiamonds) {
		App->render->Blit(texture, 8, 24, &(starsHorizontalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 24, 24, &(starsHorizontalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 40, 24, &(starsHorizontalYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 56, 24, &(starsHorizontalPinkAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 72, 24, &(starsHorizontalOrangeAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 88, 24, &(starsHorizontalSoftYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 104, 24, &(starsHorizontalPurpleAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 120, 24, &(starsHorizontalBlueAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 136, 24, &(starsHorizontalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 152, 24, &(starsHorizontalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 168, 24, &(starsHorizontalYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 184, 24, &(starsHorizontalPinkAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 200, 24, &(starsHorizontalOrangeAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 216, 24, &(starsHorizontalSoftYellowAnim.GetCurrentFrame()), 0.4f);

		App->render->Blit(texture, 8, 272, &(starsHorizontalYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 24, 272, &(starsHorizontalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 40, 272, &(starsHorizontalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 56, 272, &(starsHorizontalBlueAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 72, 272, &(starsHorizontalPurpleAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 88, 272, &(starsHorizontalSoftYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 104, 272, &(starsHorizontalOrangeAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 120, 272, &(starsHorizontalPinkAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 136, 272, &(starsHorizontalYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 152, 272, &(starsHorizontalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 168, 272, &(starsHorizontalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 184, 272, &(starsHorizontalBlueAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 200, 272, &(starsHorizontalPurpleAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 216, 272, &(starsHorizontalSoftYellowAnim.GetCurrentFrame()), 0.4f);

		App->render->Blit(texture, 224, 32, &(starsVerticalPurpleAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 48, &(starsVerticalBlueAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 64, &(starsVerticalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 80, &(starsVerticalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 96, &(starsVerticalYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 112, &(starsVerticalPinkAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 128, &(starsVerticalOrangeAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 144, &(starsVerticalSoftYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 160, &(starsVerticalPurpleAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 176, &(starsVerticalBlueAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 192, &(starsVerticalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 208, &(starsVerticalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 224, &(starsVerticalYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 240, &(starsVerticalPinkAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 224, 256, &(starsVerticalOrangeAnim.GetCurrentFrame()), 0.4f);

		App->render->Blit(texture, 8, 32, &(starsVerticalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 48, &(starsVerticalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 64, &(starsVerticalBlueAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 80, &(starsVerticalPurpleAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 96, &(starsVerticalSoftYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 112, &(starsVerticalOrangeAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 128, &(starsVerticalPinkAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 144, &(starsVerticalYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 160, &(starsVerticalGreenAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 176, &(starsVerticalRedAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 192, &(starsVerticalBlueAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 208, &(starsVerticalPurpleAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 224, &(starsVerticalSoftYellowAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 240, &(starsVerticalOrangeAnim.GetCurrentFrame()), 0.4f);
		App->render->Blit(texture, 8, 256, &(starsVerticalPinkAnim.GetCurrentFrame()), 0.4f);

	}

	if (bonusCounter) {
		sprintf_s(scoreBonusText, 10, "%d", scoreBonus);
		App->fonts->BlitText(88, 152, yellowFont, "bonus");
		App->fonts->BlitText(96, 160, whiteFont, scoreBonusText);
		App->fonts->BlitText(120, 168, blueFont, "pts.");

	}

	return update_status::UPDATE_CONTINUE;
}

bool ModuleTileMap::CleanUp()
{

	App->textures->Unload(texture);
	App->textures->Unload(scTexture);
	App->textures->Unload(chTexture);
	App->textures->Unload(noBlock);
	App->textures->Unload(Block);
	App->textures->Unload(Diamond);

	App->audio->UnloadFx(stoppedBlockFx);
	App->audio->UnloadFx(threeDiamondsFx);
	App->audio->UnloadFx(countingbonusFx);

	App->collisions->RemoveCollider(collider);
	App->collisions->RemoveCollider(colliderDiamond);

	App->fonts->UnLoad(whiteFont);
	App->fonts->UnLoad(blueFont);
	App->fonts->UnLoad(yellowFont);

	blockDestrAnim.Reset();
	blockAnim.Reset();
	blockColoredAnim.Reset();
	diamondAnim.Reset();
	twodiamondsAnim.Reset();
	threediamondsAnim.Reset();

	starsHorizontalRedAnim.Reset();
	starsHorizontalBlueAnim.Reset();
	starsHorizontalPurpleAnim.Reset();
	starsHorizontalYellowAnim.Reset();
	starsHorizontalOrangeAnim.Reset();
	starsHorizontalPinkAnim.Reset();
	starsHorizontalSoftYellowAnim.Reset();
	starsHorizontalGreenAnim.Reset();

	starsVerticalRedAnim.Reset();
	starsVerticalBlueAnim.Reset();
	starsVerticalPurpleAnim.Reset();
	starsVerticalYellowAnim.Reset();
	starsVerticalOrangeAnim.Reset();
	starsVerticalPinkAnim.Reset();
	starsVerticalSoftYellowAnim.Reset();
	starsVerticalGreenAnim.Reset();

	spawnFromBlock.Reset();
	sidesWallAnim.Reset();
	topbotWallAnim.Reset();
	spawnFromBlock.Reset();
	nextSpawnBlock.Reset();

	return true;
}


//
//
//void ModuleTileMap::OnCollision(Collider* c1, Collider* c2)
//{
//
//	if (c1->type == Collider::Type::BLOCK) {
//
//
//
//		if (c2->type == Collider::Type::ENEMY_STUNNED) {
//
//				if (dirBlock == LEFT) {
//					/*position.x = App->tilemap->positionBlock.x - 16;
//					currentAnim = &dragEnemyLeftAnim;
//					if (App->tilemap->positionBlock.x <= (App->tilemap->finalpositionX + 16) && App->tilemap->positionBlock.x > App->tilemap->finalpositionX) {
//						currentAnim = &firstSmashLeftAnim;
//					}
//					if (App->tilemap->positionBlock.x == App->tilemap->finalpositionX + 4) {
//						currentAnim = &secondSmashLeftAnim;*/
//					for (uint i = 0; i < MAX_ENEMIES; ++i)
//						{
//							if (App->enemies->enemies[i] != nullptr) {
//								if (App->enemies->enemies[i]->GetColliderStun() == c2) {
//									App->enemies->enemiesSmashed[i] = true;
//								}
//							}
//							if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
//								delete App->enemies->enemies[i];
//								App->enemies->enemies[i] = nullptr;
//								App->scene->enemiesAlive--;
//								App->enemies->enemiesSmashed[i] = false;
//								//smashedEnemy = false;
//							}
//						}
//
//					}
//
//				/*
//				else if (App->tilemap->dirBlock == RIGHT) {
//					smashedEnemy = true;
//
//
//					position.x = App->tilemap->positionBlock.x + 16;
//					currentAnim = &dragEnemyRightAnim;
//					if (App->tilemap->positionBlock.x >= (App->tilemap->finalpositionX - 16) && App->tilemap->positionBlock.x < App->tilemap->finalpositionX) {
//						currentAnim = &firstSmashRightAnim;
//					}
//					if (App->tilemap->positionBlock.x == App->tilemap->finalpositionX - 4) {
//						currentAnim = &secondSmashRightAnim;
//						for (uint i = 0; i < MAX_ENEMIES; ++i)
//						{
//							if (App->enemies->enemies[i] != nullptr) {
//								if (App->enemies->enemies[i]->GetColliderStun() == c1) {
//									App->enemies->enemiesSmashed[i] = true;
//								}
//							}
//							if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
//								delete App->enemies->enemies[i];
//								App->enemies->enemies[i] = nullptr;
//								App->scene->enemiesAlive--;
//								App->enemies->enemiesSmashed[i] = false;
//								smashedEnemy = false;
//							}
//						}
//					}
//
//				}
//				else if (App->tilemap->dirBlock == UP) {
//					smashedEnemy = true;
//
//
//					position.y = App->tilemap->positionBlock.y - 16;
//					currentAnim = &dragEnemyUpAnim;
//					if (App->tilemap->positionBlock.y <= (App->tilemap->finalpositionY + 16) && App->tilemap->positionBlock.y > App->tilemap->finalpositionY) {
//						currentAnim = &firstSmashUpAnim;
//					}
//					if (App->tilemap->positionBlock.y == App->tilemap->finalpositionY + 4) {
//						currentAnim = &secondSmashUpAnim;
//						for (uint i = 0; i < MAX_ENEMIES; ++i)
//						{
//							if (App->enemies->enemies[i] != nullptr) {
//								if (App->enemies->enemies[i]->GetColliderStun() == c1) {
//									App->enemies->enemiesSmashed[i] = true;
//								}
//							}
//							if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
//								delete App->enemies->enemies[i];
//								App->enemies->enemies[i] = nullptr;
//								App->scene->enemiesAlive--;
//								App->enemies->enemiesSmashed[i] = false;
//								smashedEnemy = false;
//							}
//						}
//					}
//
//				}
//				else if (App->tilemap->dirBlock == DOWN) {
//					smashedEnemy = true;
//
//
//					position.y = App->tilemap->positionBlock.y + 16;
//					currentAnim = &dragEnemyDownAnim;
//					if (App->tilemap->positionBlock.y >= (App->tilemap->finalpositionY - 16) && App->tilemap->positionBlock.y < App->tilemap->finalpositionY) {
//						currentAnim = &firstSmashDownAnim;
//					}
//					if (App->tilemap->positionBlock.y == App->tilemap->finalpositionY - 4) {
//						currentAnim = &secondSmashDownAnim;
//						for (uint i = 0; i < MAX_ENEMIES; ++i)
//						{
//							if (App->enemies->enemies[i] != nullptr) {
//								if (App->enemies->enemies[i]->GetColliderStun() == c1) {
//									App->enemies->enemiesSmashed[i] = true;
//								}
//							}
//							if (App->enemies->enemies[i] != nullptr && App->enemies->enemiesSmashed[i]) {
//								delete App->enemies->enemies[i];
//								App->enemies->enemies[i] = nullptr;
//								App->scene->enemiesAlive--;
//								App->enemies->enemiesSmashed[i] = false;
//								smashedEnemy = false;
//							}
//						}
//					}*/
//
//				}
//
//			}
//
//			
//	}
//

