#ifndef CHAOS_COLOR_H
#define CHAOS_COLOR_H
#include <random>


struct Color
{
    int r, g, b, a;

    Color():
        r(0), g(0), b(0), a(255)
    {}

    Color(int r_, int g_, int b_, int a_):
        r(r_), g(g_), b(b_), a(a_)
    {}

    Color(int r_, int g_, int b_):
        r(r_), g(g_), b(b_), a(255)
    {}

    static Color random()
    {
        return random(0);
    }

    static Color random(int min)
    {
        return Color(min + rand()%(256 - min), min + rand()%(256 - min), min + rand()%(256 - min));
    }
};


#endif //CHAOS_COLOR_H
