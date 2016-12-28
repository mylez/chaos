#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <SDL2/SDL.h>
#include "InputEventListener.h"

class GameState:
    public InputEventListener
{
public:
    virtual void render(SDL_Renderer *) {};
    virtual void update() {};
};


#endif //CHAOS_GAMESTATE_H
