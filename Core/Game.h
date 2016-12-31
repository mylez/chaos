#ifndef CHAOS_GAME_H
#define CHAOS_GAME_H

#include "GameState.h"
#include "AssetLibrary.h"


class Game
{
public:

    Game();

    ~Game();

    GameState defaultGameState, *gameState_ = &defaultGameState;

    AssetLibrary assetLibrary_;

    void loop();

    void pollEvents();

private:

    bool isRunning_;

    SDL_Window *window_;

    SDL_Renderer *renderer_;
};


#endif //CHAOS_GAME_H
