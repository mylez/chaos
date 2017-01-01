#include "Scene.h"


/**
 *
 * @return
 */
std::vector<GameObject *> Scene::getGameObjects()
{
    return gameObjects_;
}


/**
 *
 * @param gameObject
 */
void Scene::addGameObject(GameObject *gameObject)
{
    gameObjects_.push_back(gameObject);
}
