#include <Components/TransformComponent.h>
#include <Components/ShapeComponent.h>
#include <Core/Entity.h>
#include <Core/Vec2d.h>
#include <Core/Vec2i.h>
#include <Systems/RenderingSystem.h>


/**
 *
 * @param timeElapsed
 * @param entity
 * @param entities
 */
void RenderingSystem::update(double timeElapsed, Entity *entity, std::vector<Entity *> entities)
{

    if (entity->hasComponent<ShapeComponent>())
    {
        renderShape(entity);
    }

    //if (entity->hasComponent<SpriteComponent>()) {
    //
    //}
}


/**
 *
 * @param entity
 */
void RenderingSystem::renderShape(Entity *entity)
{
    auto transform = entity->getComponent<TransformComponent>();
    auto polygon = entity->getComponent<ShapeComponent>();

    Vec2i
        window = graphics->getWindowSize(),
        position = transform->position.asVec2i();

    graphics->setColor(polygon->color);
    graphics->fillRect(position, polygon->size.asVec2i());
    graphics->fillRect(position, polygon->size.asVec2i());
    graphics->fillRect(position, polygon->size.asVec2i());
    graphics->fillRect(position, polygon->size.asVec2i());
}


/**
 *
 * @param entity
 */
void RenderingSystem::renderSprite(Entity *entity)
{

}


/**
 *
 * @param entity
 */
void RenderingSystem::renderAnimatedSprite(Entity *entity)
{

}
