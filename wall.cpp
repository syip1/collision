#include "wall.h"

Wall::Wall(coord_2d pt1, coord_2d pt2): pt1(pt1), pt2(pt2)
{
}

Wall::Wall(double x_1, double y_1, double x_2, double y_2)
{
    pt1 = coord_2d(x_1,y_1);
    pt2 = coord_2d(x_2,y_2);
}

coord_2d Wall::get_pt1() const
{
    return pt1;
}

coord_2d Wall::get_pt2() const
{
    return pt2;
}
