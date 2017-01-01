#include "HasPosition.h"


/**
 *
 * @param x
 * @param y
 */
void HasPosition::queryPosition(double *x, double *y)
{
    if (x) *x = getXPosition();
    if (y) *y = getYPosition();
}


/**
 *
 * @param x
 * @param y
 */
void HasPosition::setPosition(double x, double y)
{
    setXPosition(x);
    setYPosition(y);
}


/**
 *
 * @param x
 */
void HasPosition::setXPosition(double x)
{
    posX_ = x;
}


/**
 *
 * @param y
 */
void HasPosition::setYPosition(double y)
{
    posY_ = y;
}


/**
 *
 * @return
 */
double HasPosition::getXPosition()
{
    return posX_;
}


/**
 *
 * @return
 */
double HasPosition::getYPosition()
{
    return posY_;
};