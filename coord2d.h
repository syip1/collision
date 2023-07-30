#ifndef COORD2D_H
#define COORD2D_H
#include <iostream>

class coord_2d {
public:
    coord_2d();
    coord_2d(double x, double y);
    coord_2d operator+(coord_2d other);
    coord_2d operator-(coord_2d other);
    coord_2d operator*(double other);
    bool operator==(coord_2d other);
    friend double dot(coord_2d x1, coord_2d x2);
    friend std::ostream& operator<<(std::ostream& os, const coord_2d& c);
private:
    double x;
    double y;
};

#endif