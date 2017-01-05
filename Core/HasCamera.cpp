#include "HasCamera.h"

HasCamera::HasCamera()
{
    this->camera_ = &defaultCamera;
}

HasCamera::HasCamera(Camera *camera)
{
    this->camera_ = camera;
}

Camera *HasCamera::getCamera()
{
    return camera_;
}