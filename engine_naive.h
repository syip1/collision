#ifndef ENGINE_NAIVE_H
#define ENGINE_NAIVE_H
#include <vector>
#include <iostream>
#include "ball.h"


class engine_naive {
public:
    void add_ball(Ball b);
    double step();
    friend std::ostream& operator<<(std::ostream& os, const engine_naive& c);
private:
    std::vector<Ball> balls;
    double time = 0;
};

#endif