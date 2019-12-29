#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Sprite.h"
#include <vector>

class GameEngine
{
public:
	void add(Sprite* spr);
	void remove(Sprite* spr);
	void run();
	//bool collision(Sprite* first, Sprite* second);
private:
	std::vector<Sprite*> sprites;
	std::vector<Sprite*> added, removed;
};

#endif
