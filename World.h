//
// Created by Miles on 12/22/16.
//

#ifndef CHAOS_WORLDRENDERER_H
#define CHAOS_WORLDRENDERER_H

#include <SDL2/SDL.h>
#include "Renderable.h"

class World: Renderable
{

public:
    const static int
        HEIGHT = 10,
        WIDTH = 10;

    void render(SDL_Renderer *renderer);

    World(SDL_Renderer *renderer);

    SDL_Texture *tileTexture;

private:

    SDL_Rect tileRect(int);

    int map[WIDTH][HEIGHT] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
};


#endif //CHAOS_WORLDRENDERER_H
