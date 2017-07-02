#ifndef CHAOS_VEC2I_H
#define CHAOS_VEC2I_H


class Vec2i
{
public:
    Vec2i();

    Vec2i(int _x, int _y);

    Vec2i add(Vec2i a);

    int x, y;

    /**
     *
     * @param a
     * @return
     */
    Vec2i entryMult(Vec2i a)
    {
        return Vec2i(
            x * a.x,
            y * a.y
        );
    }
};


#endif //CHAOS_VEC2I_H
