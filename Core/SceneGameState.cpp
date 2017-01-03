#include "SceneGameState.h"


/**
 *
 * @param event
 */
void SceneGameState::handleInputEvent(SDL_Event *event)
{
    scene_->handleInputEvent(event);
}


/**
 * this method can be overridden in a custom SceneGameState
 *
 * @param renderer
 */
void SceneGameState::render(Graphics *g)
{
    for (const auto &gameObject: getScene()->getEntities())
    {
        gameObject->render(g);
    }
}


/**
 * this method can be overridden in a custom SceneGameState
 *
 * @param timeElapsed
 */
void SceneGameState::update(double timeElapsed)
{
    for (const auto &gameObject: getScene()->getEntities())
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
