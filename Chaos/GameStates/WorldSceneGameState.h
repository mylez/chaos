#ifndef CHAOS_WORLDSCENEGAMESTATE_H
#define CHAOS_WORLDSCENEGAMESTATE_H

#include <Chaos/Scenes/WorldScene.h>
#include "Core/SceneGameState.h"

class WorldSceneGameState:
    public SceneGameState
{
private:
    WorldScene worldScene;
public:
    WorldSceneGameState();
};


#endif //CHAOS_WORLDSCENEGAMESTATE_H
