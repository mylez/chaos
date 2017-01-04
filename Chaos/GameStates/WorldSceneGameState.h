#ifndef CHAOS_WORLDSCENEGAMESTATE_H
#define CHAOS_WORLDSCENEGAMESTATE_H


#include <Core/Vec2D.h>
#include "Core/SceneGameState.h"
#include "Core/AssetLibrary.h"


class WorldSceneGameState:
    public GameState,
    public Scene
{
public:
    WorldSceneGameState(AssetLibrary *assetLibrary);
    void update(double timeElapsed);
    void render(Graphics *g);
    void drawWorld(Graphics *g);

private:
    SDL_Texture *texture_terrainTiles_;
};


#endif //CHAOS_WORLDSCENEGAMESTATE_H
