#ifndef BACKGROUND_H
#define	BACKGROUND_H
#include "Sprite.h"

class Background :	public Sprite {
public:
	static Background* getInstance() {
		return new Background();
	}

	~Background();

	bool detectCollision(Sprite* other);

	void draw() const;

	void tick();
	
private:
	Background();
	SDL_Texture* texture;
	int counter = 0;
};

#endif

