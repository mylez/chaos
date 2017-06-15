#ifndef CHAOS_BOXCOLLISIONCOMPONENT_H
#define CHAOS_BOXCOLLISIONCOMPONENT_H

#include <Core/Component.h>
#include <Core/Collision.h>
#include <Core/Vec2d.h>

class BoxCollisionComponent:
    public Component
{
public:
    bool
        debugDraw = false;

    Vec2d
        size = Vec2d(1, 1),
        center = Vec2d(0, 0);

    CollisionEnterProcedure
        *collisionEnterProcedure = nullptr;

    CollisionExitProcedure
        *collisionExitProcedure = nullptr;

    BoxCollisionComponent()
    { label = COMPONENT_COLLISION; }
};


#endif //CHAOS_BOXCOLLISIONCOMPONENT_H
