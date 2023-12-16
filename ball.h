#ifndef ball_h
#define ball_h
#include "coord2d.h"
#include "wall.h"
#include <vector>

class Ball {
public:
    Ball();
    Ball(coord_2d pos, coord_2d vel, double r);
    Ball(double pos_x, double pos_y, double vel_x, double vel_y, double r);
    void update_pos(double new_time);
    coord_2d get_vel() const;
    std::vector<float> draw() const;
    friend double collide_time(Ball& x, Ball& y);
    friend double collide_time(Ball& x, Wall& y);
    friend void collide(Ball& x, Ball& y);
    friend void collide(Ball& x, Wall& y);
    friend std::ostream& operator<<(std::ostream& os, const Ball& c);
private:
    coord_2d pos;
    coord_2d vel;
    double r;
    double time = 0;
    int nvertices = 17;
};



#endif