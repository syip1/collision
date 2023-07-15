#ifndef COORD2D_H
#define COORD2D_H

class coord_2d {
public:
    coord_2d(double x, double y);
    coord_2d operator+(coord_2d& other);
    coord_2d operator-(coord_2d& other);
    coord_2d operator*(double other);
private:
    double x;
    double y;
};

double dot(coord_2d x, coord_2d y);

#endif