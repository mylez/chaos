#ifndef CHAOS_HASCAMERA_H
#define CHAOS_HASCAMERA_H

#include "vec2d.h"
#include "Camera.h"

class HasCamera
{
private:
    Camera
        defaultCamera,
        *camera_;
public:
    HasCamera();
    HasCamera(Camera *camera);
    Camera *getCamera();
};


#endif //CHAOS_HASCAMERA_H
