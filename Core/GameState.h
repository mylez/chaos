#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <SDL2/SDL.h>

class GameState
{
public:
    virtual void render(SDL_Renderer *) {};
    virtual void handleInputEvent(SDL_Event *) {};
    virtual void update() {};
};


#endif //CHAOS_GAMESTATE_H
