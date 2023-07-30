#include "engine_naive.h"
#include "ball.h"
#include <cfloat>

void engine_naive::add_ball(Ball b)
{
    balls.push_back(b);
}

double engine_naive::step()
{
    // Find next collision time
    double min_collision_time = DBL_MAX;
    int ball1 = -1;
    int ball2 = -1;
    for (int i = 0; i < balls.size(); ++i) {
        for (int j = i+1; j < balls.size(); ++j) {
            double t = collide_time(balls[i], balls[j]);
            if (t < min_collision_time) {
                min_collision_time = t;
                ball1 = i;
                ball2 = j;
            }
        }
    }

    if ((ball1 != -1) && (ball2 != -1)) {
        time = min_collision_time + 1e-15; // So that next time we get the next collision
        // Update balls position to required time
        for (int i = 0; i < balls.size(); ++i) {
            balls[i].update_pos(time);
        }
        // Collide
        collide(balls[ball1], balls[ball2]);
        return min_collision_time;
    }
    else {
        std::cout << "No more collisions!" << std::endl;
        return -1;
    }
}

std::ostream &operator<<(std::ostream &os, const engine_naive &c)
{
    os << "Time: " << c.time << std::endl;
    for (const Ball& b: c.balls) {
        os << b;
    }
    return os;
}
