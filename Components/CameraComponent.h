#ifndef CHAOS_CAMERACOMPONENT_H
#define CHAOS_CAMERACOMPONENT_H

#include <Core/Component.h>

class RenderingSystem;

class CameraComponent:
    public Component
{
public:
    Color backgroundColor;

    RenderingSystem *renderingSystem;

    CameraComponent()
    {}
};


#endif //CHAOS_CAMERACOMPONENT_H
