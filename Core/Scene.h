#ifndef CHAOS_SCENE_H
#define CHAOS_SCENE_H


#include <vector>
#include "GameObject.h"
#include "HasInputEventListeners.h"

class Scene:
    public HasInputEventListeners
{
public:

private:

    std::vector<GameObject> gameObjects;


};


#endif //CHAOS_SCENE_H
