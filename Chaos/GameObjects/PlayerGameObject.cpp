#include <cstdlib>
#include <iostream>
#include "PlayerGameObject.h"


/**
 *
 */
PlayerGameObject::PlayerGameObject()
{
    velocity_ = (double)(rand() % 105) / 100 + 0.1;
    setPosition(rand() % 1500, rand() % 1500);
    setProperty("name", "Puppy");
}


/**
 *
 * @param renderer
 */
void PlayerGameObject::render(SDL_Renderer *renderer)
{
    //SDL_Rect rect = {(int)getXPosition(), (int)getYPosition(), 64, 64};
    //SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    //SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderDrawPoint(renderer, (int)getXPosition(), (int)(getYPosition()));
}


/**
 *
 * @param timeElapsed
 */
void PlayerGameObject::update(double timeElapsed)
{
    time_ += timeElapsed;
    double newX = getXPosition() + timeElapsed * velocity_ * pow(sin(time_ / 3000), 2),
        newY = getYPosition() + timeElapsed * velocity_ * pow(sin(time_ / 2000), 2);
    setXPosition(newX < 3000 ? newX : newX - 3000);
    setYPosition(newY < 1800 ? newY : newY - 1800);
}

