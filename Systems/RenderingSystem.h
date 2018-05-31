#ifndef CHAOS_RENDERINGSYSTEM_H
#define CHAOS_RENDERINGSYSTEM_H

#include <Core/Component.h>
#include <Core/System.h>
#include <Core/Graphics.h>
#include <Core/AssetLibrary.h>
#include <Components/CameraComponent.h>


const double
        i_p_cm = 1/2.54,  // disp in per disp cm
        cm_p_m = 3,             // disp cm per world meter
        d = i_p_cm * cm_p_m;    // disp in per world meter


class RenderingSystem:
    public System
{
private:

    Vec2i
            windowSize_i_,
            mousePosition;

    Vec2d
            windowSize_d_;

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

    std::map<unsigned int, bool>
            cursorHover,
            currentHover;


public:
    RenderingSystem()
    { signature = COMPONENT_TRANSFORM | COMPONENT_RENDER; }

    void init() override;

    void update(double timeElapsed, std::vector<Entity *> entities) override;

    void renderShape(Entity *entity);

    void renderSprite(Entity *entity, double timeElapsed);

    void updateCursor();

    void renderCursor();

    Vec2i worldToDisp(Vec2d p);

    Vec2i scale_worldToDisp(Vec2d s);

    Vec2d dispToWorld(Vec2i p_);

    Vec2d scale_dispToWorld(Vec2i s_);
};


#endif //CHAOS_RENDERINGSYSTEM_H
