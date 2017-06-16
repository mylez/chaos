#ifndef CHAOS_SCRIPT_H
#define CHAOS_SCRIPT_H

#include <Core/Collision.h>
#include <iostream>

class Game;

class Entity;

class Script
{
private:
    static unsigned int nextId_;

public:
    unsigned int id;

    bool hasInit_;

    Script():
        id(++nextId_),
        hasInit_(false)
    {}

    inline void doInit(Game *game, Entity *entity)
    {
        init(game, entity);
        hasInit_ = true;
    }

    virtual void init(Game *game, Entity *entity)
    {}

    virtual void update(Game *game, Entity *entity, double timeElapsed)
    {}

    virtual void onCollisionEnter(Collision collision)
    {}

    virtual void onCollisionExit(Collision collision)
    {}
};


#endif //CHAOS_SCRIPT_H
