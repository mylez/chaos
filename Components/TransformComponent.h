#ifndef CHAOS_TRANSFORMCOMPONENT_H
#define CHAOS_TRANSFORMCOMPONENT_H



#include <Core/Component.h>
#include <Core/System.h>
#include <Core/vec2d.h>

class TransformComponent:
    public Component
{
public:
    vec2d
        position,
        scale;
    double
        rotation;
    TransformComponent():
        position(vec2d(0, 0)),
        scale(vec2d(1, 1))
    { label = COMPONENT_TRANSFORM; }
};




#endif //CHAOS_TRANSFORMCOMPONENT_H
