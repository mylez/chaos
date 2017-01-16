#include "Chaos.h"
#include "GameStates/WorldGameState.h"

Chaos::Chaos()
{
    static WorldGameState worldGameState;
    setGameState(&worldGameState);
}

