#ifndef WAR_H
#define WAR_H
#include"game.h"
#include"image.h"
#include"Jetman.h"
#include"textureManager.h"
#include"BackGround.h"
#include"Alien.h"
class AWar :public Game
{
private:
    BackGround bg;
    Jetman jetman;
    Alien alien;
public:
    AWar();
    virtual ~AWar();
    void initialize(HWND hwnd);
    void update();
    void ai();
    void collisions();
    void render();
    void releaseAll();
    void resetAll();

};

#endif