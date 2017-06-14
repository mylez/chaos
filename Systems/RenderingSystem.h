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
    RenderingSystem(Graphics *g) :
        graphics(g)
    { signature = COMPONENT_TRANSFORM | COMPONENT_RENDER; }

    void update(double timeElapsed, Entity *entity, std::vector<Entity *> entities);

    void renderShape(Entity *entity);

    void renderSprite(Entity *entity);

    void renderAnimatedSprite(Entity *entity);
};


#endif //CHAOS_RENDERINGSYSTEM_H
