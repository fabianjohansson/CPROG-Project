#include "Background.h"
#include "GameEngine.h"
#include "Zombie.h"
#include "System.h"
#include "GameOver.h"

Background::~Background() {
	SDL_DestroyTexture(texture);
}


bool Background::detectCollision(Sprite* other) {
	return false;
}

void Background::draw() const {
	SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
}
void Background::tick() {
	if (!gg.getGameHasEnded()) {
		counter++;
		static int spawnedZombies;
		if (counter % 1000 == 0 && spawnedZombies < 10) {
			Zombie* zombie = Zombie::getInstance();
			eng.add(zombie);
			spawnedZombies++;
		}
	}
}
	Background::Background() : Sprite(0, 0, 700, 500) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\backgroundIce.png");
	}

