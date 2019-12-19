#include <SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include <SDL_image.h>
#include "System.h"

//test
GameEngine eng;

class Santa : public Sprite {
public:
	Santa(int x, int y) : Sprite(x, y, 50, 50) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\New Piskel.png");
	}
	~Santa() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	void upKey(){
		rect.y -= 4;
	}
	void downKey() {
		rect.y += 4;
	}
	void leftKey() {
		rect.x -= 4;
	}
	void rightKey() {
		rect.x += 4;
	}
	void tick() {}
private:
	SDL_Texture* texture;
};
class BackgroundSprite : public Sprite{
public:
	BackgroundSprite() : Sprite(0, 0, 700, 500) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\background5.png");
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	void tick(){}
private:
	SDL_Texture* texture;
};

/*class Zombie : public Sprite {
public:
	Zombie() : Sprite()
		~Zombie() {}
};*/

int main(int argc, char** argv) {
	BackgroundSprite* bgs = new BackgroundSprite();
	eng.add(bgs);
	Santa* santa = new Santa(20,100);
	eng.add(santa);
	eng.run();
	return 0;
}
