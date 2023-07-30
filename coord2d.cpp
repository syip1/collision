#include "coord2d.h"

coord_2d::coord_2d(): x(0), y(0)
{
}

coord_2d::coord_2d(double x, double y) : x(x), y(y)
{
}

coord_2d coord_2d::operator+(coord_2d other)
{
    return coord_2d(x+other.x, y+other.y);
}

coord_2d coord_2d::operator-(coord_2d other)
{
    return coord_2d(x-other.x, y-other.y);
}

coord_2d coord_2d::operator*(double other)
{
    return coord_2d(other*x, other*y);
}

bool coord_2d::operator==(coord_2d other)
{
    return (x==other.x) && (y=other.y);
}

double dot(coord_2d x1, coord_2d x2)
{
    return x1.x*x2.x + x1.y*x2.y;
}

std::ostream &operator<<(std::ostream &os, const coord_2d& c)
{
    os << "(" << c.x << "," << c.y << ")";
    return os;
}
