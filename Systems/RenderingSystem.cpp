#include <Components/TransformComponent.h>
#include <Components/ShapeComponent.h>
#include <Components/SpriteComponent.h>
#include <Core/Entity.h>
#include <Core/Vec2d.h>
#include <Core/Vec2i.h>
#include <Systems/RenderingSystem.h>
#include <Core/Game.h>


/**
 *
 * @param timeElapsed
 * @param entity
 * @param entities
 */
void RenderingSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    for (const auto &entity:entities)
    {

        //if (entity->hasComponent<SpriteComponent>())
        //{
        //    renderSprite(entity);
        //}

        if (entity->hasComponent<ShapeComponent>())
        {
            renderShape(entity);
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
    Vec2i position = transform->position.add(polygon->size.scale(-0.5)).asVec2i();

    //std::cout << " drawing something at " << position.x << "\n";

    graphics->setColor(polygon->color);
    graphics->fillRect(position, polygon->size.asVec2i());
}


/**
 *
 * @param entity
 */
void RenderingSystem::renderSprite(Entity *entity)
{
    std::cout << " render sprite? \n";
    auto transform = entity->getComponent<TransformComponent>();
    auto sprite = &entity->getComponent<SpriteComponent>()->sprite;
    graphics->drawSprite(sprite, Vec2i(32, 32), transform->position.asVec2i());
}


/**
 *
 * @param entity
 */
void RenderingSystem::renderAnimatedSprite(Entity *entity)
{}


/**
 *
 * @param game
 */
void RenderingSystem::init(Game *game)
{
    std::cout << "RenderingSystem.init\n";
    assetLibrary = game->getAssetLibrary();
    graphics = game->getGraphics();
}
