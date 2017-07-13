#ifndef CHAOS_SYSTEM_H
#define CHAOS_SYSTEM_H

#include <vector>

class Entity;

class Game;

class System
{
public:
    unsigned long signature;

    Game *game;

    bool managed_;

    double timeElapsed;

    System():
        game(nullptr),
        managed_(false),
        signature(0)
    {}

    virtual void init()
    {}

    virtual void deinit()
    {}

    virtual void update(double timeElapsed, std::vector<Entity *> entities) = 0;
};


#endif //CHAOS_SYSTEM_H
