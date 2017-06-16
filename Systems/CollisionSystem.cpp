#include "CollisionSystem.h"
#include <Core/Entity.h>
#include <Components/BoxCollisionComponent.h>
#include <cmath>
#include <Core/Game.h>
#include <Core/Script.h>


/**
 * very dumb and slow collision system
 *
 * O(n^2) + map operations and clearing at every frame
 *
 * todo - replace with spatial partitioning
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

            Vec2d
                pos_b = transform_b->position.add(boxCollision_b->center),
                size_b = boxCollision_b->size;

            if (isIntersecting(pos_a, size_a, pos_b, size_b))
            {
                trackCollisionThisCycle(entity_a, boxCollision_a, entity_b, boxCollision_b);
            }

            trackCollisionInProgress(entity_a, boxCollision_a, entity_b, boxCollision_b);
        }

        if (boxCollision_a->debugDraw)
        {
            graphics->setColor(0, 255, 0);
            graphics->drawRect(pos_a.add(size_a.scale(-0.5)).asVec2i(), size_a.asVec2i());
            graphics->fillRect(pos_a.add(Vec2d(-1, -1)).asVec2i(), Vec2i(2, 2));
        }
    }

    collisionsThisCycle.clear();
}

/**
 *
 * @param posA
 * @param sizeA
 * @param posB
 * @param sizeB
 * @return
 */
bool CollisionSystem::isIntersecting(Vec2d posA, Vec2d sizeA, Vec2d posB, Vec2d sizeB)
{
    return (fabs(posA.x - posB.x) * 2. < (sizeA.x + sizeB.x)) &&
           (fabs(posA.y - posB.y) * 2. < (sizeA.y + sizeB.y));
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


/**
 *
 * @param idA
 * @param idB
 */
void CollisionSystem::trackCollisionThisCycle(Entity *entityA, BoxCollisionComponent *cmpA, Entity *entityB,
                                              BoxCollisionComponent *cmpB)
{
    std::pair<unsigned int, unsigned int>
        orderedPair = makeOrderedPair(entityA->id, entityB->id);

    if (!collisionsInProgress[orderedPair])
    {
        for (const auto &script: entityA->getScripts())
        {
            script->onCollisionEnter(Collision(entityA, entityB));
        }

        for (const auto &script: entityB->getScripts())
        {
            script->onCollisionEnter(Collision(entityB, entityA));
        }
    }

    collisionsThisCycle[orderedPair] = true;
    collisionsInProgress[orderedPair] = true;
}


/**
 *
 * @param entityA
 * @param entityB
 */
void CollisionSystem::trackCollisionInProgress(Entity *entityA, BoxCollisionComponent *cmpA, Entity *entityB,
                                               BoxCollisionComponent *cmpB)
{
    std::pair<unsigned int, unsigned int>
        orderedPair = makeOrderedPair(entityA->id, entityB->id);

    bool
        inProgress = collisionsInProgress[orderedPair],
        thisCycle = collisionsThisCycle[orderedPair];

    if (inProgress && !thisCycle)
    {
        for (const auto &script: entityA->getScripts())
        {
            script->onCollisionExit(Collision(entityA, entityB));
        }

        for (const auto &script: entityB->getScripts())
        {
            script->onCollisionExit(Collision(entityB, entityA));
        }

        collisionsInProgress.erase(orderedPair);
    }
}


/**
 *
 * @param idA
 * @param idB
 * @return
 */
std::pair<unsigned int, unsigned int> CollisionSystem::makeOrderedPair(unsigned int idA, unsigned int idB)
{
    unsigned int
        a = idA > idB ? idA : idB,
        b = idA < idB ? idA : idB;
    return std::make_pair(a, b);
}
