#include "SpriteMap.h"

/**
 *
 * @param sprite
 * @return
 */
SDL_Rect SpriteMap::getSourceRect(int sprite)
{
    int xPos = sprite % this->numTilesX,
        yPos = (1 + sprite - xPos) / this->numTilesX;

    return SDL_Rect {
        xPos * this->tileWidth,
        yPos * this->tileHeight,
        this->tileWidth,
        this->tileHeight
    };
}

// void SpriteMap::loadTexture(std::string name, std::string filePath, int tileHeight, int tileWidth,
//                             int numTilesX, int numTilesY)
// {
//     this->assetLibrary->loadTexture(name, filePath);
//     this->assetName = name;
//     this->tileHeight = tileHeight;
//     this->tileWidth = tileWidth;
//     this->numTilesX = numTilesX;
//     this->numTilesY = numTilesY;
// }



