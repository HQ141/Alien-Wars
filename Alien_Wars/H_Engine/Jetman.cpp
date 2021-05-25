#include "Jetman.h"
void Jetman::initialize(Graphics *g,Input *i){
	graphics = g;
	input = i;
	if(!Manager.initialize(graphics, L"__jet_pack_man_with_weapon_flying.png"))
		throw(GameError(gameErrorNS::FATAL_ERROR,"Error initializing jetman"));
	Moveimage.initialize(graphics, 0, 0,0, &Manager);
	idleManager.initialize(graphics, L"__jet_pack_man_with_weapon_flying_no_movement.png");
	idle.initialize(graphics, 0, 0, 0, &idleManager);
}
void Jetman::nomove() {
	xstatus = 0;
	ystatus = 0;
	sxstatus = 0;
	systatus = 0;
	RECT r;
	r.left = (4405 / 5) * ixstatus;
	r.right = (4405 / 5) * (ixstatus + 1);
	r.top = (1278 / 2) * iystatus;
	r.bottom = (1278 / 2) * (iystatus + 1);
	ixstatus++;
	if (ixstatus == 5) {
		ixstatus = 0;
		iystatus++;
		if (iystatus == 1)
			iystatus = 0;
	}
	idle.setSpriteDataRect(r);
	if (dir == direction::left) {
		idle.flipHorizontal(true);
		idle.setX(x - (4405 / 5) * 4 * scale);
	}
	else {

		idle.flipHorizontal(false);
		idle.setX(x);
	}
	idle.setY(y);
	idle.setScale(scale);
}
void Jetman::movement() {
	ixstatus = 0;
	iystatus = 0;
	sxstatus = 0;
	systatus = 0;
	if (p / 5 == 1) {
		RECT r;
		r.left = (4405 / 5) * xstatus;
		r.right = (4405 / 5) * (xstatus + 1);
		r.top = (1917 / 3) * ystatus;
		r.bottom = (1917 / 3) * (ystatus + 1);
		xstatus++;
		if (xstatus == 5) {
			xstatus = 0;
			ystatus++;
			if (ystatus == 3)
				ystatus = 0;
		}
		Moveimage.setSpriteDataRect(r);
		p = 0;
	}
	else { p++; }
	if (dir == direction::left) {
		Moveimage.flipHorizontal(true);
		Moveimage.setX(x - (4405 / 5) * 4 * scale);
	}
	else {
		Moveimage.flipHorizontal(false);
		Moveimage.setX(x);
	}

	Moveimage.setY(y);
	Moveimage.setScale(scale);
}
void Jetman::control() {
	if (input->isKeyDown('D') && ((x + ((Moveimage.getWidth()) / 5) * scale) < GAME_WIDTH)) {
		x = x + 2;
		st = status::forward;
		dir = direction::right;
	}
	else if (input->isKeyDown('A') && (x > 0)) {
		x = x - 2;
		st = status::back;
		dir = direction::left;
	}
	else{st = status::idle;}
	if (input->isKeyDown('W') && (y > 0)) {
		y = y - 2;
	}
	if (input->isKeyDown('S') && ((y + ((Moveimage.getHeight()) / 5) * scale) < GAME_HEIGHT)) {
		y = y + 2;
	}
	if (input->isKeyDown('P') && !bullet) {
		bullet = new Projectile;
		bullet->intialize(graphics, x, y, dir, L"broad-2.png");
	}
}
void Jetman::update() {
	control();
	if (bullet) {
		bullet->update();
		if (bullet->end()) {
			delete bullet;
			bullet = NULL;
		}
	}
	if (st == status::back || status::forward) {
		movement();
	}
	else if (st == status::idle) {
		nomove();
	}

}

void Jetman::draw() {
	if (st == status::back || status::forward) {
		Moveimage.draw();
	}
	else if (st == status::idle) {
		idle.draw();
	}
	if (bullet)
		bullet->draw();
	
}
