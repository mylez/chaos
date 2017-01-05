#ifndef CHAOS_CAMERA_H
#define CHAOS_CAMERA_H

#include "HasUpdate.h"
#include "Vec2D.h"

class Camera:
    public HasUpdate
{
private:
    Vec2D cameraPosition_;
public:
    Camera():
        cameraPosition_(0, 0)
    {};
    virtual void setCameraPosition(Vec2D pos)
    {
        cameraPosition_ = pos;
    };
    virtual Vec2D getCameraPosition()
    {
        return cameraPosition_;
    };
};


#endif //CHAOS_CAMERA_H
