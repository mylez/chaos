#ifndef CHAOS_SCRIPT_H
#define CHAOS_SCRIPT_H

#include <Core/Collision.h>
#include <Core/InputEvent.h>
#include <SDL2/SDL.h>
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

    bool hasInit_, managed_;

    Entity *entity;

    Game *game;

    double timeElapsed;

    Script():
        id(++nextId_),
        hasInit_(false),
        managed_(false),
        game(nullptr),
        entity(nullptr),
        timeElapsed(0)
    {}

    /**
     *
     * @param game
     * @param entity
     */
    void performInit(Game *game, Entity *entity)
    {
        this->entity = entity;
        this->game = game;
        timeElapsed = 0;

        init();
        hasInit_ = true;
    }

    /**
     *
     */
    virtual void init()
    {}

    void performDeinit()
    {
        deinit();
    }

    virtual void deinit()
    {};

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

    /**
     *
     * @param inputEvent
     */
    virtual void onInputEvent(InputEvent inputEvent)
    {}

    /**
     *
     * @param inputEvent
     */
    virtual void onInputEvent(SDL_Event inputEvent)
    {}

    GameState *gameState();
};


#endif //CHAOS_SCRIPT_H
