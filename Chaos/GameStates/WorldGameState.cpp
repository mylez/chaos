#include <Chaos/Entities/WorldEntity.h>
#include "WorldGameState.h"
#include <Core/AssetLibrary.h>

// load world segment
//



/**
 *
 */
void WorldGameState::willEnter(AssetLibrary *assetLibrary)
{
    assetLibrary->loadTexture("Terrain", "media/tile-sheets/Terrain.png");
    loadTileSet("media/tile-data/level.json");
    setTileTexture(assetLibrary->getTexture("Terrain"));

    SDL_Texture *ter = assetLibrary->getTexture("Terrain");

    //worldSegment_.loadSegment(getTileSet(), vec2i(0, 0), vec2i(40, 40), ter);
}


/**
 *
 * @param event
 */
void WorldGameState::handleInputEvent(SDL_Event *event)
{
    for (const auto &inputEventListener: getInputEventListeners(event->type)) {
        inputEventListener->handleInputEvent(event);
    }

}


/**
 *
 * @param timeElapsed
 */
void WorldGameState::update(double timeElapsed)
{
    static double t;
    t += timeElapsed;
    //printf("%f\n", player.velocity.x);
    std::stringstream name;
    player.position = player.position.add(player.velocity.scale(2));
}


/**
 *
 * @param g
 */
void WorldGameState::render(Graphics *g)
{
    static double t;
    t += .01;

    Sprite
        terrainSprite = Sprite(getTileTexture(), vec2i(1*32, 11*32), vec2i(32, 32)),
        playerSprite = Sprite(getTileTexture(), vec2i(7*32, 13*32), vec2i(32, 32));

    vec2i windowSize = g->getWindowSize();

    g->pushTransform(vec2i(0, windowSize.y), vec2d(1, -1));
    for (int x = 0; 32*x < windowSize.x; x++) {
        for (int y = 0; 32*y < windowSize.y; y++) {
            g->setColor(255, 0, 0);
            g->drawSprite(&terrainSprite, vec2i(32, 32), vec2i(32*x, 32*y));
        }
    }

    g->setColor(100, 155, 255);
    g->pushTransform(vec2i(0, 0), vec2d(2, 2));
    g->drawSprite(&playerSprite, vec2i(32, 32), player.position.asVec2i());
    g->drawString(player.getStringProperty("name"), player.position.asVec2i());
    g->popTransform();
    g->popTransform();
}

