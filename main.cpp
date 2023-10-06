#include "ball.h"
#include "wall.h"
#include "engine_naive.h"
#include <iostream>
#include <cassert>
#include <cfloat>
#include <cmath>

void test_collision_time_1() {
    Ball b1(0,0,0,1,1);
    Ball b2(0,5,0,-1,1);
    assert(collide_time(b1,b2) == 1.5);
    std::cout << "Test: Collision Time 1 passed!" << std::endl;
}

void test_collision_time_2() {
    Ball b1(0,0,0,1,1);
    Ball b2(0,-5,0,-1,1);
    assert(collide_time(b1,b2) == DBL_MAX);
    std::cout << "Test: Collision Time 2 passed!" << std::endl;
}

void test_collision_time_3() {
    Ball b1(0,0,0,1,1);
    Ball b2(2,-5,0,1,1);
    assert(collide_time(b1,b2) == DBL_MAX);
    std::cout << "Test: Collision Time 3 passed!" << std::endl;
}

void test_collision_time_4() {
    Ball b1(0,0,0,1,1);
    Ball b2(-5,5,1,0,2);
    assert(collide_time(b1,b2) == 5-sqrt(18)/2);
    std::cout << "Test: Collision Time 4 passed!" << std::endl;
}

void test_collision_time_5() {
    Ball b1(0,0,0,1,1);
    Wall w1(-2,2,2,2);
    assert(collide_time(b1,w1) == 1);
    std::cout << "Test: Collision Time 5 passed!" << std::endl;
}

void test_collision_velocity_1() {
    Ball b1(0,0,0,1,1);
    Ball b2(0,2,0,-1,1);
    collide(b1,b2);
    assert(b1.get_vel() == coord_2d(0,-1));
    assert(b2.get_vel() == coord_2d(0,1));
    std::cout << "Test: Collision Velocity 1 passed!" << std::endl;
}

void test_collision_velocity_2() {
    Ball b1(0,0,0,1,1);
    Ball b2(3,0,0,-1,2);
    collide(b1,b2);
    assert(b1.get_vel() == coord_2d(0,1));
    assert(b2.get_vel() == coord_2d(0,-1));
    std::cout << "Test: Collision Velocity 2 passed!" << std::endl;
}

void test_collision_velocity_3() {
    Ball b1(0,0,0,1,1);
    Ball b2(0,2,0,-1,1);
    collide(b1,b2);
    assert(b1.get_vel() == coord_2d(0,-1));
    assert(b2.get_vel() == coord_2d(0,1));
    std::cout << "Test: Collision Velocity 3 passed!" << std::endl;
}

void test_collision_velocity_4() {
    Ball b1(1,0,1,1,1);
    Wall w1(0,2,0,-2);
    collide(b1,w1);
    assert(b1.get_vel() == coord_2d(-1,1));
    std::cout << "Test: Collision Velocity 4 passed!" << std::endl;
}

void test_naive_engine_1() {
    engine_naive e;
    e.add_ball(Ball(0,0,0,1,1));
    e.add_ball(Ball(5,0,-1,1,1));
    e.add_ball(Ball(0,10,0,-1,2));
    std::cout << e.step() << std::endl;
    std::cout << e.step() << std::endl;
    std::cout << e.step() << std::endl;
}

void test_naive_engine_2() {
    engine_naive e;
    e.add_ball(Ball(0,0,0,1,1));
    e.add_ball(Ball(5,0,-1,1,1));
    e.add_wall(Wall(-10,-10,-10,10));
    e.add_wall(Wall(-10,10,10,10));
    e.add_wall(Wall(10,10,10,-10));
    e.add_wall(Wall(10,-10,-10,-10));
    std::cout << e.step() << std::endl;
    std::cout << e.step() << std::endl;
    std::cout << e.step() << std::endl;
}

void run_tests_collision_time() {
    std::cout << "Running tests on Ball collide_time function..." << std::endl;
    test_collision_time_1();
    test_collision_time_2();
    test_collision_time_3();
    test_collision_time_4();
    test_collision_time_5();
}

void run_tests_collision_velocity() {
    std::cout << "Running tests on Ball collide function..." << std::endl;
    test_collision_velocity_1();
    test_collision_velocity_2();
    test_collision_velocity_3();
    test_collision_velocity_4();
}

void run_tests_naive_engine() {
    std::cout << "Running tests on engine_naive..." << std::endl;
    test_naive_engine_1();
    test_naive_engine_2();
}


int main() {
    run_tests_collision_time();
    run_tests_collision_velocity();
    run_tests_naive_engine();
    return 0;
}