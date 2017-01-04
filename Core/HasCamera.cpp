#include "HasCamera.h"

void HasCamera::setCameraPosition(Vec2D newPos)
{
    cameraPosition_ = newPos;
}

Vec2D HasCamera::getCameraPosition()
{
    return cameraPosition_;
}