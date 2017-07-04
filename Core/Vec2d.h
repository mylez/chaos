#ifndef CHAOS_VEC2D_H
#define CHAOS_VEC2D_H

#include "Vec2d.h"
#include "Vec2i.h"

class Vec2d
{
public:
    Vec2d(): x(0), y(0) {}

    Vec2d(Vec2i a);

    Vec2d(double _x, double _y);

    Vec2d hadamard(Vec2d a);

    Vec2d hadamard(double x, double y);

    Vec2d divide(Vec2d a);

    Vec2d divide(double a, double b);

    Vec2d add(Vec2d a);

    Vec2d scale(double a)
    {
        return Vec2d(a * x, a * y);
    }

    Vec2i asVec2i()
    {
        return Vec2i(static_cast<int>(x), static_cast<int>(y));

    }

    double x, y;
};


#endif //CHAOS_VEC2D_H
