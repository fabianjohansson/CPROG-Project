#include <SDL.h>
#include "GameEngine.h"
#include "Label.h"
#include "Sprite.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "System.h"
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <vector>

using namespace std;

GameEngine eng;
Label* label = Label::getInstance(250, 200, 200, 140, "");


class Zombie : public Sprite {
public:
	static Zombie* getInstance() {
		srand((int)time(0));
		int y = (rand() % 400) + 20;
		return new Zombie(668, y);
	}
	~Zombie() {
		SDL_DestroyTexture(texture);
	}
	void keyDown(SDL_Keycode k) {}

	bool detectCollision(Sprite* other) {
		return false;
	}

	void draw() const {
		const SDL_Rect& rect = getRect();
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
	}
	void tick() {
		if (!label->getGameHasEnded()) {
			counter++;
			if (rect.x < -12) {
				eng.remove(this);
				label->switchGameHasEnded();
				label->setText("You Lost!");
				eng.add(label);
			}
			else if (counter % 10 == 0) {
				rect.x--;
			}
		}
		

	}

private:
	Zombie(int x, int y) : Sprite(x, y, 25, 25) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Zombie_pixel.png");
	}
	SDL_Texture* texture;
	int counter = 0;
};

class Bullet : public Sprite {
public:
	static Bullet* getInstance(int x, int y) {
		return new Bullet(x,y);
	}
	~Bullet() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		//const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	void keyDown(SDL_Keycode k) {}

	bool detectCollision(Sprite* other) {
		static int collisions = 0;
		if (Zombie* z = dynamic_cast<Zombie*>(other)) {
			if (this->getRect().x + this->getRect().w > other->getRect().x&&
				other->getRect().x + other->getRect().w > this->getRect().x&&
				this->getRect().y + this->getRect().h > other->getRect().y&&
				other->getRect().y + other->getRect().h > this->getRect().y) {
				//eng.addKill();
				collisions++;
				if (collisions == 10) {
					label->switchGameHasEnded();
					//Label* gameOver = Label::getInstance(250, 200, 200, 140, "You win!");
					label->setText("You win!");
					eng.add(label);
				}
					
				return true;
			}
		}
		return false;
		}

	void tick() {
		if (!label->getGameHasEnded()) {
			counter++;
			if (rect.x >= 700)
				eng.remove(this);
			else 
				rect.x ++;
		}
		
	}

private:
	Bullet(int x, int y) : Sprite(x, y, 8, 8) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\red laser.png");
	}
	SDL_Texture* texture;
	int counter = 0;
};

class Santa : public Sprite {
public:
	static Santa* getInstance(int x, int y) {
		return new Santa(x, y);
	}
	~Santa() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
	}
	void upKey(){
		if(rect.y > 20)
			rect.y -= 4;
	}
	void downKey() {
		if(rect.y < 400)
			rect.y += 4;
	}
	void leftKey() {
		if(rect.x > -12)
			rect.x -= 4;
	}
	void rightKey() {
		if(rect.x < 668)
			rect.x += 4;
	}
	void spaceDown() {
		if(counter % 2 == 0){
			Bullet* b = Bullet::getInstance(rect.x + 15, rect.y + 15);
			eng.add(b);
		}
	}
	void keyDown(SDL_Keycode k) {
		if (!label->getGameHasEnded()) {
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

	bool detectCollision(Sprite* other) {
		return false;
	}

	void tick() {
		if (!label->getGameHasEnded()) {
			counter++;
		}
		
	}
private:
	Santa(int x, int y) : Sprite(x, y, 36, 36) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Santa.png");
	}
	SDL_Texture* texture;
	int counter = 0;
};



class Background : public Sprite {
public:
	static Background* getInstance() {
		return new Background();
	}
	
	~Background() {
		SDL_DestroyTexture(texture);
	}
	void keyDown(SDL_Keycode k) {}

	bool detectCollision(Sprite* other) {
		return false;
	}

	void draw() const {
		const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
	}
	void tick() {
		if (!label->getGameHasEnded()) {
			counter++;
			static int spawnedZombies;
			if (counter % 1000 == 0 && spawnedZombies < 10) {
				Zombie* zombie = Zombie::getInstance();
				eng.add(zombie);
				spawnedZombies++;
			}
		}
	}
private:
	Background() : Sprite(0, 0, 700, 500) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\background5.png");
	}
	SDL_Texture* texture;
	int counter = 0;
};



int main(int argc, char** argv) {
	Background* bg = Background::getInstance();
	eng.add(bg);
	Santa* santa = Santa::getInstance(20, 100);
	eng.add(santa);
	eng.run();
	

	delete bg;
	delete santa;

	return 0;
}
