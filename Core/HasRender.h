#ifndef CHAOS_HASRENDER_H
#define CHAOS_HASRENDER_H

#include <SDL2/SDL.h>

class HasRender
{
public:
    virtual void render(SDL_Renderer *renderer) {};
};


#endif //CHAOS_HASRENDER_H
