#include "cleanup.h"
#include "res_path.h"
#include "drawing_functions.h"
#include <SDL_mixer.h>
#undef main

int main(int __argc, char **agv)
{
	//setup SDL
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		cout << "error initializing SDL" << endl;
		return 1;
	}

	//setup Window
	SDL_Window *window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		SDL_Quit();
		cout << "Window error" << endl;
		return 1;
	}

	//setup renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		cleanup(window);
		SDL_Quit();
		cout << "renderer error" << endl;
		return 1;
	}

	SDL_RenderSetLogicalSize(renderer, 1024, 768);

	//Initialise SDL_image
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		SDL_Quit();
		cout << "SDL Image did not initialise" << endl;
		return 1;
	}

	//Initialise text to font
	if (TTF_Init() != 0)
	{
		SDL_Quit();
		cout << "SDL ttf fif no initialise" << endl;
		return 1;
	}

	//Initilise SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		SDL_Quit();
		cout << "Mixer did not initialise" << endl;
		return 1;
	}

	string resPath = getResourcePath();
	SDL_Texture *texture = loadTexture(resPath + "map.png", renderer);

	//run game for 5000 ticks (5000ms)
	while (SDL_GetTicks() < 5000)
	{
		//clean the screen
		SDL_RenderClear(renderer);
		//draw what we want to the screen
		renderTexture(texture, renderer, 0, 0);
		//show image we've been rendering
		SDL_RenderPresent(renderer);
	}

	cleanup(renderer);
	cleanup(window);
	cleanup(texture);

	SDL_Quit();
	return 0;
}