#ifndef CHAOS_GAME_H
#define CHAOS_GAME_H

#include <SDL2/SDL.h>
#include "AssetLibrary.h"
#include "Graphics.h"
#include "GameState.h"


class Game
{
private:

    bool isRunning_;

    SDL_Window *window_;

    SDL_Renderer *renderer_;

public:

    Game();

    ~Game();

    GameState defaultGameState, *gameState_ = &defaultGameState;

    Graphics graphics_;

    AssetLibrary assetLibrary_;

    void loop();

    void pollInputEvents();

    void setGameState(GameState *gameState);

    GameState *getGameState() { return gameState_; }

    AssetLibrary *getAssetLibrary() { return &assetLibrary_; }

    Graphics *getGraphics() { return &graphics_; }
};


#endif //CHAOS_GAME_H
