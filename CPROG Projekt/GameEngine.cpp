#include "GameEngine.h"
#include <SDL.h>
#include "Sprite.h"
#include "System.h"
#include "Label.h"
#include <iostream>

GameEngine eng;

using namespace std;

#define FPS 80

void GameEngine::add(Sprite* spr) {
	added.push_back(spr);
}

void GameEngine::remove(Sprite* spr) {
	removed.push_back(spr);
}



void GameEngine::run() {
	bool quit = false;

	const int tickInterval = 1000 / FPS;

	while (!quit) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				for (Sprite* s : sprites)
					s->keyDown(event.key.keysym.sym);
				break;
	
			}//switch(event)
		}//while SDL_PollEvent
	
		for (Sprite* s: sprites) 
			for(vector<Sprite*>::iterator i = sprites.begin() +1;
				i!= sprites.end(); i++)
			if (s->detectCollision(*i)) {
				//cout << "Collision! " << endl;
				removed.push_back(s);
				removed.push_back(*i);
			}

		

		//calls the sprite objects tick method
		for (Sprite* s : sprites)
				s->tick();
			

		for (Sprite* s : added)
			sprites.push_back(s);
		added.clear();

		for (Sprite* s : removed)
			for (vector<Sprite*>::iterator i = sprites.begin();
				i != sprites.end();)
				if (*i == s) {
					i = sprites.erase(i);
				}
				else
					i++;
		removed.clear();

		SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
		SDL_RenderClear(sys.ren);
		for (Sprite* s : sprites)
			s->draw();
		SDL_RenderPresent(sys.ren);

	}//while !quit
}
