#include "Chaos.h"
#include "GameStates/WorldSceneGameState.h"

Chaos::Chaos()
{
    static WorldSceneGameState worldSceneGameState;
    this->gameState = &worldSceneGameState;
}

