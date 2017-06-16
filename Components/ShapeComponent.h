#ifndef CHAOS_RECTRENDERCOMPONENT_H
#define CHAOS_RECTRENDERCOMPONENT_H

#include <Core/Component.h>
#include <Core/Vec2d.h>
#include <Core/Color.h>

class ShapeComponent:
    public Component
{
public:
    Vec2d size;
    Color color;
    ShapeComponent():
        size(Vec2d(20, 20)),
        color(Color(100, 100, 100))

    { label = COMPONENT_SHAPE; }
};


#endif //CHAOS_RECTRENDERCOMPONENT_H
