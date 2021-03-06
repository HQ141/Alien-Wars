#include "textureManager.h"
TextureManager::TextureManager()
{
    texture = NULL;
    width = 0;
    height = 0;
    file = NULL;
    graphics = NULL;
    initialized = false;
}
TextureManager::~TextureManager(){
    SAFE_RELEASE(texture);
}
bool TextureManager::initialize(Graphics *g, LPCWSTR f)
{
    try{
        graphics = g;
        file = f;

        hr = graphics->loadTexture(file, graphicsNS::BLACK, width, height, texture);
        if (FAILED(hr))
        {
            SAFE_RELEASE(texture);
            return false;
        }
    }
    catch(...) {return false;}
    initialized = true;
    return true;
}
void TextureManager::onLostDevice(){
    if (!initialized)
        return;
    SAFE_RELEASE(texture);
}
void TextureManager::onResetDevice()
{
    if (!initialized)
        return;
    graphics->loadTexture(file, graphicsNS::WHITE, width, height, texture);
}


