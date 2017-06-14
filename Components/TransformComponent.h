#ifndef CHAOS_TRANSFORMCOMPONENT_H
#define CHAOS_TRANSFORMCOMPONENT_H



#include <Core/Component.h>
#include <Core/System.h>
#include <Core/Vec2d.h>

class TransformComponent:
    public Component
{
public:
    Vec2d
        position,
        scale;
    double
        rotation;
    TransformComponent():
        position(Vec2d(0, 0)),
        scale(Vec2d(1, 1))
    { label = COMPONENT_TRANSFORM; }
};




#endif //CHAOS_TRANSFORMCOMPONENT_H
