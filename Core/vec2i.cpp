#include "vec2i.h"


vec2i::vec2i(int _x, int _y)
{
    x = _x;
    y = _y;
}


vec2i vec2i::add(vec2i a)
{
    return vec2i(
        x + a.x,
        y + a.y
    );
}


vec2i::vec2i()
{
    x = 0;
    y = 0;
}
