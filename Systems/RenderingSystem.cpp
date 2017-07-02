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
                .entryMult(.5, .5)
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
 * @param entity
 */
void RenderingSystem::renderShape(Entity *entity)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>();
    ShapeComponent *polygon = entity->getComponent<ShapeComponent>();
    Vec2i position = positionInCamera(transform->position)
        .add(polygon->size.scale(-0.5))
        .asVec2i();

    graphics_->setColor(polygon->color);
    graphics_->fillRect(position, polygon->size.asVec2i());
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
void RenderingSystem::renderTerrain(Entity *entity)
{
    TransformComponent *transform = entity->getComponent<TransformComponent>();
    TerrainLayerComponent *terrain = entity->getComponent<TerrainLayerComponent>();
    Vec2i windowSize = graphics_->getWindowSize();
    Vec2i tileSize(terrain->tileSets[0].tileWidth, terrain->tileSets[0].tileHeight);

    for (int l = 0; l < terrain->numLayers; l++)
    {
        TerrainLayer terrainLayer = terrain->layers[l];
        SpriteSheet spriteSheet(
            assetLibrary_->getTexture(terrainLayer.name),
            Vec2i(16, 16),
            Vec2i(32, 32)
        );

        for (int x = 0; x < terrain->width /*&& x * 32 < windowSize.x*/; x++)
        {
            for (int y = 0; y < terrain->height /*&& y * 32 < windowSize.y*/; y++)
            {
                TileInfo tileInfo = terrain->getTileInfoAtIndex(l, x, y);
                if (tileInfo.type >= 0)
                {
                    Sprite sprite = spriteSheet.getSprite(tileInfo.type);
                    Vec2i pos = tileSize
                        .entryMult(Vec2i(x, y))
                        .add(positionInCamera(transform->position).asVec2i())
                        .add(Vec2i(-terrainLayer.height*tileSize.x / 2, -terrainLayer.height * tileSize.y / 2));

                    graphics_->drawSprite(
                        &sprite,
                        tileSize,
                        pos
                    );
                    graphics_->setColor(80, 80, 255);
                    graphics_->drawRect(pos, Vec2i(32, 32));
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
    return position.entryMult(1, -1).add(Vec2d(0, windowSize_d_.y));
}
