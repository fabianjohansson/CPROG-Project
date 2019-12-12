#include "GameEngine.h"
#include <SDL.h>
#include "Sprite.h"
#include "System.h"
using namespace std;

void GameEngine::add(Sprite* spr) {
	sprites.push_back(spr);
}

void GameEngine::run() {
	bool quit = false;
	while (!quit) {
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
					
			}//switch(event)
		}//while SDL_PollEvent

		SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
		SDL_RenderClear(sys.ren);
		for (Sprite* s : sprites)
			s->draw();
		SDL_RenderPresent(sys.ren);

	}//while !quit

}
