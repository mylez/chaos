#include "HasEntities.h"
#include "Entity.h"


/**
 *
 * @return
 */
std::vector<Entity *> HasEntities::getEntities()
{
    return entities_;
}


/**
 *
 * @param entity
 */
void HasEntities::addEntity(Entity *entity)
{
    entities_.push_back(entity);
}
