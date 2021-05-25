#include"graphics.h"
#include"image.h"
#include"Constant.h"
#include"gameError.h"
class BackGround
{
private:
	TextureManager Manager;
	Graphics* graphics;
	Image image;
public:
	BackGround() {}
	void initialize(Graphics* gra);
	void draw();
	void release() { Manager.onLostDevice(); }
	void reset() { Manager.onResetDevice(); }
};

