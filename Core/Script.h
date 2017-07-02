#ifndef CHAOS_SCRIPT_H
#define CHAOS_SCRIPT_H

#include <Core/Collision.h>
#include <iostream>

class Game;

class Entity;

class GameState;

class Script
{
private:
    static unsigned int nextId_;

public:
    unsigned int id;

    bool hasInit_;

    Entity *entity;

    Game *game;

    Script():
        id(++nextId_),
        hasInit_(false)
    {}

    inline void doInit(Game *game, Entity *entity)
    {
        init(entity);
        hasInit_ = true;
    }

    virtual void init(Entity *entity)
    {}

    virtual void update(Game *game, Entity *entity, double timeElapsed)
    {}

    virtual void update(Entity *entity)
    {}

    virtual void onCollisionEnter(Collision collision)
    {}

    virtual void onCollisionExit(Collision collision)
    {}

    GameState *gameState();
};


#endif //CHAOS_SCRIPT_H
