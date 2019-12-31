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
	void switchGameEnded();
	void addKill();
	int getKills();
private:
	std::vector<Sprite*> sprites, enemies;
	std::vector<Sprite*> added, removed;
	bool gameEnded;
	int kills = 0;
};

#endif
