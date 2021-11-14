#include "glad\glad.h"
#include "Interface.h"

#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <chrono>

int *Interface::inputState = new int[350];

Interface::Interface()
{
    for (int i = 0; i < 350; i++)
        Interface::inputState[i] = 0;
}

Interface::~Interface()
{
    glfwTerminate();
}

void Interface::setup()
{

    glfwInit();

    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);

    _window = glfwCreateWindow(1280, 720, "Zomboid", NULL, NULL);
    glfwMakeContextCurrent(_window);
    //glewInit();

    glViewport(0, 0, 1280, 720);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(0, 1280, 720, 0, -10, 10);
    // glMatrixMode(GL_MODELVIEW);
    // // glLoadIdentity();
}

void Interface::run(Game *game)
{
    while (_running)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        _running = !glfwWindowShouldClose(_window);

        glfwSetKeyCallback(_window, keyboard);
        glfwSetMouseButtonCallback(_window, mouse);

        render(game);
        glfwPollEvents();

        static auto stime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> selapsed = std::chrono::high_resolution_clock::now() - stime;

        if (selapsed.count() > 1. / _framerate)
        {
            game->step();
            stime = std::chrono::high_resolution_clock::now();
        }
    }
}

void Interface::render(Game *game)
{
    glClear(GL_COLOR_BUFFER_BIT);
    game->render();
    glfwSwapBuffers(_window);
}

void Interface::keyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    switch (key)
    {
    case GLFW_KEY_W:
        Interface::inputState[GLFW_KEY_W] = action;
        break;
    case GLFW_KEY_A:
        Interface::inputState[GLFW_KEY_A] = action;
        break;
    case GLFW_KEY_S:
        Interface::inputState[GLFW_KEY_S] = action;
        break;
    case GLFW_KEY_D:
        Interface::inputState[GLFW_KEY_D] = action;
        break;
    default:
        Interface::inputState[key] = action;
        break;
    };
}

void Interface::mouse(GLFWwindow *window, int button, int action, int mods)
{

    switch (button)
    {
    case GLFW_MOUSE_BUTTON_1:
        // double xpos, ypos;
        // glfwGetCursorPos(window, &xpos, &ypos);
        // printf("Mouse Left x:%.2f y:%.2f\n", xpos, ypos);
        Interface::inputState[GLFW_MOUSE_BUTTON_1] = action;
        break;
    default:
        break;
    };
}