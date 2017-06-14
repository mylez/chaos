#ifndef CHAOS_SYSTEM_H
#define CHAOS_SYSTEM_H

#include <vector>

class Entity;
class Game;

class System
{
public:
    unsigned long signature = 0;
    virtual void init(Game *game) {}
    virtual void update(double timeElapsed, std::vector<Entity *> entity) = 0;
};


#endif //CHAOS_SYSTEM_H
