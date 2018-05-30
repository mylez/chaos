#ifndef CHAOS_PHYSICSCOMPONENT_H
#define CHAOS_PHYSICSCOMPONENT_H

#include <Core/Component.h>
#include <Core/Vec2d.h>

class PhysicsComponent:
    public Component
{
public:
    Vec2d
        velocity,
        acceleration,
        netForce;
    double
        friction = 1, // this is not true friction, replace with static and kinetic friction
        staticFriction = 0,
        kineticFriction = 0,
        mass = 1;
    bool
        useGravity;
    PhysicsComponent()  :
        velocity(Vec2d(0, 0)),
        acceleration(Vec2d(0, 0)),
        netForce(Vec2d(0, 0)),
        friction(1),
        mass(1),
        useGravity(false)
    { label = COMPONENT_PHYSICS; }

    void applyForce(Vec2d f)
    {
        netForce = netForce.add(f);
    }
};

#endif //CHAOS_PHYSICSCOMPONENT_H
