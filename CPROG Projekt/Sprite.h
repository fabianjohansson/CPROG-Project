#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

class Sprite
{
public:
	virtual void mouseDown(int x, int y) {}
	virtual void mouseup(int x, int y) {}
	virtual void draw() const = 0;
	SDL_Rect getRect() const { return rect; }
protected:
	Sprite(int x, int y, int w, int h) : rect{x,y,w,h} {}
	SDL_Rect rect;
};

#endif