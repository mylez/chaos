#ifndef CHAOS_PLAYERGAMEOBJECT_H
#define CHAOS_PLAYERGAMEOBJECT_H

#include "Core/Entity.h"

class PlayerEntity:
    public Entity
{
public:
    double velocity_, time_;

    PlayerEntity();

    Uint8 red_, green_, blue_;

    void render(SDL_Renderer *renderer);

    void update(double timeElapsed);

};


#endif //CHAOS_PLAYERGAMEOBJECT_H
