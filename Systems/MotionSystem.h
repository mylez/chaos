#ifndef CHAOS_MOTIONSYSTEM_H
#define CHAOS_MOTIONSYSTEM_H

#include <Core/Component.h>
#include <Core/System.h>

class MotionSystem:
    public System
{
public:
    MotionSystem()
    { signature = COMPONENT_TRANSFORM | COMPONENT_PHYSICS; }

    void update(double timeElapsed, Entity *entity, std::vector<Entity *> entities);
};


#endif //CHAOS_MOTIONSYSTEM_H
