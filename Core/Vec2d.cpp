#include "Vec2d.h"
#include "Vec2i.h"

Vec2d::Vec2d(Vec2i a)
{
    x = (double) a.x;
    y = (double) a.y;
}

/**
 *
 * @param _x
 * @param _y
 */
Vec2d::Vec2d(double _x, double _y)
{
    x = _x;
    y = _y;
}


/**
 *
 * @param a
 * @return
 */
Vec2d Vec2d::entryMult(Vec2d a)
{
    return Vec2d(
        x * a.x,
        y * a.y
    );
}


/**
 *
 * @param a
 * @return
 */
Vec2d Vec2d::add(Vec2d a)
{
    return Vec2d(
        x + a.x,
        y + a.y
    );
}