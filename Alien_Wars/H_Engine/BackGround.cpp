#include "BackGround.h"
void BackGround::initialize(Graphics* g) {
	graphics = g;
	if (!Manager.initialize(graphics, L"sky_background_green_hills.png"))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing jetman"));
	image.initialize(graphics,0,0, 0, &Manager);
}
void BackGround::draw() {
	image.draw();
}