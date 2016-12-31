#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <SDL2/SDL.h>
#include "InputEventListener.h"


class GameState:
    public InputEventListener
{
public:
    virtual void render(SDL_Renderer *renderer) {};
    virtual void update(double timeElapsed) {};
};


#endif //CHAOS_GAMESTATE_H
