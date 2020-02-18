#ifndef BULLET_H
#define BULLET_H
#include "Sprite.h"
#include "Label.h"


class Bullet : public Sprite {
public:
	static Bullet* getInstance(int x, int y) {
		return new Bullet(x, y);
	}
	~Bullet();

	void draw() const;

	bool detectCollision(Sprite* other);

	void tick();

private:
	Bullet(int x, int y);
	SDL_Texture* texture;
	int counter = 0;
	Label* gameWon;
};
#endif