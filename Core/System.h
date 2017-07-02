#ifndef CHAOS_SYSTEM_H
#define CHAOS_SYSTEM_H

#include <vector>

class Entity;

class Game;

class System
{
public:
    unsigned long signature = 0;

    bool managed_ = false;

    virtual void init(Game *game)
    {}

    virtual void update(double timeElapsed, std::vector<Entity *> entities) = 0;
};


#endif //CHAOS_SYSTEM_H
