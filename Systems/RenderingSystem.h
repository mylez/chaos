#ifndef CHAOS_RENDERINGSYSTEM_H
#define CHAOS_RENDERINGSYSTEM_H

#include <Core/Component.h>
#include <Core/System.h>
#include <Core/Graphics.h>
#include <Core/AssetLibrary.h>

#include <Components/CameraComponent.h>

class RenderingSystem:
    public System
{
private:

    Vec2i
        windowSize_;

    Graphics
        *graphics_
        = nullptr;

    AssetLibrary
        *assetLibrary_
        = nullptr;

    Entity
        *cameraEntity
        = nullptr;

    CameraComponent
        *cameraComponent
        = nullptr;


public:
    RenderingSystem()
    { signature = COMPONENT_TRANSFORM | COMPONENT_RENDER; }

    void init(Game *game);

    void update(double timeElapsed, std::vector<Entity *> entities);

    void renderShape(Entity *entity);

    void renderSprite(Entity *entity);

    void renderAnimation(Entity *entity);

    void renderTerrain(Entity *entity);

    Vec2d positionInCamera(Vec2d position);
};


#endif //CHAOS_RENDERINGSYSTEM_H
