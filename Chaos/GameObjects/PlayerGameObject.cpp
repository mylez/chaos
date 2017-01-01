#include <cstdlib>
#include <iostream>
#include "PlayerGameObject.h"


/**
 *
 */
PlayerGameObject::PlayerGameObject()
{
    red_ = (Uint8)(rand() % 256);
    green_ = (Uint8)(rand() % 256);
    blue_ = (Uint8)(rand() % 256);
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
    SDL_Rect dest = {(int)getXPosition() - 75, (int)getYPosition() - 75, 75, 75};
    SDL_SetRenderDrawColor(renderer, red_, green_, blue_, 50);
    SDL_RenderFillRect(renderer, &dest);
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

