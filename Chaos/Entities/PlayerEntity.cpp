#include <cstdlib>
#include <iostream>
#include "PlayerEntity.h"


/**
 *
 */
PlayerEntity::PlayerEntity()
{
    red_ = (Uint8)(rand() % 256);
    green_ = (Uint8)(rand() % 256);
    blue_ = (Uint8)(rand() % 256);
    velocity_ = (double)(rand() % 105) / 100 + 0.1;
    setPosition(rand() % 1500, rand() % 1500);
}


/**
 *
 * @param renderer
 */
void PlayerEntity::render(SDL_Renderer *renderer)
{
    int size = 25;
    SDL_Rect destination = {(int)getXPosition() - size, (int)getYPosition() - size, size, size};
    SDL_SetRenderDrawColor(renderer, red_, green_, blue_, 125);
    SDL_RenderFillRect(renderer, &destination);
}


/**
 *
 * @param timeElapsed
 */
void PlayerEntity::update(double timeElapsed)
{
    time_ += timeElapsed;
    double newX = getXPosition() + timeElapsed * velocity_ * pow(sin(time_ / 900), 2),
        newY = getYPosition() + timeElapsed * velocity_ * pow(sin(time_ / 800), 2);

    setXPosition(newX < 800 ? newX : newX - 800);
    setYPosition(newY < 800 ? newY : newY - 800);
}

