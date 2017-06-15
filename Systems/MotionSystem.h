#ifndef CHAOS_MOTIONSYSTEM_H
#define CHAOS_MOTIONSYSTEM_H

#include <Core/System.h>
#include <Core/Component.h>

class MotionSystem:
    public System
{
public:
    Vec2d gravity;
    MotionSystem():
        gravity(Vec2d(0, 3))
    { signature = COMPONENT_TRANSFORM | COMPONENT_PHYSICS; }

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init (Game *game);
};


#endif //CHAOS_MOTIONSYSTEM_H
