#ifndef Interface_h
#define Interface_h
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "Shader.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Texture.h"

#include <iostream>

class Interface
{
private:
    bool _running = true;
    double _framerate = 30.0; // frames per second
    GLFWwindow *_window;
    Game *_game;
    Shader *_shader;
    VBO *_vbo;
    VAO *_vao;
    EBO *_ebo;
    Texture *_tex;
    static int *inputState;

public:
    Interface();
    ~Interface();

    void setup();
    void run(Game *);
    void render(Game *);
    static int *getInputState() { return inputState; }
    static void keyboard(GLFWwindow *, int, int, int, int);
    static void mouse(GLFWwindow *, int, int, int);
};

#endif // Interface_h
