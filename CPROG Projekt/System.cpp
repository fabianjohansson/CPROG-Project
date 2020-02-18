#include "System.h"
#include <iostream>

System::System() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	win = SDL_CreateWindow("Santa saving christmas", 10, 10, 700, 500, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	music = Mix_LoadWAV("filepath");
	Mix_PlayChannel(-1, music, -1);
	font = TTF_OpenFont("C:/Windows/Fonts/MAIAN.ttf", 48);
	if (!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
}
System::~System() {
	Mix_FreeChunk(music);
	Mix_CloseAudio();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
}

System sys;