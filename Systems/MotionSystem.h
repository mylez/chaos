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

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init (Game *game);
};


#endif //CHAOS_MOTIONSYSTEM_H
