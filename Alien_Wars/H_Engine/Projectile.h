#ifndef PROJECTILE_H
#define PROJECTILE_H
#include"graphics.h"
#include"image.h"
#include"Constant.h"
#include"Input.h"
#include"gameError.h"

class Projectile
{
private:
	TextureManager Manager;
	Image image;
	Graphics* graphics;
	float x;
	float degree;
	float scale;
	bool inti=false;
	int ii=0;
	direction dir;
	float y;
public:
	~Projectile() {}
	Projectile() {}
	bool getinti() { return inti; }
	bool end();
	void intialize(Graphics* gra, float dx, float dy, direction a, LPCWSTR str, float sc = .3,int i=0);
	void update();
	void draw();
	void release() { Manager.onLostDevice(); }
	void reset() { Manager.onResetDevice(); }
	float getx() { return x; }
	float gety() { return y; }
};

#endif