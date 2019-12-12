#include "System.h"

System::System() {
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Game", 10, 10, 700, 500, 0);
	ren = SDL_CreateRenderer(win,-1,0);
}
System::~System() {
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}

System sys;
