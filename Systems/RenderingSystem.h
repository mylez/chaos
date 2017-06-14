#ifndef CHAOS_RENDERINGSYSTEM_H
#define CHAOS_RENDERINGSYSTEM_H

#include <Core/Component.h>
#include <Core/System.h>
#include <Core/Graphics.h>
#include <Core/AssetLibrary.h>

class RenderingSystem:
    public System
{
    Graphics *graphics;

    AssetLibrary *assetLibrary;

public:
    RenderingSystem()
    { signature = COMPONENT_TRANSFORM | COMPONENT_RENDER; }

    void init(Game *game);

    void update(double timeElapsed, std::vector<Entity *> entities);

    void renderShape(Entity *entity);

    void renderSprite(Entity *entity);

    void renderAnimatedSprite(Entity *entity);
};


#endif //CHAOS_RENDERINGSYSTEM_H
