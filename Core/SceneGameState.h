#ifndef CHAOS_SCENEGAMESTATE_H
#define CHAOS_SCENEGAMESTATE_H

#include <iostream>
#include "Scene.h"
#include "GameState.h"
#include "DefaultScene.h"


class SceneGameState:
    public GameState
{
private:
    DefaultScene defaultScene;

public:
    Scene *scene_ = &defaultScene;
    SceneGameState();
    void handleInputEvent(SDL_Event *event);
};


#endif //CHAOS_SCENEGAMESTATE_H
