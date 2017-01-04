#ifndef CHAOS_VEC2D_H
#define CHAOS_VEC2D_H

#include "Vec2D.h"
#include "Vec2I.h"

class Vec2D
{

public:
    Vec2D(Vec2I a);
    Vec2D(double _x, double _y);
    Vec2D entryMult(Vec2D a);
    Vec2D add(Vec2D a);
    double x, y;

};


#endif //CHAOS_VEC2D_H
