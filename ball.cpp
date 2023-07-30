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

void Ball::update_pos(double new_time)
{
    pos = pos + vel * (new_time - time);
    time = new_time;
}

coord_2d Ball::get_vel() const
{
    return vel;
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
            // No collision
            return DBL_MAX;
        }
    }
    else {
        // No collision
        return DBL_MAX;
    }
}

void collide(Ball &x, Ball &y)
{
    // Assume coef of restituion = 1 and mass equal
    coord_2d pd = x.pos - y.pos;
    // Keep velocity parallel, transfer velocity perpendicular
    coord_2d xvpar = pd * (dot(x.vel, pd) / dot(pd, pd));
    coord_2d yvpar = pd * (dot(y.vel, pd) / dot(pd, pd));
    coord_2d xvperp = x.vel - xvpar;
    coord_2d yvperp = y.vel - yvpar;
    x.vel = xvpar + yvperp;
    y.vel = yvpar + xvperp;
}

std::ostream &operator<<(std::ostream &os, const Ball &c)
{
    os << "Position: " << c.pos << ", Velocity: " << c.vel << "Radius: " << c.r << std::endl;
    return os;
}
