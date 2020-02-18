#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>


class Sprite
{
public:
	virtual void keyDown(SDL_Keycode k) {}
	virtual bool detectCollision(Sprite* other) { return false; }
	virtual void draw() const = 0;
	SDL_Rect getRect() const { return rect; }
	//totally virtual method implemented in subclasses
	virtual void tick() = 0;
protected:
	Sprite(int x, int y, int w, int h) : rect{ x,y,w,h } {}
	//removes copy constructor
	Sprite(const Sprite&) = delete;
	//removes assignment operator
	const Sprite& operator=(const Sprite&) = delete;
	SDL_Rect rect;
};

#endif