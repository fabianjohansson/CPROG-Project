#include "GameEngine.h"
#include <SDL.h>
#include "Sprite.h"
#include "System.h"
#include "Label.h"
#include <iostream>

using namespace std;

#define FPS 80

void GameEngine::add(Sprite* spr) {
	added.push_back(spr);
}

void GameEngine::remove(Sprite* spr) {
	removed.push_back(spr);
}


void GameEngine::switchGameEnded() {
	gameEnded = !gameEnded;
}

void GameEngine::addKill() {
	kills++;
}

int GameEngine::getKills() {
	return kills;
}


void GameEngine::run() {
	bool quit = false;
	gameEnded = false;

	const int tickInterval = 1000 / FPS;

	while (!quit) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				for (Sprite* s : sprites)
					s->mouseDown(event.button.x, event.button.y);
				break;
			case SDL_MOUSEBUTTONUP:
				for (Sprite* s : sprites)
					s->mouseUp(event.button.x, event.button.y);
				break;
			case SDL_KEYDOWN:
				if (!gameEnded)
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					for (Sprite* s : sprites)
						s->upKey();
					break;
				case SDLK_DOWN:
					for (Sprite* s : sprites)
						s->downKey();
					break;
				case SDLK_LEFT:
					for (Sprite* s : sprites)
						s->leftKey();
					break;
				case SDLK_RIGHT:
					for (Sprite* s : sprites)
						s->rightKey();
					break;
				case SDLK_SPACE:
					for (Sprite* s : sprites)
						s->spaceDown();
					break;
				}	
					
			}//switch(event)
		}//while SDL_PollEvent

		if(gameEnded && kills < 10){
			Label* gameOver = Label::getInstance(250, 200, 200, 140, "Game Over");
			sprites.push_back(gameOver);
		}else if (gameEnded) {
			Label* victory = Label::getInstance(250, 200, 200, 140, "You won!");
			sprites.push_back(victory);
		}

			
		for (Sprite* s: sprites) 
			for(vector<Sprite*>::iterator i = sprites.begin() +1;
				i!= sprites.end(); i++)
			if (s->detectCollision(*i)) {
				cout << "Collision! " << endl;
				removed.push_back(s);
				removed.push_back(*i);
			}

		

		//calls the sprite objects tick method
		for (Sprite* s : sprites)
			if (!gameEnded) {
				s->tick();
			}
			

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
