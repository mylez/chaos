#include <Chaos/Entities/PlayerEntity.h>
#include "WorldSceneGameState.h"


WorldSceneGameState::WorldSceneGameState(AssetLibrary *assetLibrary)
{
    assetLibrary_ = assetLibrary;
    addEntity(new PlayerEntity());
}


void WorldSceneGameState::render(SDL_Renderer *renderer)
{
    for (const auto &entity: getEntities())
    {
        entity->render(renderer);
    }
}


void WorldSceneGameState::update(double timeElapsed)
{
    for (const auto &entity: getEntities())
    {
        entity->update(timeElapsed);
    }
}

