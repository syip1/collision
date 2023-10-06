#include "engine_naive.h"
#include "ball.h"
#include <cfloat>

void engine_naive::add_ball(Ball b)
{
    balls.push_back(b);
}

void engine_naive::add_wall(Wall w)
{
    walls.push_back(w);
}

double engine_naive::step()
{
    // Find next ball-ball collision time
    double min_ball_collision_time = DBL_MAX;
    int ball1 = -1;
    int ball2 = -1;
    for (int i = 0; i < balls.size(); ++i) {
        for (int j = i+1; j < balls.size(); ++j) {
            double t = collide_time(balls[i], balls[j]);
            if (t < min_ball_collision_time) {
                min_ball_collision_time = t;
                ball1 = i;
                ball2 = j;
            }
        }
    }
    // Find next ball-wall collision time
    double min_wall_collision_time = DBL_MAX;
    int ball3 = -1;
    int wall1 = -1;
    for (int i = 0; i < balls.size(); ++i) {
        for (int j = i+1; j < walls.size(); ++j) {
            double t = collide_time(balls[i], walls[j]);
            if (t < min_wall_collision_time) {
                min_wall_collision_time = t;
                ball3 = i;
                wall1 = j;
            }
        }
    }
    if (min_ball_collision_time < min_wall_collision_time) {
        if ((ball1 != -1) && (ball2 != -1)) {
            time = time + min_ball_collision_time;
            // Update balls position to required time
            for (int i = 0; i < balls.size(); ++i) {
                balls[i].update_pos(time);
            }
            // Collide
            collide(balls[ball1], balls[ball2]);
            // Step forward small time so that we get the next collision
            time = time + 1e-6;
            for (int i = 0; i < balls.size(); ++i) {
                balls[i].update_pos(time);
            }
            return min_ball_collision_time;
        }
        else {
            std::cout << "No more collisions!" << std::endl;
            return -1;
        }
    }
    else {
        if ((ball3 != -1) && (wall1 != -1)) {
            time = time + min_wall_collision_time;
            // Update balls position to required time
            for (int i = 0; i < balls.size(); ++i) {
                balls[i].update_pos(time);
            }
            // Collide
            collide(balls[ball3], walls[wall1]);
            // Step forward small time so that we get the next collision
            time = time + 1e-6;
            for (int i = 0; i < balls.size(); ++i) {
                balls[i].update_pos(time);
            }
            return min_wall_collision_time;
        }
        else {
            std::cout << "No more collisions!" << std::endl;
            return -1;
        }
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
