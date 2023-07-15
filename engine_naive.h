#ifndef ENGINE_NAIVE_H
#define ENGINE_NAIVE_H
#include <vector>
#include "ball.h"


class engine_naive {
public:
    engine_naive();
    void step();
    void print_state();
private:
    std::vector<Ball> balls;
    double time = 0;
};

#endif