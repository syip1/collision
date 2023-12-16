#include "engine_naive.h"
#include "ball.h"
#include <cfloat>
#include <windows.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void engine_naive::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (!move && glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
        move = true;
    else if (move && glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_RELEASE)
        move = false;
}

engine_naive::engine_naive(int width, int height): width(width), height(height)
{
    window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        throw;
    }
    glfwMakeContextCurrent(window);

    // GLAD check
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        throw;
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void engine_naive::add_ball(Ball b)
{
    balls.push_back(b);
}

void engine_naive::add_wall(Wall w)
{
    walls.push_back(w);
}

void engine_naive::draw()
{
    // Shader stuff
    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n";
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Bind buffers
    std::vector<unsigned int> VBOs;
    std::vector<unsigned int> VAOs;
    std::vector<int> sizes;
    for (int i = 0; i < balls.size(); ++i) {
        std::vector<float> vertices = balls[i].draw();
        // Normalise coordinates
        for (int j = 0; j < vertices.size()/3; ++j) {
            vertices[3*j] /= width;
            vertices[3*j+1] /= height;
        }
        unsigned int VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO); 
        glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), &vertices[0], GL_STATIC_DRAW); //vertices.size()*
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        VBOs.push_back(VBO);
        VAOs.push_back(VAO);
        sizes.push_back(vertices.size()/3);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (!glfwWindowShouldClose(window) && !move) {
        processInput();
        // rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        for (int i = 0; i < balls.size(); ++i) {
            glUseProgram(shaderProgram);
            glBindVertexArray(VAOs[i]);
            glDrawArrays(GL_TRIANGLES, 0, sizes[i]);
        }
        // Check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    for (int i = 0; i < balls.size(); ++i) {
        glDeleteVertexArrays(1, &VAOs[i]);
    }
    if (move) {
        while (move) {
            glfwPollEvents();
            processInput(); // Wait till release
            auto a = glfwGetKey(window, GLFW_KEY_ENTER);
            Sleep(10);
        }
    }
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
            std::cout << "Collision time: " << min_ball_collision_time << std::endl;
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
            std::cout << "Collision time: " << min_wall_collision_time << std::endl;
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
