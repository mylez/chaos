#include "Vec2I.h"


Vec2I::Vec2I(int _x, int _y)
{
    x = _x;
    y = _y;
}


Vec2I Vec2I::add(Vec2I a)
{
    return Vec2I(
        x + a.x,
        y + a.y
    );
}


Vec2I::Vec2I()
{
    x = 0;
    y = 0;
}
