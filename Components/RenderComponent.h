#ifndef CHAOS_RENDERCOMPONENT_H
#define CHAOS_RENDERCOMPONENT_H

#include <Core/Component.h>

typedef enum COORD
{
    ISOMETRIC
} RenderCoordSystem;

class RenderComponent:
    public Component
{
public:
    RenderCoordSystem renderCoordSystem;

    RenderComponent()
    {
        label = COMPONENT_RENDER;
        renderCoordSystem = COORD::ISOMETRIC;
    }
};


#endif //CHAOS_RENDERCOMPONENT_H
