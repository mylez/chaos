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
    for (auto const &entity: entities)
    {
        auto *transform = entity->getComponent<TransformComponent>();
        auto *physics = entity->getComponent<PhysicsComponent>();
       // std::cout << transform->position.x << ", " << transform->position.y << std::endl;
        transform->position = transform->position.add(physics->velocity.scale(timeElapsed));
    }
}