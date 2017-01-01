#include "SceneGameState.h"


/**
 *
 * @param event
 */
void SceneGameState::handleInputEvent(SDL_Event *event)
{
    this->scene_->handleInputEvent(event);
}

/**
 * this method can be overridden in a custom SceneGameState
 *
 * @param renderer
 */
void SceneGameState::render(SDL_Renderer *renderer)
{
    for (const auto &gameObject: getScene()->getGameObjects())
    {
        gameObject->render(renderer);
    }
}


/**
 * this method can be overridden in a custom SceneGameState
 *
 * @param timeElapsed
 */
void SceneGameState::update(double timeElapsed)
{
    for (const auto &gameObject: getScene()->getGameObjects())
    {
        gameObject->update(timeElapsed);
    }
}


/**
 *
 * @return
 */
Scene *SceneGameState::getScene()
{
    return scene_;
}

/**
 *
 * @param scene
 */
void SceneGameState::setScene(Scene *scene)
{
    scene_ = scene;
}
