#ifndef CHAOS_RENDERINGSYSTEM_H
#define CHAOS_RENDERINGSYSTEM_H

#include <Core/Component.h>
#include <Core/System.h>
#include <Core/Graphics.h>

class RenderingSystem:
    public System
{
    Graphics *graphics;
public:
    RenderingSystem(Graphics *g):
        graphics(g)
    { signature = COMPONENT_TRANSFORM; }

    void update(double timeElapsed, std::vector<Entity *> entities);
};


#endif //CHAOS_RENDERINGSYSTEM_H
