#ifndef GLOBALS
#define GLOBALS

#include <string>
#include <iostream>
#include <SDL.h>
#include "randomNumber.h"

class Globals
{
public:
	//math helpers
	static const float PI;

	//useful for me as a dev
	static bool debugging;

	//SDL related
	static int ScreenWidth, ScreenHeight, ScreenScale;
	static SDL_Renderer *renderer;
};

//Inicialización de variables globales
const float Globals::PI = 3.14159;
bool Globals::debugging = true;
int Globals::ScreenWidth = 1024, Globals::ScreenHeight = 768, Globals::ScreenScale = 1;
SDL_Renderer *Globals::renderer = NULL;

#endif