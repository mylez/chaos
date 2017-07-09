#ifndef CHAOS_BOUNDINGBOXCOMPONENT_H
#define CHAOS_BOUNDINGBOXCOMPONENT_H

#include <Core/Component.h>

class BoundingBoxComponent:
    public Component
{
public:
    Vec2d
        size,
        position;

    BoundingBoxComponent():
        size(Vec2d(0, 0)),
        position(Vec2d(0, 0))
    { label = COMPONENT_BOUNDING_BOX; }
};


#endif //CHAOS_BOUNDINGBOXCOMPONENT_H
