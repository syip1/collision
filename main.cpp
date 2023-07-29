#include "ball.h"
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

void run_tests_collision_time() {
    std::cout << "Running tests on Ball collide_time function..." << std::endl;
    test_collision_time_1();
    test_collision_time_2();
    test_collision_time_3();
    test_collision_time_4();
}


int main() {
    run_tests_collision_time();
    return 0;
}