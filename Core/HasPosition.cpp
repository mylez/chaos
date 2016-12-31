#include "HasPosition.h"

void HasPosition::queryPosition(double *x, double *y)
{
    if (x) *x = posX_;
    if (y) *y = posY_;
}

void HasPosition::setPosition(double x, double y)
{
    setXPosition(x);
    setYPosition(y);
}


void HasPosition::setXPosition(double x)
{
    posX_ = x;
}


void HasPosition::setYPosition(double y)
{
    posY_ = y;
}
