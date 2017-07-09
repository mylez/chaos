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

    double timeElapsed;

    Script():
        id(++nextId_),
        hasInit_(false),
        game(nullptr),
        entity(nullptr),
        timeElapsed(0)
    {}

    /**
     *
     * @param game
     * @param entity
     */
    inline void doInit(Game *game, Entity *entity)
    {
        init(entity);
        hasInit_ = true;
    }

    /**
     *
     * @param entity
     */
    virtual void init(Entity *entity)
    {}

    /**
     *
     */
    virtual void update()
    {}

    /**
     *
     * @param collision
     */
    virtual void onCollisionEnter(Collision collision)
    {}

    /**
     *
     * @param collision
     */
    virtual void onCollisionExit(Collision collision)
    {}

    GameState *gameState();
};


#endif //CHAOS_SCRIPT_H
