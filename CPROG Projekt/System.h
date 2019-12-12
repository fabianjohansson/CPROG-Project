#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
class System
{	
	//constructor
	System();
	//destructor
	~System();

	//window pointer
	SDL_Window* win;
	//renderer pointer
	SDL_Renderer* ren;
};

extern System sys;

#endif

