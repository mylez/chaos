#ifndef CHAOS_VEC2D_H
#define CHAOS_VEC2D_H

#include "Vec2d.h"
#include "Vec2i.h"

class Vec2d
{
public:
    Vec2d(Vec2i a);
    Vec2d(double _x, double _y);
    Vec2d entryMult(Vec2d a);
    Vec2d add(Vec2d a);
    Vec2d scale(double a) { return Vec2d(a*x, a*y); }
    Vec2i asVec2i()
    {
        return Vec2i(x, y);
    }
    double x, y;
};


#endif //CHAOS_VEC2D_H
