#ifndef CHAOS_HASENTITIES_H
#define CHAOS_HASENTITIES_H

#include <vector>
#include "Entity.h"


class HasEntities
{
public:
    std::vector<Entity *> getEntities();
    void addEntity(Entity *entity);

private:
    std::vector<Entity *> entities_;
};


#endif //CHAOS_HASENTITIES_H
