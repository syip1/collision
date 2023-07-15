#ifndef ball_h
#define ball_h
#include "coord2d.h"

class Ball {
public:
    Ball();
    Ball(coord_2d pos, coord_2d vel, double r);
    Ball(double pos_x, double pos_y, double vel_x, double vel_y, double r);
    friend void collide(Ball& x, Ball& y);
    friend std::ostream& operator<<(std::ostream& os, const Ball& c);
private:
    coord_2d pos;
    coord_2d vel;
    double r;
};



#endif