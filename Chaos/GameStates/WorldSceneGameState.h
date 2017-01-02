#ifndef CHAOS_WORLDSCENEGAMESTATE_H
#define CHAOS_WORLDSCENEGAMESTATE_H

#include "Core/SceneGameState.h"

class WorldSceneGameState:
    public GameState,
    public Scene
{

public:
    WorldSceneGameState(AssetLibrary *assetLibrary);
    void update(double timeElapsed);
    void render(SDL_Renderer *renderer);

private:
    AssetLibrary *assetLibrary_;
};


#endif //CHAOS_WORLDSCENEGAMESTATE_H
