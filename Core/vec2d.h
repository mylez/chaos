#ifndef CHAOS_VEC2D_H
#define CHAOS_VEC2D_H

#include "vec2d.h"
#include "vec2i.h"

class vec2d
{
public:
    vec2d(vec2i a);
    vec2d(double _x, double _y);
    vec2d entryMult(vec2d a);
    vec2d add(vec2d a);
    double x, y;
};


#endif //CHAOS_VEC2D_H
