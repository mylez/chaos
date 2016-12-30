#ifndef CHAOS_HASPOSITION_H
#define CHAOS_HASPOSITION_H

class HasPosition
{
public:
    void setPosition(double x, double y);
    void queryPosition(double *x, double *y);
private:
    double positionX = 0, positionY = 0;
};


#endif //CHAOS_HASPOSITION_H
