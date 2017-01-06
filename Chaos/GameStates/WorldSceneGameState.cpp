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
    loadTileSet("media/tile-data/level.json");
    assetLibrary->loadTexture("WorldSceneGameState::Terrain", "tile-sheets/Terrain.png");
    texture_terrainTiles_ = assetLibrary->getTexture("WorldSceneGameState::Terrain");
    for (int i = 0; i < 5000; i++)
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

    //static double _time = .01;

    //g->pushTransform(Vec2I(0, 0), Vec2D(.25 + pow(sin(_time*.1), 2), .25 + pow(sin(_time*.5), 2)));

    drawWorld(g);

    for (const auto &entity: getEntities())
    {
        entity->render(g);
    }

    //_time += 0.01;

    //g->popTransform();
}


/**
 *
 *
 * @param g
 */
void WorldSceneGameState::drawWorld(Graphics *g)
{
    TileSet
        *tileData = getTileSet();

    int
        numLayers = tileData->getNumLayers(),
        worldHeight = tileData->getHeight(0);

    Vec2D
        cameraPosition = getCamera()->getCameraPosition(),
        cameraSize = Vec2D(g->getWindowSize());


    Vec2I
        tileSize = tileData->tileSetTileSize(0),
        topLeft = Vec2I(
            (int)(cameraPosition.x / tileSize.x),
            worldHeight - (int)((cameraSize.y + cameraPosition.y) / tileSize.y)
        ),
        bottomRight = Vec2I(
            (int)((cameraPosition.x + cameraSize.x) / tileSize.x),
            worldHeight - (int)(cameraPosition.y / tileSize.y)
        ),
        scrollOffset = Vec2I(
            -(int)((cameraPosition.x)) % tileSize.x,
            (int)(cameraSize.y + cameraPosition.y) % tileSize.y
        );

    for (int layer = 0; layer < numLayers; layer++)
    {
        for (int x = topLeft.x; x < bottomRight.x + 1; x++)
        {
            for (int y = topLeft.y - 1; y < bottomRight.y; y++)
            {
                Vec2I dstPos = Vec2I(
                    tileSize.x * (x - topLeft.x),
                    tileSize.y * (y - topLeft.y)
                ).add(scrollOffset);

                Vec2I srcPos = tileData->tileSourcePosition(0, tileData->getTileTypeAt(layer, x, y));

                g->copyTexture(texture_terrainTiles_,
                               srcPos, tileSize,
                               dstPos, tileSize
                );
            }
        }
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

    getCamera()->setCameraPosition(Vec2D(
        200 * pow(cos(time / 2500), 2),
        200 * pow(sin(time / 5000), 2)
    ));

    for (const auto &entity: getEntities())
    {
        entity->update(timeElapsed);
    }
}

