#ifndef CHAOS_HASTILEDATA_H
#define CHAOS_HASTILEDATA_H

#include <SDL2/SDL.h>
#include "TileData.h"

class HasTileData
{
public:
    void loadTileData(std::string filePath);
    TileData *getTileData();
    SDL_Texture *getTileTexture();
private:
    TileData tileData_;
    SDL_Texture *tileTexture_;
};


#endif //CHAOS_HASTILEDATA_H
