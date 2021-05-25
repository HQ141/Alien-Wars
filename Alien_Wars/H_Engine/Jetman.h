#include"graphics.h"
#include"image.h"
#include"Constant.h"
#include"Input.h"
#include"gameError.h"
#include"Projectile.h"

class Jetman
{
private:
	Projectile *bullet;
	TextureManager Manager;
	Graphics* graphics;
	Input* input;
	TextureManager idleManager;
	Image idle;
	Image Moveimage;
	float x;
	float y;
	status st;
	status lst;
	direction dir;
	float p=0;
	float scale;
	int sxstatus;
	int systatus;
	int ixstatus;
	int iystatus;
	int xstatus;
	int ystatus;
public:
	Jetman(){
		xstatus = 0;
		ystatus = 0;
		sxstatus = 0;
		systatus = 0;
		ixstatus = 0;
		iystatus = 0;
		scale = 0.125;
		st = status::idle;
		lst = status::forward;
		dir = direction::right;
	}
	void movement();
	void nomove();
	void fire();
	void initialize(Graphics *gra,Input *input);
	float getx() { return x; }
	float gety() { return y; }
	float getpx() { if (bullet)return bullet->getx(); else return 0; }
	float getpy() { if (bullet)return bullet->gety(); else return 0; }
	void update();
	void draw();
	void control();
	void release() { Manager.onLostDevice(); }
	void reset() { Manager.onResetDevice(); }
};

