#include <Chaos/GameObjects/PlayerGameObject.h>
#include "WorldSceneGameState.h"


WorldSceneGameState::WorldSceneGameState()
{
    static PlayerGameObject
        playerGameObject1,
        playerGameObject2,
        playerGameObject3,
        playerGameObject4,
        playerGameObject5,
        playerGameObject6,
        playerGameObject7,
        playerGameObject8;

    scene_->addGameObject(&playerGameObject1);
    scene_->addGameObject(&playerGameObject2);
    scene_->addGameObject(&playerGameObject3);
    scene_->addGameObject(&playerGameObject4);
    scene_->addGameObject(&playerGameObject5);
    scene_->addGameObject(&playerGameObject6);
    scene_->addGameObject(&playerGameObject7);
    scene_->addGameObject(&playerGameObject8);
}

void WorldSceneGameState::render(SDL_Renderer *renderer)
{
    for (const auto &gameObject: scene_->getGameObjects())
    {
        double x, y;
        gameObject->queryPosition(&x, &y);

        SDL_Rect rect = {(int)x, (int)y, 32, 32};

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
    }
}



void WorldSceneGameState::update(double timeElapsed)
{
    for (const auto &gameObject: scene_->getGameObjects())
    {
        double x, y;
        gameObject->queryPosition(&x, NULL);

        x += (int)timeElapsed / 3;

        if (x > 600)
        {
            x = 0;
        }

        gameObject->setXPosition(x);
    }
}