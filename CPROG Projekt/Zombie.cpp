#include "Zombie.h"
#include "Label.h"
#include "GameEngine.h"
#include "System.h"
#include "GameOver.h"


Zombie::Zombie(int x, int y) : Sprite(x, y, 25, 25) {
	texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Zombie_pixel.png");
}
Zombie::~Zombie() {
	SDL_DestroyTexture(texture);
}
bool Zombie::detectCollision(Sprite* other) {
	return false;
}
void Zombie::draw() const {
	SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
}

void Zombie::tick() {
	if (!gg.getGameHasEnded()) {
		counter++;
		if (rect.x < -12) {
			eng.remove(this);
			gg.switchGameHasEnded();
			Label* gameOver = Label::getInstance(250, 200, 200, 140, "You Lost!");
			eng.add(gameOver);
		}
		else if (counter % 20 == 0) {
			rect.x--;
		}
	}
}
