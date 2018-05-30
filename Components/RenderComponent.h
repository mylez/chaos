#ifndef CHAOS_RENDERCOMPONENT_H
#define CHAOS_RENDERCOMPONENT_H

#include <Core/Component.h>

typedef enum COORD
{
    CARTESIAN,
    ISOMETRIC
} RenderCoordSystem;

class RenderComponent:
    public Component
{
public:
    RenderCoordSystem renderCoordSystem = COORD::CARTESIAN;
    RenderComponent() { label = COMPONENT_RENDER; }
};


#endif //CHAOS_RENDERCOMPONENT_H
