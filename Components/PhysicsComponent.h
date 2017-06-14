#ifndef CHAOS_PHYSICSCOMPONENT_H
#define CHAOS_PHYSICSCOMPONENT_H

#include <Core/Component.h>
#include <Core/Vec2d.h>

class PhysicsComponent:
    public Component
{
public:
    Vec2d velocity;
    PhysicsComponent():
        velocity(Vec2d(0, 0))
    { label = COMPONENT_PHYSICS; }
};

#endif //CHAOS_PHYSICSCOMPONENT_H
