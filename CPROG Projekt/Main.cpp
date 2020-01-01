#include <SDL.h>
#include "GameEngine.h"
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

class Bullet : public Sprite {
public:
	static Bullet* getInstance(int x, int y) {
		return new Bullet(x,y);
	}
	~Bullet() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
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
			eng.addKill();
			if (eng.getKills() == 10)
				eng.switchGameEnded();
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
protected:
	Bullet(int x, int y) : Sprite(x, y, 8, 8) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\laser_bullet.png");
	}
private:
	SDL_Texture* texture;
	int counter = 0;
	string className = "Bullet";
};

class Santa : public Sprite {
public:
	Santa(int x, int y) : Sprite(x, y, 36, 36){
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Santa.png");
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
	bool detectCollision(Sprite* other) {
		return false;
	}

	string getClassName() {
		return className;
	}
	void draw() const {
		const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
	}
	void tick() {
		counter++;
		if (rect.x < -12) {
			eng.remove(this);
			eng.switchGameEnded();
		}
		else if (counter % 10 == 0) {
			rect.x--;
		}
		
	}
protected:
	Zombie(int x, int y) : Sprite(x, y, 25, 25) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\Zombie_pixel.png");
	}
private:
	SDL_Texture* texture;
	int counter = 0;
	string className = "Zombie";
};

class Background : public Sprite {
public:
	Background() : Sprite(0, 0, 700, 500) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\background5.png");
	}
	~Background() {
		SDL_DestroyTexture(texture);
	}
	bool detectCollision(Sprite* other) {
		return false;
	}

	string getClassName() {
		return className;
	}
	void draw() const {
		const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
	}
	void tick() {
		counter++;
		if (counter % 1000 == 0 && spawnedZombies < 10) {
			Zombie* zombie = Zombie::getInstance();
			eng.add(zombie);
			spawnedZombies++;
		}
	}
private:
	SDL_Texture* texture;
	string className = "Background";
	int counter = 0;
	int spawnedZombies = 0;
};



int main(int argc, char** argv) {
	Background* bg = new Background();
	eng.add(bg);
	Santa* santa = new Santa(20,100);
	eng.add(santa);
	eng.run();

		

	return 0;
}
