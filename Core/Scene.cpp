#include "Scene.h"

std::vector<GameObject *> Scene::getGameObjects()
{
    return gameObjects_;
}

void Scene::addGameObject(GameObject *gameObject)
{
    gameObjects_.push_back(gameObject);
}
