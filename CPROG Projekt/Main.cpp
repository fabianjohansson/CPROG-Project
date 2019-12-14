#include <SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include <SDL_image.h>
#include "System.h"

GameEngine eng;

class Santa : public Sprite {
public:
	Santa(int x, int y) : Sprite(x, y, 300, 300) {
		texture = IMG_LoadTexture(sys.ren, "C:\\Users\\fabian\\Desktop\\Plugg\\HT 2019\\CPROG\\Sprites\\santa4.png");
	}
	~Santa() {
		SDL_DestroyTexture(texture);
	}
	void draw() const {
		SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
	}
	void upKey(){
		rect.y--;
	}
	void downKey() {
		rect.y++;
	}
	void leftKey() {
		rect.x--;
	}
	void rightKey() {
		rect.x++;
	}
	void tick() {}
private:
	SDL_Texture* texture;
};

int main(int argc, char** argv) {
	Santa* santa = new Santa(20,100);
	eng.add(santa);
	eng.run();
	return 0;
}