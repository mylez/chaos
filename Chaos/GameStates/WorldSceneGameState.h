#ifndef CHAOS_WORLDSCENEGAMESTATE_H
#define CHAOS_WORLDSCENEGAMESTATE_H

#include "Core/SceneGameState.h"

class WorldSceneGameState:
    public SceneGameState
{
public:
    WorldSceneGameState();
    void render(SDL_Renderer *renderer);
    void update();
};


#endif //CHAOS_WORLDSCENEGAMESTATE_H
