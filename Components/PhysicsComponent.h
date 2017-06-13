#ifndef CHAOS_PHYSICSCOMPONENT_H
#define CHAOS_PHYSICSCOMPONENT_H

#include <Core/Component.h>
#include <Core/vec2d.h>

class PhysicsComponent:
    public Component
{
public:
    vec2d velocity;
    PhysicsComponent(): velocity(vec2d(0, 0))
    { label = COMPONENT_PHYSICS; }
};

#endif //CHAOS_PHYSICSCOMPONENT_H
