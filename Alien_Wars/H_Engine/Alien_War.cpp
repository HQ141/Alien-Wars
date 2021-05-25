#include "Alien_War.h"
AWar::AWar(){}
AWar::~AWar(){}
void AWar::initialize(HWND hwnd) {
	Game::initialize(hwnd);
	jetman.initialize(graphics,input);
	bg.initialize(graphics);
	alien.intialize(graphics);
}
void AWar::update() {
	jetman.update();
	alien.update();
	AWar::render();
}
void AWar::ai() {

}
void AWar::collisions() {
	if ((jetman.getpy() > alien.gety() - 50) && (jetman.getpy() < alien.gety() + 50)) {
		if (jetman.getpx() > GAME_WIDTH - 100) {
			MessageBox(NULL, L"You Won", L"You Won", 0);
			exit(0);
		}
	}
	if ((alien.getpy() > jetman.gety() - 50) && (alien.getpy() < jetman.gety() + 50)) {
		if ((alien.getpx() > jetman.getx() - 50) && (alien.getpx() < jetman.getx() + 50)) {
			MessageBox(NULL, L"You Lose", L"You Lose", 0);
			exit(0);
		}
	}
}
void AWar::releaseAll() {
	Game::releaseAll();
}
void AWar::resetAll() {
	Game::resetAll();
}
void AWar::render() {
	graphics->spriteBegin();
	bg.draw();
	
	jetman.draw();
	alien.draw();
	graphics->spriteEnd();
}