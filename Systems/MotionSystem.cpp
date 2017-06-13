#include <Core/Entity.h>
#include <Components/TransformComponent.h>
#include <Components/PhysicsComponent.h>
#include "MotionSystem.h"
#include <iostream>


void MotionSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    for (auto const &entity: entities) {
            std::cout << "updating entity " << this << std::endl;

            TransformComponent  *transform  = static_cast<TransformComponent    *> (entity->getComponent(COMPONENT_TRANSFORM));
            PhysicsComponent    *physics    = static_cast<PhysicsComponent      *> (entity->getComponent(COMPONENT_PHYSICS));

            transform->position = transform->position.add(physics->velocity.scale(timeElapsed));
        }
}