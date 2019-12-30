#include <SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "System.h"
#include <iostream>
#include <string>

using namespace std;


GameEngine eng;

class Bullet : public Sprite {
public:
	static Bullet* getInstance(int x, int y) {
		return new Bullet(x,y);
	}
	Bullet(int x, int y) : Sprite(x, y, 8, 8) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\laser_bullet.png");
	}
	~Bullet() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	string getClassName() {
		return className;
	}
	bool detectCollision(Sprite* other) {
		if (other->getClassName() == "Zombie" &&
			this->getRect().x + this->getRect().w > other->getRect().x &&
			other->getRect().x + other->getRect().w > this->getRect().x &&
			this->getRect().y + this->getRect().h > other->getRect().y &&
			other->getRect().y + other->getRect().h > this->getRect().y) {
			return true;
		}
		return false;
		}

	void tick() {
		counter++;
		if (rect.x >= 700)
			eng.remove(this);
		else if (counter % 2 == 0)
			rect.x++;
	}
	
private:
	SDL_Texture* texture;
	int counter = 0;
	string className = "Bullet";
};

class Santa : public Sprite {
public:
	Santa(int x, int y) : Sprite(x, y, 36, 36) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Santa.png");
	}
	~Santa() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
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
		Bullet* b = Bullet::getInstance(rect.x + 15, rect.y + 15);
		eng.add(b);
	}
	bool detectCollision(Sprite* other) {
		return false;
	}

	string getClassName() {
		return className;
	}
	void tick() {}
private:
	SDL_Texture* texture;
	string className = "Santa";
};
class BackgroundSprite : public Sprite{
public:
	BackgroundSprite() : Sprite(0, 0, 700, 500) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\background5.png");
	}
	~BackgroundSprite(){
		SDL_DestroyTexture(texture);
	}
	bool detectCollision(Sprite* other) {
		return false;
	}

	string getClassName() {
		return className;
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	void tick(){}
private:
	SDL_Texture* texture;
	string className = "BackgroundSprite";
};

class Zombie : public Sprite {
public:
	Zombie() : Sprite(668,250,25,25) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Zombie_pixel.png");
	}
	~Zombie() {
		SDL_DestroyTexture(texture);
	}
	bool detectCollision(Sprite* other) {
		return false;
	}

	string getClassName() {
		return className;
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	void tick() {
		counter++;
		if (rect.x < -12) {
			eng.remove(this);
			eng.switchGameEnded();
		}
		else if(counter % 10 == 0)
		 rect.x --;
	}
private:
	SDL_Texture* texture;
	int counter = 0;
	string className = "Zombie";
};



int main(int argc, char** argv) {
	BackgroundSprite* bgs = new BackgroundSprite();
	eng.add(bgs);
	Santa* santa = new Santa(20,100);
	eng.add(santa);
	Zombie* zombie = new Zombie();
	eng.add(zombie);
	eng.run();
	return 0;
}
