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
    float dispDDPI, dispHDPI, dispVDPI;

    Game();

    ~Game();

    GameState defaultGameState, *gameState_ = &defaultGameState;

    Graphics graphics_;

    AssetLibrary assetLibrary_;

    void loop();

    void setGameState(GameState *gameState);

    void setIsRunning(bool isRunning)
    { isRunning_ = isRunning; }

    Vec2i getMousePosition();

    GameState *getGameState()
    { return gameState_; }

    AssetLibrary *getAssetLibrary()
    { return &assetLibrary_; }

    Graphics *getGraphics()
    { return &graphics_; }
};


#endif //CHAOS_GAME_H
