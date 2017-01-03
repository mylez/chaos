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
    Scene *scene_ = &defaultScene;

public:
    Scene *getScene();
    void setScene(Scene *scene);
    void handleInputEvent(SDL_Event *event);
    void update(double timeElapsed);
    void render(Graphics *g);
};


#endif //CHAOS_SCENEGAMESTATE_H
