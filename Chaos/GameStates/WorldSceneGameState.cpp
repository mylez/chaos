#include <Chaos/Entities/PlayerEntity.h>
#include "WorldSceneGameState.h"

class Vec2D;


/**
 *
 * @param assetLibrary
 */
WorldSceneGameState::WorldSceneGameState(AssetLibrary *assetLibrary)
{
    setAssetLibrary(assetLibrary);

    loadTileData("media/tile-sheets/Terrain.png");



    for (int i = 0; i < 1000; i++)
    {
        addEntity(new PlayerEntity());
    }
}


/**
 *
 * @param g
 */
void WorldSceneGameState::render(Graphics *g)
{
    for (const auto &entity: getEntities())
    {
        entity->render(g);
    }
}


/**
 *
 * @param timeElapsed
 */
void WorldSceneGameState::update(double timeElapsed)
{
    for (const auto &entity: getEntities())
    {
        entity->update(timeElapsed);
    }
}


/**
 *
 * @param renderer
 * @param texture
 * @param srcRect
 * @param position
 * @param size
 */
void WorldSceneGameState::renderWorldRelative(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *srcRect,
                                              Vec2D position, Vec2D size)
{
    SDL_Rect dstRect = {
        (int)position.x,
        (int)(500 - position.y),
        (int)size.x,
        (int)size.y
    };
}


//void WorldSceneGameState::loadWorldTiles()
//{
//    std::string name = "WorldSceneGameState::Terrain";
//    getAssetLibrary()->loadTexture(name, "media/tile-sheets/Terrain.png");
//    texture_terrainTiles_ = getAssetLibrary()->getTexture(name);
//}

