#ifndef wall_h
#define wall_h
#include "coord2d.h"

class Wall {
public:
    Wall(coord_2d pt1, coord_2d pt2);
    Wall(double x_1, double y_1, double x_2, double y_2);
    coord_2d get_pt1() const;
    coord_2d get_pt2() const;
private:
    coord_2d pt1;
    coord_2d pt2;
};

#endif