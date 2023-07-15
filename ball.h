#ifndef ball_h
#define ball_h
#include "coord2d.h"

class Ball {
public:
    Ball(coord_2d pos, coord_2d vel, double r);
private:
    coord_2d pos;
    coord_2d vel;
    double r;
};

void collide(Ball& x, Ball& y);

#endif