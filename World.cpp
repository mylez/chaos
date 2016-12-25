#include <SDL2/SDL_image.h>
#include "World.h"


void World::render(SDL_Renderer *renderer)
{
    SDL_Delay(400);
    for (int i = 0; i < this->WIDTH; i++)
    {
        for (int j = 0; j < this->HEIGHT; j++)
        {
            SDL_Rect
                srcRect = this->tileRect(this->map[j][i]),
                dstRect = {32 * i, 32 * j, 32, 32};
            SDL_RenderCopy(renderer, this->tileTexture, &srcRect, &dstRect);
        }
    }
}


World::World(SDL_Renderer *renderer)
{
    this->tileTexture = IMG_LoadTexture(renderer, "media/level-png/map-tile-32x32.level-png");
}



SDL_Rect World::tileRect(int tile)
{
    SDL_Rect rect = {32, 32, 32, 32};
    switch (tile)
    {
        case 0:
        {
            rect.x *= 7;
            rect.y *= 1;
        } break;
        case 1:
        {
            rect.x *= 3;
            rect.y *= 21;
        } break;
    }
    return rect;
}

