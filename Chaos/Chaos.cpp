#include "Chaos.h"
#include "GameStates/WorldSceneGameState.h"

Chaos::Chaos()
{
    static WorldSceneGameState worldSceneGameState(&assetLibrary_);

    gameState_ = &worldSceneGameState;
}

