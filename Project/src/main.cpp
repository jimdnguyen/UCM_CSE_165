#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

/*
Links used to help me learn and understand OpenGL
https://medium.com/@vivekjha92/setup-opengl-with-vs-code-82852c653c43
https://www.glfw.org/download.html
https://learnopengl.com/Getting-started/Hello-Window
https://code.visualstudio.com/docs/cpp/config-mingw#_build-helloworldcpp
https://glad.dav1d.de/
//compile in cmd not wsl, https://stackoverflow.com/questions/66127102/command-cmd-not-found-but-there-are-16-similar-ones
*/

/*
Links used to help me learn and understand SOIL
*/