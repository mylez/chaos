#include <Chaos/GameObjects/PlayerGameObject.h>
#include "WorldSceneGameState.h"
#include <SDL2/SDL.h>


WorldSceneGameState::WorldSceneGameState()
{
    setScene(&worldScene_);
}


void WorldSceneGameState::render(SDL_Renderer *renderer)
{
    worldScene_.render(renderer);
}

