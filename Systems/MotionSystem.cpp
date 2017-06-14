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
void MotionSystem::update(double timeElapsed, Entity *entity, std::vector<Entity *> entities)
{
    auto *transform = entity->getComponent<TransformComponent>();
    auto *physics = entity->getComponent<PhysicsComponent>();
    physics->velocity = physics->velocity.scale(1);
    transform->position = transform->position.add(physics->velocity.scale(timeElapsed));
}
