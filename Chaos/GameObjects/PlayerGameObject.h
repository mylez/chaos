#ifndef CHAOS_PLAYERGAMEOBJECT_H
#define CHAOS_PLAYERGAMEOBJECT_H

#include "Core/GameObject.h"

class PlayerGameObject:
    public GameObject
{
public:
    double velocity_, time_;

    PlayerGameObject();

    void render(SDL_Renderer *renderer);

    void update(double timeElapsed);

};


#endif //CHAOS_PLAYERGAMEOBJECT_H
