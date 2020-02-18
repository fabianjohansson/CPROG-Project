#include "GameOver.h"

GameOver gg;

void GameOver::switchGameHasEnded() {
	gameHasEnded = !gameHasEnded;
}
bool GameOver::getGameHasEnded() {
	return gameHasEnded;
}