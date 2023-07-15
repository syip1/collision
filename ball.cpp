#include "ball.h"
#include <iostream>

Ball::Ball(): pos(coord_2d(0,0)), vel(coord_2d(0,0)), r(0)
{
}

Ball::Ball(coord_2d pos, coord_2d vel, double r) : pos(pos), vel(vel), r(r)
{
}

Ball::Ball(double pos_x, double pos_y, double vel_x, double vel_y, double r): r(r)
{
    pos = coord_2d(pos_x, pos_y);
    vel = coord_2d(vel_x, vel_y);
}

void collide(Ball& x, Ball& y) {

}

std::ostream &operator<<(std::ostream &os, const Ball &c)
{
    os << "Position: " << c.pos << ", Velocity: " << c.vel << "Radius: " << c.r << std::endl;
    return os;
}
