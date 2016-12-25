//
// Created by Miles on 12/22/16.
//

#ifndef CHAOS_GAME_H
#define CHAOS_GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include "World.h"

class Game
{

public:

    Game();

    ~Game();

    void loop();

private:

    World *worldRenderer;

    SDL_Window *window;

    SDL_Renderer *renderer;

    bool isRunning;

    std::vector<Renderable *> renderables;
};


#endif //CHAOS_GAME_H
