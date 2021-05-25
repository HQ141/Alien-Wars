#include"graphics.h"
#include"image.h"
#include"Constant.h"
#include"Input.h"
#include"gameError.h"
#include"Projectile.h"
class Alien
{
private:
	TextureManager ship1Texture;
	TextureManager ship2Texture;
	TextureManager ship3Texture;
	TextureManager ship4Texture;
	TextureManager ship5Texture;
	Image ship[5];
	float shipx;
	float shipy;
	direction dir;
	Projectile* bullet;
	Graphics* graphics;
	int st = 0;
	int s = 0;
public:
	Alien(){
		shipx = GAME_WIDTH;
		shipy = 0;
		dir = direction::right;
	}
	~Alien() {}
	void update();
	void intialize(Graphics* gra);
	void resetAll();
	void draw();
	float getx() { return shipx; }
	float gety() { return shipy; }
	float getpx() { if (bullet)return bullet->getx(); else return 0; }
	float getpy() { if (bullet)return bullet->gety(); else return 0; }
	void releaseAll();
};

