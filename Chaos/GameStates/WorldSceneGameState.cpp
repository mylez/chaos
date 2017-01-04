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
    loadTileData("media/tile-data/level-1.json");
    assetLibrary->loadTexture("WorldSceneGameState::Terrain", "tile-sheets/Terrain.png");
    texture_terrainTiles_ = assetLibrary->getTexture("WorldSceneGameState::Terrain");

    for (int i = 0; i < 20; i++)
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
    int height = tileData->getHeight(0);
    int width = tileData->getLayerSize(0) / height;

    int i = 0;


    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            g->setColor(0, 255, 0, 255);

            int type = tileData->getTileTypeAt(0, i);
            Vec2I srcPos = tileData->tileSrcRectPosition(0, type);

            g->copyTexture(texture_terrainTiles_,
                           srcPos, Vec2I(32, 32),
                           Vec2I(32 * y, 32 * x), Vec2I(32, 32)
            );

            i++;
        }
    }

    //std::cout << " - - - - - \n";
}



/**
 *
 * @param g
 */
void WorldSceneGameState::render(Graphics *g)
{
    static double stupidMover = 0;
    g->pushTransform(Vec2I(-(int)(400 * (1+sin(stupidMover))), -(int)(400 * (1+cos(stupidMover)))), Vec2D(1, 1));
    drawWorld(g);
    for (const auto &entity: getEntities())
    {
        entity->render(g);
    }
    g->popTransform();
    stupidMover += .005;
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


//void WorldSceneGameState::loadWorldTiles()
//{
//    std::string name = "WorldSceneGameState::Terrain";
//    getAssetLibrary()->loadTexture(name, "media/tile-sheets/Terrain.png");
//    texture_terrainTiles_ = getAssetLibrary()->getTexture(name);
//}

