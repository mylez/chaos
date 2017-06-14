#ifndef CHAOS_SYSTEM_H
#define CHAOS_SYSTEM_H

#include <vector>

class Entity;

class System {
public:
    unsigned long signature = 0;
    virtual void init() {}
    virtual void update(double timeElapsed, Entity *entity, std::vector<Entity *>) = 0;
};


#endif //CHAOS_SYSTEM_H
