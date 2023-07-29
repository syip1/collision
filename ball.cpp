#include "ball.h"
#include <iostream>
#include <cfloat>
#include <cmath>

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

double collide_time(Ball &x, Ball &y)
{
    coord_2d vd = x.vel - y.vel;
    coord_2d pd = x.pos - y.pos;
    double d = x.r + y.r;
    double discriminant = dot(vd,pd)*dot(vd,pd) - dot(vd,vd)*(dot(pd,pd)-d*d);
    if ((discriminant >= 0) && dot(vd,vd) > 0) {
        // Find min collision time
        if (-dot(vd,pd) - sqrt(discriminant) >= 0) {
            return (-dot(vd,pd) - sqrt(discriminant)) / dot(vd,vd);
        }
        else if (-dot(vd,pd) + sqrt(discriminant) >= 0) {
            return (-dot(vd,pd) + sqrt(discriminant)) / dot(vd,vd);
        }
        else {
            return DBL_MAX;
        }
    }
    else {
        // No collision
        return DBL_MAX;
    }
}

std::ostream &operator<<(std::ostream &os, const Ball &c)
{
    os << "Position: " << c.pos << ", Velocity: " << c.vel << "Radius: " << c.r << std::endl;
    return os;
}
