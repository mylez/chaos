#include "EnemyGameObject.h"

void EnemyGameObject::render(SDL_Renderer *renderer)
{
    SDL_Rect rect = {(int)getXPosition(), 25, 30, 30};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
}


void EnemyGameObject::update(double timeElapsed)
{
    double newPos = getXPosition() + timeElapsed * 0.05;
    setXPosition(newPos < 300 ? newPos : newPos - 300);
}