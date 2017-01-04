#include "Vec2D.h"
#include "Vec2I.h"

Vec2D::Vec2D(Vec2I a)
{
    x = (double)a.x;
    y = (double)a.y;
}

/**
 *
 * @param _x
 * @param _y
 */
Vec2D::Vec2D(double _x, double _y)
{
    x = _x;
    y = _y;
}


/**
 *
 * @param a
 * @return
 */
Vec2D Vec2D::entryMult(Vec2D a)
{
    return Vec2D(
        x * a.x,
        y * a.y
    );
}


/**
 *
 * @param a
 * @return
 */
Vec2D Vec2D::add(Vec2D a)
{
    return Vec2D(
        x + a.x,
        y + a.y
    );
}