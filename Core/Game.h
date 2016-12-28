//
// Created by Miles on 12/27/16.
//

#ifndef CHAOS_GAME_H
#define CHAOS_GAME_H

#include "GameState.h"

class Game
{
public:

    Game();

    ~Game();

    GameState defaultGameState;

    GameState *gameState = &defaultGameState;

    void loop();

    void pollEvents();
private:

    bool isRunning;

    SDL_Window *window;

    SDL_Renderer *renderer;
};


#endif //CHAOS_GAME_H
