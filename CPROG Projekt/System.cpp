#include "System.h"

System::System() {
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Game", 10, 10, 700, 500, 0);
	ren = SDL_CreateRenderer(win,-1,0);
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	music = Mix_LoadWAV("filepath");
	Mix_PlayChannel(-1, music, -1);
}
System::~System() {
	Mix_FreeChunk(music);
	Mix_CloseAudio();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}

System sys;
