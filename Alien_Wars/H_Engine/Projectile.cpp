#include "Projectile.h"
void Projectile::intialize(Graphics* gra, float dx, float dy, direction a,LPCWSTR str,float sc,int i) {
	ii = i;
	graphics = gra;
	scale = sc;
	x = dx+50;
	y = dy+5;
	dir = a;
	Manager.initialize(graphics, str);
	image.initialize(graphics, 0, 0, 0, &Manager);
	image.setX(x);
	image.setY(y);
	inti = true;
}
void Projectile::update() {
	if (dir == direction::right) {
		x = x + 5;
		image.setDegrees(90);
	}
	else {
		x = x - 5;
		image.setDegrees(270);
	}
	if (ii)
		image.setDegrees(90);
	image.setX(x);
	image.setScale(scale);
}
bool Projectile::end(){
	if (x > GAME_WIDTH || x < 0)
		return true;
	return false;
}
void Projectile::draw() {
	image.draw();
}