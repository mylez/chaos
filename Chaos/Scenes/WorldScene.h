#ifndef CHAOS_WORLDSCENE_H
#define CHAOS_WORLDSCENE_H

#include "Core/Scene.h"

class WorldScene:
    public Scene
{
public:
    WorldScene();
    void render(SDL_Renderer *renderer);
};


#endif //CHAOS_WORLDSCENE_H
