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

    void renderWorldRelative(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *srcRect, Vec2D position,
                             Vec2D size);

private:
    SDL_Texture *texture_terrainTiles_;
};


#endif //CHAOS_WORLDSCENEGAMESTATE_H
