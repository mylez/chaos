#include "CollisionSystem.h"
#include <Core/Entity.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/PhysicsComponent.h>
#include <cmath>
#include <Core/Game.h>


/**
 *
 * @param timeElapsed
 * @param entities
 */
void CollisionSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    for (const auto &entity_a: entities)
    {
        auto *transform_a = entity_a->getComponent<TransformComponent>();
        auto *boxCollision_a = entity_a->getComponent<BoxCollisionComponent>();
        auto *physics_a = entity_a->getComponent<PhysicsComponent>();

        Vec2d
            pos_a = transform_a->position.add(boxCollision_a->center),
            size_a = boxCollision_a->size;
        for (const auto entity_b: entities)
        {
            if (entity_a->id == entity_b->id)
            {
                continue;
            }
            auto *transform_b = entity_b->getComponent<TransformComponent>();
            auto *boxCollision_b = entity_b->getComponent<BoxCollisionComponent>();
            auto *physics_b = entity_b->getComponent<PhysicsComponent>();

            Vec2d
                pos_b = transform_b->position.add(boxCollision_b->center),
                size_b = boxCollision_b->size;

            if (isIntersecting(pos_a, size_a, pos_b, size_b))
            {
                if (boxCollision_a->collisionEnterProcedure)
                {
                    boxCollision_a->collisionEnterProcedure->onCollisionEnter(Collision(entity_a, entity_b));
                }
            }
        }

        if (boxCollision_a->debugDraw)
        {
            graphics->setColor(0, 255, 0);
            graphics->drawRect(pos_a.add(size_a.scale(-0.5)).asVec2i(), size_a.asVec2i());
            graphics->fillRect(pos_a.add(Vec2d(-1, -1)).asVec2i(), Vec2i(2, 2));
        }
    }
}

/**
 *
 * @param pos_a
 * @param size_a
 * @param pos_b
 * @param size_b
 * @return
 *
 * bool DoBoxesIntersect(Box a, Box b) {
  return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
         (abs(a.y - b.y) * 2 < (a.height + b.height));
}
 */
bool CollisionSystem::isIntersecting(Vec2d pos_a, Vec2d size_a, Vec2d pos_b, Vec2d size_b)
{
    return (fabs(pos_a.x - pos_b.x) * 2. < (size_a.x + size_b.x)) &&
           (fabs(pos_a.y - pos_b.y) * 2. < (size_a.y + size_b.y));
}


/**
 *
 * @param game
 */
void CollisionSystem::init(Game *game)
{
    std::cout << "CollisionSystem.init\n";
    graphics = game->getGraphics();
}