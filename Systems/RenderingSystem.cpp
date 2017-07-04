#include <Core/Entity.h>
#include <Core/Game.h>
#include <Core/SpriteSheet.h>
#include <Components/ShapeComponent.h>
#include <Components/SpriteComponent.h>
#include <Components/TerrainLayerComponent.h>


/**
 *
 * @param timeElapsed
 * @param entity
 * @param entities
 */
void RenderingSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    if (cameraEntity == nullptr)
    {
        Vec2i w = graphics_->getWindowSize();
        graphics_->drawString(
            "No camera attached",
            Vec2d(w.x, w.y)
                .hadamard(.5, .5)
                .add(Vec2d(-85, -20))
                .asVec2i()
        );
        return;
    }

    windowSize_i_ = graphics_->getWindowSize();
    windowSize_d_ = Vec2d(windowSize_i_.x, windowSize_i_.y);

    for (const auto &entity:entities)
    {
        if (entity->hasComponent<SpriteComponent>())
        {
            renderSprite(entity);
        }

        if (entity->hasComponent<ShapeComponent>())
        {
            renderShape(entity);
        }

        if (entity->hasComponent<TerrainLayerComponent>())
        {
            renderTerrain(entity);
        }
    }
}


/**
 *
 * @param game
 */
void RenderingSystem::init(Game *game)
{
    std::cout << "RenderingSystem.init\n";
    assetLibrary_ = game->getAssetLibrary();
    graphics_ = game->getGraphics();
    cameraEntity = game->getGameState()->findEntityWithComponent<CameraComponent>();
    if (cameraEntity != nullptr)
    {
        cameraComponent = cameraEntity->getComponent<CameraComponent>();
        cameraComponent->renderingSystem = this;
    }
}


/**
 *
 * @param entity
 */
void RenderingSystem::renderShape(Entity *entity)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>();
    ShapeComponent *polygon = entity->getComponent<ShapeComponent>();

    Vec2i screenPosition = transform->position
        // invert y axis
        .hadamard(1, -1)
        // position in camera
        .add(cameraEntity->transform.position.hadamard(-1, 1))
        // move origin to the center of screen
        .add(windowSize_d_.scale(.5))
        // treat entity position as its center
        .add(polygon->size.scale(-.5))
        //
        .asVec2i();

    graphics_->setColor(polygon->color);
    graphics_->fillRect(screenPosition, polygon->size.asVec2i());
    //
    std::stringstream message;
    message << entity->transform.position.x << " " << entity->transform.position.y;
    graphics_->drawString(message.str(), screenPosition.add(Vec2i(10, -3)));
}


/**
 *
 * @param entity
 */
void RenderingSystem::renderSprite(Entity *entity)
{
    auto transform = entity->getComponent<TransformComponent>();
    auto sprite = &entity->getComponent<SpriteComponent>()->sprite;
    graphics_->drawSprite(
        sprite,
        sprite->getTargetSize()
            .asVec2i(),
        positionInCamera(transform->position)
            .asVec2i()
    );
}


/**
 *
 * @param entity
 */
void RenderingSystem::renderAnimation(Entity *entity)
{}


/**
 *
 * @param entity
 */
void RenderingSystem::renderTerrain(Entity *entity)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>();
    TerrainLayerComponent *terrain = entity->getComponent<TerrainLayerComponent>();
    Vec2i tileSize(terrain->tileSets[0].tileWidth, terrain->tileSets[0].tileHeight);

    for (int l = 0; l < terrain->numLayers; l++)
    {
        TerrainLayer terrainLayer = terrain->layers[l];
        SpriteSheet spriteSheet(
            assetLibrary_->getTexture(terrainLayer.name),
            Vec2i(16, 16),
            Vec2i(32, 32)
        );

        TileInfo
            topLeftTile = terrain->getTileInfoAtPosition(l, transform->position.add(windowSize_d_.scale(-.5))
                .add(cameraEntity->transform.position.hadamard(1, -1)).hadamard(1, -1)),
            bottomRightTile = terrain->getTileInfoAtPosition(l, transform->position.add(windowSize_d_.scale(.5))
                .add(cameraEntity->transform.position.hadamard(1, -1)).hadamard(1, -1));

        for (int x = topLeftTile.x; x < bottomRightTile.x; x++)
        //for (int x = 0; x < terrain->width; x++)
        {
            for (int y = topLeftTile.y; y < bottomRightTile.y; y++)
            //for (int y = 0; y < terrain->height; y++)
            {
                TileInfo tileInfo = terrain->getTileInfoAtIndex(l, x, y);
                if (tileInfo.type >= 0)
                {
                    Sprite sprite = spriteSheet.getSprite(tileInfo.type);

                    Vec2i screenPosition = transform->position
                        // invert y axis
                        .hadamard(1, -1)
                        //
                        .add(Vec2d(x*tileSize.x, y*tileSize.y))
                        //
                        .add(Vec2d(-terrain->width*tileSize.x/2, -terrain->height*tileSize.y/2))
                        // move origin to the center of screen
                        .add(windowSize_d_.hadamard(.5, .5))
                        // treat entity position as its center
                        //.add(terrain->size.scale(-.5))
                        // position in camera
                        .add(cameraEntity->transform.position.hadamard(-1, 1))
                        //
                        .asVec2i();

                    graphics_->drawSprite(
                        &sprite,
                        tileSize,
                        screenPosition
                    );
                    graphics_->setColor(80, 80, 200);
                    graphics_->drawRect(screenPosition, Vec2i(32, 32));
                }
            }
        }
    }
}


/**
 *
 * @param position
 * @return
 */
Vec2d RenderingSystem::positionInCamera(Vec2d position)
{
    return position.add(
        cameraEntity->transform.position
            .add(windowSize_d_.scale(0.5))
    );
}


/**
 *
 * @param position
 * @return
 */
Vec2d RenderingSystem::positionOriginRelative(Vec2d position)
{
    return position.hadamard(1, -1).add(Vec2d(0, windowSize_d_.y));
}