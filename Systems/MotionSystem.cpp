#include <Core/Entity.h>
#include <Components/TransformComponent.h>
#include <Components/PhysicsComponent.h>
#include "MotionSystem.h"
#include <iostream>


/**
 *
 * @param timeElapsed
 * @param entities
 */
void MotionSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    for (const auto &entity: entities)
    {
        auto *transform = entity->getComponent<TransformComponent>();
        auto *physics = entity->getComponent<PhysicsComponent>();

        physics->velocity = physics->velocity.add(physics->acceleration.scale(timeElapsed));
        physics->velocity = physics->velocity.scale(physics->friction);
        transform->position = transform->position.add(physics->velocity.scale(timeElapsed));

        if (physics->useGravity)
        {
            transform->position = transform->position.add(gravity);
        }
    }
}

void MotionSystem::init(Game *game)
{
    std::cout << "MotionSystem.init\n";
}
