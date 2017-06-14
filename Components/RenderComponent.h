#ifndef CHAOS_RENDERCOMPONENT_H
#define CHAOS_RENDERCOMPONENT_H

#include <Core/Component.h>

class RenderComponent:
    public Component
{
public:
    RenderComponent()
    { label = COMPONENT_RENDER; }
};


#endif //CHAOS_RENDERCOMPONENT_H
