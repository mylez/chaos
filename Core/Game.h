#ifndef CHAOS_GAME_H
#define CHAOS_GAME_H

#include "GameState.h"
#include "AssetLibrary.h"


class Game
{
public:

    Game();

    ~Game();

    GameState defaultGameState, *gameState = &defaultGameState;

    AssetLibrary assetLibrary;

    void loop();

    void pollEvents();

private:

    bool isRunning;

    SDL_Window *window;

    SDL_Renderer *renderer;
};


#endif //CHAOS_GAME_H
