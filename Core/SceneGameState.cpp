#include "SceneGameState.h"


SceneGameState::SceneGameState()
{

}


/**
 *
 * @param event
 */
void SceneGameState::handleInputEvent(SDL_Event *event)
{
    this->scene->handleInputEvent(event);
}

