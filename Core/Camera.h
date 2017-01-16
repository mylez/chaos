#ifndef CHAOS_CAMERA_H
#define CHAOS_CAMERA_H

#include "HasUpdate.h"
#include "vec2d.h"

class Camera:
    public HasUpdate
{
private:
    vec2d cameraPosition_;
public:
    Camera():
        cameraPosition_(0, 0)
    {};
    virtual void setCameraPosition(vec2d pos)
    {
        cameraPosition_ = pos;
    };
    virtual vec2d getCameraPosition()
    {
        return cameraPosition_;
    };
};


#endif //CHAOS_CAMERA_H
