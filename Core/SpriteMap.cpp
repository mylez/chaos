#include "SpriteMap.h"

/**
 *
 * @param sprite
 * @return
 */
SDL_Rect SpriteMap::getSourceRect(int sprite)
{
    int xPos = sprite % numTilesX_,
        yPos = (1 + sprite - xPos) / numTilesX_;

    return SDL_Rect {
        xPos * tileWidth_,
        yPos * tileHeight_,
        tileWidth_,
        tileHeight_
    };
}

// void SpriteMap::loadTexture(std::string name, std::string filePath, int tileHeight_, int tileWidth_,
//                             int numTilesX_, int numTilesY)
// {
//     assetLibrary->loadTexture(name, filePath);
//     assetName = name;
//     tileHeight_ = tileHeight_;
//     tileWidth_ = tileWidth_;
//     numTilesX_ = numTilesX_;
//     numTilesY = numTilesY;
// }



