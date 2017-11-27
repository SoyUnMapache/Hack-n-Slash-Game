#include "cleanup.h"
#include "res_path.h"
#include "drawing_functions.h"
#include <SDL_mixer.h>

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

	return 0;
}