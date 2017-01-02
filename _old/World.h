//
// Created by Miles on 12/22/16.
//

#ifndef CHAOS_WORLDRENDERER_H
#define CHAOS_WORLDRENDERER_H

#include <SDL2/SDL.h>
#include <vector>
#include "Renderable.h"

class World: Renderable
{

public:

    void render(SDL_Renderer *renderer);

    World(SDL_Renderer *renderer);

    SDL_Texture *tileTexture;

    void loadMapData(const char *file, std::vector<std::vector<int>> &vec);

private:

    std::vector<std::vector<int>> mapData;

    SDL_Rect tileRect(int);

    static const int TILE_SIZE = 8;

    static const int TILESET_WIDTH = 18;

};


#endif //CHAOS_WORLDRENDERER_H
