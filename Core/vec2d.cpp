#include "vec2d.h"
#include "vec2i.h"

vec2d::vec2d(vec2i a)
{
    x = (double)a.x;
    y = (double)a.y;
}

/**
 *
 * @param _x
 * @param _y
 */
vec2d::vec2d(double _x, double _y)
{
    x = _x;
    y = _y;
}


/**
 *
 * @param a
 * @return
 */
vec2d vec2d::entryMult(vec2d a)
{
    return vec2d(
        x * a.x,
        y * a.y
    );
}


/**
 *
 * @param a
 * @return
 */
vec2d vec2d::add(vec2d a)
{
    return vec2d(
        x + a.x,
        y + a.y
    );
}