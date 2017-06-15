#ifndef CHAOS_COLLISIONSYSTEM_H
#define CHAOS_COLLISIONSYSTEM_H

#include <Core/System.h>
#include <Core/Component.h>
#include <Core/Vec2d.h>
#include <Core/Graphics.h>

class CollisionSystem:
    public System
{
public:
    Graphics *graphics;
    CollisionSystem()
    { signature = COMPONENT_TRANSFORM | COMPONENT_COLLISION | COMPONENT_PHYSICS; }

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init (Game *game);

    bool isIntersecting(Vec2d, Vec2d, Vec2d, Vec2d);
};


#endif //CHAOS_COLLISIONSYSTEM_H
