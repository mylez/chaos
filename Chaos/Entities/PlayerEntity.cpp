#include <iostream>
#include <map>
#include "Core/Graphics.h"
#include "PlayerEntity.h"

/**
 *
 */
PlayerEntity::PlayerEntity()
{
    red_ = (Uint8)(rand() % 256);
    green_ = (Uint8)(rand() % 256);
    blue_ = (Uint8)(rand() % 256);

    velocity_ = (double)(rand() % 100) / 100 + 0.1;

    setPosition(rand() % 500, rand() % 500);
}


/**
 *
 * @param renderer
 */
void PlayerEntity::render(Graphics *g)
{
    int boxSize = 10;
    static double time = 0;

    Vec2I
        pos((int)getXPosition() - boxSize, (int)getYPosition() - boxSize),
        size(boxSize, boxSize);

    g->setColor(
        (int)(red_*pow(sin(3 * velocity_ + time * .1), 2)),
        (int)(green_*pow(sin(velocity_ + time * .2), 2)),
        (int)(blue_*pow(2*velocity_ + sin(time * .3), 2)),
        80
    );
    g->setColor(red_, green_, blue_, 255);

    g->fillRect(pos, size);
    g->setColor(red_, green_, blue_, 180);
    g->drawRect(pos, size);
    time += 0.00006;
}

/**
 *
 * @param timeElapsed
 */
void PlayerEntity::update(double timeElapsed)
{
    time_ += timeElapsed;

    //->setColor(
    //   (int)(red_*pow(sin(3 * velocity_ + time * .1), 2)),
    //   (int)(green_*pow(sin(velocity_ + time * .2), 2)),
    //   (int)(blue_*pow(2*velocity_ + sin(time * .3), 2)),
    //   80
    //;

    double
        newX = getXPosition() + timeElapsed * velocity_ * pow(sin(time_ / 5000), 2),
        newY = getYPosition() + timeElapsed * velocity_ * pow(sin(time_ / 4000), 2);

    int box = 2000;

    setXPosition(newX < box ? newX : newX - box);
    setYPosition(newY < box ? newY : newY - box);
}

