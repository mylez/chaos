#include "HasPosition.h"

void HasPosition::queryPosition(double *x, double *y)
{
    *x = this->positionX;
    *y = this->positionY;
}

void HasPosition::setPosition(double x, double y)
{
    this->positionX = x;
    this->positionY = y;
}