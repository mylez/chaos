#ifndef CHAOS_HASCAMERA_H
#define CHAOS_HASCAMERA_H

#include "Vec2D.h"

class HasCamera
{
private:
    Vec2D cameraPosition_ = Vec2D(0, 0);
public:
    void setCameraPosition(Vec2D newPos);
    Vec2D getCameraPosition();
};


#endif //CHAOS_HASCAMERA_H
