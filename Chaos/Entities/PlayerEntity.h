#ifndef CHAOS_PLAYERGAMEOBJECT_H
#define CHAOS_PLAYERGAMEOBJECT_H
#include <iostream>
#include "WorldEntity.h"




class PlayerEntity
{
private:
    vec2d position;

public:
    void render(Graphics *g)
    {
        std::cout<<"shit\n";
    }
    void update(double timeElapsed)
    {
        std::cout<<"fuck\n";
    }
};


#endif //CHAOS_PLAYERGAMEOBJECT_H
