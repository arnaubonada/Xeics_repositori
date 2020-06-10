#include "SceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include "SDL/include/SDL_scancode.h"

SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{
	name = "s intro";
}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;


	char lookupTable[] = { "0123456789.,&!'-©abcdefghijklmnopqrstuvwxyz.    " };
	whiteFont = App->fonts->Load("Assets/whiteFont.png", lookupTable, 3);
	blueFont = App->fonts->Load("Assets/blueFont.png", lookupTable, 3);

	bgTexture = App->textures->Load("Assets/startScreen.png");
	logo = App->textures->Load("Assets/Logoodef.png");

	App->audio->PlayMusic("Assets/Audio/Intermission.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->input->Enable();
	return ret;
}

update_status SceneIntro::Update()
{

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && contador == 3)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 30);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneIntro::PostUpdate()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		contador++;
	}


	if (contador == 0)
	{
		App->fonts->BlitText(18, 30, blueFont, "pengo is an arcade");
		App->fonts->BlitText(18, 50, blueFont, "game developed by");
		App->fonts->BlitText(18, 70, blueFont, "coreland and published");
		App->fonts->BlitText(18, 90, blueFont, "by sega in 1982.");
		App->fonts->BlitText(18, 130, whiteFont, "the playing field");
		App->fonts->BlitText(18, 150, whiteFont, "is a maze, where the");
		App->fonts->BlitText(18, 170, whiteFont, "player has to act");
		App->fonts->BlitText(18, 190, whiteFont, "quickly to escape and ");
		App->fonts->BlitText(18, 210, whiteFont, "defeat snobees.");

	}
	if (contador == 1)
	{
		App->render->Blit(logo, 13, 130, NULL);
		App->fonts->BlitText(18, 10, whiteFont, "we are xeics games, ");
		App->fonts->BlitText(18, 30, whiteFont, "and our members are");
		App->fonts->BlitText(18, 50, blueFont, "- arnau bonada");
		App->fonts->BlitText(18, 70, blueFont, "- andreu landa");
		App->fonts->BlitText(18, 90, blueFont, "- max llovera");
		App->fonts->BlitText(18, 110, blueFont, "- arnau ustrell");
	}
	if (contador == 2)
	{
		App->fonts->BlitText(88, 25, blueFont, "citm-upc");
		App->fonts->BlitText(18, 50, whiteFont, "disseny i desenvolupament");
		App->fonts->BlitText(72, 70, whiteFont, "de videojocs");
		App->fonts->BlitText(18, 130, whiteFont, "tutors");
		App->fonts->BlitText(18, 150, blueFont, "- jesus alonso");
		App->fonts->BlitText(18, 170, blueFont, "- marc garrigo");
	}
	if (contador == 3)
	{
		App->render->Blit(bgTexture, 8, 0, NULL);
	}

	return update_status::UPDATE_CONTINUE;
}

bool SceneIntro::CleanUp()
{

	App->textures->Unload(bgTexture);
	App->textures->Unload(logo);
	App->fonts->UnLoad(whiteFont);
	App->fonts->UnLoad(blueFont);
	
	return true;
}