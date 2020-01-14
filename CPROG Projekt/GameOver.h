#ifndef GAMEOVER_H
#define GAMEOVER_H

class GameOver
{
public:
	void switchGameHasEnded();
	bool getGameHasEnded();
private:
	bool gameHasEnded;
};

extern GameOver gg;

#endif

