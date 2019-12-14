#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_mixer.h>

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
};

extern System sys;

#endif

