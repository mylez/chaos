#ifndef CHAOS_SCRIPT_H
#define CHAOS_SCRIPT_H

#include <Core/Collision.h>

class Game;
class Entity;

class Script
{
private:
    static unsigned int nextId_;

public:
    Script()
    {
        id = ++nextId_;
    }

    unsigned int id;

    virtual void update(Game *game, Entity *entity, double timeElapsed)
    {}

    virtual void onCollisionEnter(Collision collision)
    {}

    virtual void onCollisionExit(Collision collision)
    {}
};


#endif //CHAOS_SCRIPT_H
