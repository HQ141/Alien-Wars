#include "Alien.h"
void Alien::intialize(Graphics *gra) {
    graphics = gra;
    ship2Texture.initialize(graphics, L"__alien_enemy_4_purple_green_flying_001.png");
    if (!ship[2].initialize(graphics, 0, 0, 0, &ship2Texture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship"));
    ship3Texture.initialize(graphics, L"__alien_enemy_4_purple_green_flying_002.png");
    if (!ship[3].initialize(graphics, 0, 0, 0, &ship3Texture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship"));
    ship4Texture.initialize(graphics, L"__alien_enemy_4_purple_green_flying_003.png");
    if (!ship[4].initialize(graphics, 0, 0, 0, &ship4Texture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship"));
    ship5Texture.initialize(graphics, L"__alien_enemy_4_purple_green_flying_004.png");
    if (!ship[0].initialize(graphics, 0, 0, 0, &ship5Texture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship"));
    ship1Texture.initialize(graphics, L"__alien_enemy_4_purple_green_flying_000.png");
    if (!ship[1].initialize(graphics, 0, 0, 0, &ship1Texture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship"));
}
void Alien::update() {
    if(bullet)
        if (bullet->end()) {
            delete bullet;
            bullet = NULL;
        }
        else{
            bullet->update();
        }
    if (!bullet) {
        bullet = new Projectile;
        bullet->intialize(graphics, shipx, shipy, direction::left, L"missle.png",0.1,1);
    }
    if (s == 10) {
        st++;
        s = 0;
    }
    else { s++; }
    if (st == 4)
        st = 0;
    shipx = GAME_WIDTH-150 ;
    if (dir == right) {
        shipy = shipy - 2;
    }
    else{shipy = shipy + 2;
    }
    if (shipy >= GAME_HEIGHT-(970*.1))
        dir = right;
    if (shipy < 0)
        dir = direction::left;
    ship[st].setX(shipx);
    ship[st].setY(shipy);
    
}
void Alien::draw() {
    ship[st].setScale(.2);
    ship[st].draw();
    if (bullet)
        bullet->draw();
}
void Alien::releaseAll()
{
    ship1Texture.onLostDevice();
    ship2Texture.onLostDevice();
    ship3Texture.onLostDevice();
    ship4Texture.onLostDevice();
    ship5Texture.onLostDevice();
    return;
}
void Alien::resetAll()
{
    ship1Texture.onResetDevice();
    ship2Texture.onResetDevice();
    ship3Texture.onResetDevice();
    ship4Texture.onResetDevice();
    ship5Texture.onResetDevice();
    return;
}