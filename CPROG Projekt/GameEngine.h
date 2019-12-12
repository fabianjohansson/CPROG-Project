#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Sprite.h"
#include <vector>

class GameEngine
{
public:
	void add(Sprite* spr);
	void run();
private:
	std::vector<Sprite*> sprites;
};

#endif
