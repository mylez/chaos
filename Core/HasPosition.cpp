#include "HasPosition.h"

void HasPosition::queryPosition(double *x, double *y)
{
    if (x) *x = this->positionX;
    if (y) *y = this->positionY;
}

void HasPosition::setPosition(double x, double y)
{
    this->positionX = x;
    this->positionY = y;
}
