#include "Scene.h"


/**
 *
 * @return
 */
std::vector<Entity *> Scene::getEntities()
{
    return entities_;
}


/**
 *
 * @param entity
 */
void Scene::addEntity(Entity *entity)
{
    entities_.push_back(entity);
}
