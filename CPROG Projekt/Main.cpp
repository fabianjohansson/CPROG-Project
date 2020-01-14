#include <SDL.h>
#include "GameEngine.h"
#include "Background.h"
#include "Santa.h"


using namespace std;




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
