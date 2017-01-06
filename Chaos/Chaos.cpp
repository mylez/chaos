#include "Chaos.h"
#include "GameStates/WorldSceneGameState.h"
#include "GameStates/UITestGameState.h"

Chaos::Chaos()
{
    //static WorldSceneGameState worldSceneGameState(&assetLibrary_);
    //setGameState(&worldSceneGameState);

    static UITestGameState uiTestGameState;
    setGameState(&uiTestGameState);
}

