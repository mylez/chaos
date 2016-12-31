#ifndef CHAOS_HASPOSITION_H
#define CHAOS_HASPOSITION_H

class HasPosition
{
public:
    void setPosition(double x, double y);
    void setXPosition(double x);
    void setYPosition(double y);
    void queryPosition(double *x, double *y);
private:
    double posX_ = 0, posY_ = 0;
};


#endif //CHAOS_HASPOSITION_H
