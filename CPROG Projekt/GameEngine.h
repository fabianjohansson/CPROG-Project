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
private:
	std::vector<Sprite*> sprites, enemies;
	std::vector<Sprite*> added, removed;
	int kills = 0;
};

extern GameEngine eng;

#endif