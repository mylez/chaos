#include "WorldSceneGameState.h"


WorldSceneGameState::WorldSceneGameState()
{

}

void WorldSceneGameState::render(SDL_Renderer *renderer)
{

}

void WorldSceneGameState::update()
{
    std::cout << "update\n";
    for (const auto &gameObject: this->scene->getGameObjects())
    {
        double x, y;
        gameObject->queryPosition(&x, NULL);

        y = 50;

        x += 5;
        if (x > 300) x = 0;

    }
}