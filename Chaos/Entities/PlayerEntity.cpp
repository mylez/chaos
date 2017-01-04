#include <iostream>
#include "Core/Graphics.h"
#include "Core/Vec2I.h"
#include "Core/Vec2D.h"
#include "PlayerEntity.h"

/**
 *
 */
PlayerEntity::PlayerEntity()
{
    red_ = (Uint8)(rand() % 256);
    green_ = (Uint8)(rand() % 256);
    blue_ = (Uint8)(rand() % 256);

    velocity_ = (double)(rand() % 40) / 100 + 0.1;

    setPosition(rand() % 1000, rand() % 1000);
}


/**
 *
 * @param renderer
 */
void PlayerEntity::render(Graphics *g)
{
    Vec2I
        pos((int)getXPosition(), (int)getYPosition()),
        size(25, 25);

    g->setColor(red_, green_, blue_, 255);
    g->fillRect(pos, size);
}

/**
 *
 * @param timeElapsed
 */
void PlayerEntity::update(double timeElapsed)
{
    time_ += timeElapsed;

    double
        newX = getXPosition() + timeElapsed * velocity_ * pow(sin(time_ / 2000), 2),
        newY = getYPosition() + timeElapsed * velocity_ * pow(sin(time_ / 1000), 2);

    setXPosition(newX < 800 ? newX : newX - 800);
    setYPosition(newY < 800 ? newY : newY - 800);
}

