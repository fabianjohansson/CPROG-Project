#include "Santa.h"
#include "System.h"
#include "Bullet.h"
#include "GameEngine.h"
#include "GameOver.h"


Santa::	~Santa() {
	SDL_DestroyTexture(texture);
}

void Santa::draw() const {
	SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
}

void Santa::upKey() {
	if (rect.y > 20)
		rect.y -= 4;
}
void Santa::downKey() {
	if (rect.y < 400)
		rect.y += 4;
}
void Santa::leftKey() {
	if (rect.x > -12)
		rect.x -= 4;
}
void Santa::rightKey() {
	if (rect.x < 668)
		rect.x += 4;
}
void Santa::spaceDown() {
	if (counter % 2 == 0) {
		Bullet* b = Bullet::getInstance(rect.x + 15, rect.y + 15);
		eng.add(b);
	}
}
void Santa::keyDown(SDL_Keycode k) {
	if (!gg.getGameHasEnded()) {
		switch (k) {
		case SDLK_UP:
			upKey();
			break;
		case SDLK_DOWN:
			downKey();
			break;
		case SDLK_RIGHT:
			rightKey();
			break;
		case SDLK_LEFT:
			leftKey();
			break;
		case SDLK_SPACE:
			spaceDown();
			break;
		}
	}

}

bool Santa::detectCollision(Sprite* other) {
	return false;
}

void Santa::tick() {
	if (!gg.getGameHasEnded()) {
		counter++;
	}

}

Santa::Santa(int x, int y) : Sprite(x, y, 36, 36) {
	texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Santa.png");
}