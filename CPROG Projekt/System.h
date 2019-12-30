#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

struct System
{	
	//constructor
	System();
	//destructor
	~System();

	//window pointer
	SDL_Window* win;
	//renderer pointer
	SDL_Renderer* ren;
	Mix_Chunk* music;
	TTF_Font* font;
};

extern System sys;

#endif

