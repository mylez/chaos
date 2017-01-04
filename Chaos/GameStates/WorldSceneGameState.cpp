#include <Chaos/Entities/PlayerEntity.h>
#include "WorldSceneGameState.h"

class Vec2D;


/**
 *
 *
 * @param assetLibrary
 */
WorldSceneGameState::WorldSceneGameState(AssetLibrary *assetLibrary)
{
    loadTileData("media/tile-data/level.json");
    assetLibrary->loadTexture("WorldSceneGameState::Terrain", "tile-sheets/Terrain.png");
    texture_terrainTiles_ = assetLibrary->getTexture("WorldSceneGameState::Terrain");

    for (int i = 0; i < 500; i++)
    {
        addEntity(new PlayerEntity());
    }
}


/**
 *
 *
 * @param g
 */
void WorldSceneGameState::drawWorld(Graphics *g)
{
    TileData *tileData = getTileData();

    Vec2D
        cameraPosition = getCameraPosition(),
        cameraSize = Vec2D(g->getWindowSize());

    int worldHeight = tileData->getHeight(0);

    Vec2I
        tileSize = tileData->tileSetTileSize(0),
        topLeft(
            (int)(cameraPosition.x / tileSize.x),
            worldHeight - (int)((cameraSize.y + cameraPosition.y) / tileSize.y)
        ),
        bottomRight(
            (int)((cameraPosition.x + cameraSize.x) / tileSize.x),
            worldHeight - (int)(cameraPosition.y / tileSize.y)
        ),
        scrollOffset(
            -(int)((cameraPosition.x)) % tileSize.x,
            (int)(cameraSize.y + cameraPosition.y) % tileSize.y
        );
    for (int x = topLeft.x; x < bottomRight.x + 1; x++)
    {
        for (int y = topLeft.y - 1; y < bottomRight.y; y++)
        {
            Vec2I dstPos = Vec2I(
                tileSize.x * (x - topLeft.x),
                tileSize.y * (y - topLeft.y)
            ).add(scrollOffset);

            Vec2I srcPos = tileData->tileSourcePosition(0, tileData->getTileTypeAt(0, x, y));

            g->copyTexture(texture_terrainTiles_,
                           srcPos, tileSize,
                           dstPos, tileSize
            );
        }
    }
}



/**
 *
 * @param g
 */
void WorldSceneGameState::render(Graphics *g)
{
    drawWorld(g);

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
    static double time = 0;
    time += timeElapsed;

    setCameraPosition(Vec2D(
        6000 * (1 + cos(time / 160000)),
        6000 * (1 + sin(time / 200000))
    ));

    for (const auto &entity: getEntities())
    {
        entity->update(timeElapsed);
    }
}

