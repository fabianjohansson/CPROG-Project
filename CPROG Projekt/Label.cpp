#include "Label.h"
#include "System.h"
#include <SDL.h>

using namespace std;

Label::Label(int x, int y, int w, int h, string txt)
	:Sprite(x, y, w, h), text(txt) {
	SDL_Surface* surf = TTF_RenderText_Blended(sys.font, text.c_str(), {255,0,0});
	texture = SDL_CreateTextureFromSurface(sys.ren, surf);
	SDL_FreeSurface(surf);
}
void Label::draw() const {
	SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
}

void Label::setText(string newTxt) {
	text = newTxt;
	SDL_Surface* surf = TTF_RenderText_Blended(sys.font, text.c_str(), { 255,0,0 });
	SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(sys.ren, surf);
	SDL_FreeSurface(surf);
}

Label::~Label() {
	SDL_DestroyTexture(texture);
}