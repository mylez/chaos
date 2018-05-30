#include "Vec2i.h"
#include "Vec2d.h"


Vec2i::Vec2i(int _x, int _y)
{
    x = _x;
    y = _y;
}


Vec2i Vec2i::add(Vec2i a)
{
    return Vec2i(
            x + a.x,
            y + a.y
    );
}


Vec2i::Vec2i()
{
    x = 0;
    y = 0;
}
