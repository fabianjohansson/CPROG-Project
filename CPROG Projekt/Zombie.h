#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Sprite.h"
#include "Label.h"
#include <cstdlib> 
#include <ctime>
#include <random>


class Zombie : public Sprite {
public:
	static Zombie* getInstance() {
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(20, 400);

		int y = distr(eng);

		return new Zombie(668, y);
	}
	~Zombie();

	bool detectCollision(Sprite* other);

	void draw() const;

	void tick();

private:
	Zombie(int x, int y);
	SDL_Texture* texture;
	int counter = 0;
	Label* gameOver;

};

#endif
