#include <Chaos/GameObjects/PlayerGameObject.h>
#include "WorldScene.h"

WorldScene::WorldScene()
{
    for (int i = 0; i < 40000; i++)
    {
        addGameObject(new PlayerGameObject());
    }

}

void WorldScene::render(SDL_Renderer *renderer)
{
    SDL_RenderDrawRect(renderer, )
}
