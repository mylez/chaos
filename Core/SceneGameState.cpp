#include "SceneGameState.h"


SceneGameState::SceneGameState()
{

}


void SceneGameState::handleInputEvent(SDL_Event *event)
{
    this->scene->handleInputEvent(event);
}

