#include "Zombie.h"
#include "GameEngine.h"
#include "System.h"
#include "GameOver.h"


Zombie::Zombie(int x, int y) : Sprite(x, y, 25, 25) {
	//Här ska sökvägen för filen Zombie_pixel.png läggas in
	texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Zombie_pixel.png");
}
Zombie::~Zombie() {
	SDL_DestroyTexture(texture);
	delete gameOver;
}
bool Zombie::detectCollision(Sprite* other) {
	return false;
}
void Zombie::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

void Zombie::tick() {
	if (!gg.getGameHasEnded()) {
		counter++;
		if (rect.x < -12) {
			eng.remove(this);
			gg.switchGameHasEnded();
			gameOver = Label::getInstance(250, 200, 200, 140, "You Lost!");
			eng.add(gameOver);
		}
		else if (counter % 20 == 0) {
			rect.x--;
		}
	}
}