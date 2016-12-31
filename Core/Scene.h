#ifndef CHAOS_SCENE_H
#define CHAOS_SCENE_H


#include <vector>
#include "GameObject.h"
#include "HasInputEventListeners.h"

class Scene:
    public HasInputEventListeners
{
public:
    std::vector<GameObject *> getGameObjects();
    void addGameObject(GameObject *gameObject);
private:

    std::vector<GameObject *> gameObjects_;
};


#endif //CHAOS_SCENE_H
