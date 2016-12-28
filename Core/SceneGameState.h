//
// Created by Miles on 12/27/16.
//

#ifndef CHAOS_SCENEGAMESTATE_H
#define CHAOS_SCENEGAMESTATE_H


#include <iostream>
#include "Scene.h"
#include "GameState.h"

class SceneGameState: public GameState
{
public:
    Scene *scene;

    void handleInputEvent(SDL_Event *event);
};


#endif //CHAOS_SCENEGAMESTATE_H
