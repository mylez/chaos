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
        pos((int)getXPosition() - 25, (int)getYPosition() - 25),
        size(25, 25);

    g->setColor(red_, green_, blue_, 100);
    g->fillRect(pos, size);

    g->setColor(red_, green_, blue_, 255);
    g->drawRect(pos, size);
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

    int box = 2500;

    setXPosition(newX < box ? newX : newX - box);
    setYPosition(newY < box ? newY : newY - box);
}

