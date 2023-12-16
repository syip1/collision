#ifndef ENGINE_NAIVE_H
#define ENGINE_NAIVE_H

// Order matters!
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <vector>
#include <iostream>
#include "ball.h"
#include "wall.h"
#include "shader.h"


class engine_naive {
public:
    engine_naive(int width = 800, int height = 600);
    void add_ball(Ball b);
    void add_wall(Wall w);
    void processInput();
    void draw();
    double step();
    friend std::ostream& operator<<(std::ostream& os, const engine_naive& c);
private:
    std::vector<Ball> balls;
    std::vector<Wall> walls;
    int width;
    int height;
    double time = 0;
    GLFWwindow* window;
    bool move = false;
};

#endif