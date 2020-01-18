#include "Bullet.h"
#include "Zombie.h"
#include "GameEngine.h"
#include "System.h"
#include "Label.h"
#include "GameOver.h"


Bullet::~Bullet() {
	SDL_DestroyTexture(texture);
}

void Bullet::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

bool Bullet::detectCollision(Sprite* other) {
	static int collisions = 0;
	if (Zombie* z = dynamic_cast<Zombie*>(other)) {
		if (this->getRect().x + this->getRect().w > other->getRect().x&&
			other->getRect().x + other->getRect().w > this->getRect().x&&
			this->getRect().y + this->getRect().h > other->getRect().y&&
			other->getRect().y + other->getRect().h > this->getRect().y) {
			collisions++;
			if (collisions == 10) {
				gg.switchGameHasEnded();
				Label* gameWon = Label::getInstance(250, 200, 200, 140, "You win!");
				eng.add(gameWon);
			}

			return true;
		}
	}
	return false;
}

void Bullet::tick() {
	if (!gg.getGameHasEnded()) {
		counter++;
		if (rect.x >= 700)
			eng.remove(this);
		else
			rect.x++;
	}
}

Bullet::Bullet(int x, int y) : Sprite(x, y, 8, 8) {
	//Här ska sökvägen för filen red laser.png läggas in
	texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\red laser.png");
}

