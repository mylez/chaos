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
            windowSize_i_;

    Vec2d
            windowSize_d_,
            dotsPerMeter;

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

    void init() override;

    void update(double timeElapsed, std::vector<Entity *> entities) override;

    void renderShape(Entity *entity);

    void renderSprite(Entity *entity, double timeElapsed);

    Vec2i worldToDisp(Vec2d p);

    Vec2i scale_worldToDisp(Vec2d s);

    Vec2d dispToWorld(Vec2i p_);

    Vec2d scale_dispToWorld(Vec2i s_);
};


#endif //CHAOS_RENDERINGSYSTEM_H
