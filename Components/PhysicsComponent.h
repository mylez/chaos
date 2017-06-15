#ifndef CHAOS_PHYSICSCOMPONENT_H
#define CHAOS_PHYSICSCOMPONENT_H

#include <Core/Component.h>
#include <Core/Vec2d.h>

class PhysicsComponent:
    public Component
{
public:
    Vec2d
        velocity = Vec2d(0, 0),
        acceleration;
    double
        friction,
        mass;
    bool
        useGravity;
    PhysicsComponent():
        velocity(Vec2d(0, 0)),
        acceleration(Vec2d(0, 0)),
        friction(1),
        mass(1),
        useGravity(false)
    { label = COMPONENT_PHYSICS; }
};

#endif //CHAOS_PHYSICSCOMPONENT_H
