#ifndef SANTA_H
#define SANTA_H
#include "Sprite.h"


class Santa : public Sprite {
public:
	static Santa* getInstance(int x, int y) {
		return new Santa(x, y);
	}
	~Santa();
	void draw() const;

	void upKey();
	void downKey();
	void leftKey();
	void rightKey();
	void spaceDown();
	void keyDown(SDL_Keycode k);

	bool detectCollision(Sprite* other);

	void tick();

private:
	Santa(int x, int y);
	SDL_Texture* texture;
	int counter = 0;
};

#endif
