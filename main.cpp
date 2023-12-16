// Order matters!
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <iostream>

//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}

int main() {
    //// Setup OpenGL
    //glfwInit();
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    //if (window == NULL)
    //{
    //    std::cout << "Failed to create GLFW window" << std::endl;
    //    glfwTerminate();
    //    return -1;
    //}
    //glfwMakeContextCurrent(window);

    //// GLAD check
    //if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    //{
    //    std::cout << "Failed to initialize GLAD" << std::endl;
    //    return -1;
    //}

    //glViewport(0, 0, 800, 600);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    ////---------------------------------------------------
    //// Rendering loop
    //while (!glfwWindowShouldClose(window))
    //{
    //    processInput(window);

    //    // rendering commands
    //    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //    glClear(GL_COLOR_BUFFER_BIT);
    //    // Check and call events and swap buffers
    //    glfwSwapBuffers(window);
    //    glfwPollEvents();
    //}

    /*run_tests_collision_time();
    run_tests_collision_velocity();
    run_tests_naive_engine();
    */

    // Clean up and terminate
    //glfwTerminate();
    return 0;
}