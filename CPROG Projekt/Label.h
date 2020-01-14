#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <SDL_ttf.h>

class Label : public Sprite {
public:
	static Label* getInstance(int x, int y, int w, int h, std::string txt) {
		return new Label(x, y, w, h, txt);
	}
	void draw() const;
	void tick();
	~Label();
	std::string getText() const { return text; }
	void setText(std::string newTxt);

//protected:
	
private:
	Label(int x, int y, int w, int h, std::string txt);
	SDL_Texture* texture;
	std::string text;
};

#endif
