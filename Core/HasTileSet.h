#ifndef CHAOS_HASTILESET_H
#define CHAOS_HASTILESET_H

#include <SDL2/SDL.h>
#include "TileSet.h"

class HasTileSet
{
public:
    void loadTileSet(std::string filePath);
    TileSet *getTileSet();
    SDL_Texture *getTileTexture();
private:
    TileSet tileSet_;
    SDL_Texture *tileTexture_;
};


#endif //CHAOS_HASTILESET_H
