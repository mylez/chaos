#ifndef CHAOS_GAME_H
#define CHAOS_GAME_H

#include <SDL2/SDL.h>
#include "AssetLibrary.h"
#include "Graphics.h"


class Game
{
public:

    Game();

    ~Game();

    //GameState defaultGameState, *gameState_ = &defaultGameState;

    Graphics graphics_;

    AssetLibrary assetLibrary_;

    void loop();

    void pollInputEvents();

    //void setGameState(GameState *gameState);

private:

    bool isRunning_;

    SDL_Window *window_;

    SDL_Renderer *renderer_;
};


#endif //CHAOS_GAME_H
