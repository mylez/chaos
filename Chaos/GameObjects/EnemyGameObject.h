#ifndef CHAOS_ENEMYGAMEOBJECT_H
#define CHAOS_ENEMYGAMEOBJECT_H


#include <Core/GameObject.h>

class EnemyGameObject:
    public GameObject
{
public:
    void render(SDL_Renderer *renderer);
    void update(double timeElapsed);
};


#endif //CHAOS_ENEMYGAMEOBJECT_H
