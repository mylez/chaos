#ifndef CHAOS_SPRITEMAP_H
#define CHAOS_SPRITEMAP_H


#include <SDL2/SDL.h>
#include <string>
#include "AssetLibrary.h"


class SpriteMap
{

public:

    SDL_Rect getSourceRect(int sprite);

    //void loadTexture(std::string name, std::string filePath, int tileHeight, int tileWidth, int numTilesX,
    //                 int numTilesY);

private:

    AssetLibrary *assetLibrary;

    std::string assetName;

    int tileWidth = 0,
        tileHeight = 0,
        numTilesX = 0,
        numTilesY = 0;
};


#endif //CHAOS_SPRITEMAP_H

