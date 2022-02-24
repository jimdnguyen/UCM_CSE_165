#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

#include "Interface.h"
#include "Shader.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Texture.h"

#include <chrono>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

GLuint gWVPLocation;
GLuint gSampler;
GLuint texture;

const char *pSVSFileName = "shader/simpleshader.vs";
const char *pSFSFileName = "shader/simpleshader.fs";

const char *pTVSFileName = "shader/textureshader.vs";
const char *pTFSFileName = "shader/textureshader.fs";

//https://learnopengl.com/Getting-started/Textures
//https://learnopengl.com/Getting-started/Hello-Triangle
//https://learnopengl.com/Getting-started/Shaders

//cheese
GLfloat vertices[] = {
    // positions          // colors           // texture coords
    0.35f, 0.35f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
    0.35f, -0.35f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -0.35f, -0.35f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.35f, 0.35f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
};

//just rectangle
// GLfloat vertices[] = {
//     0.5f, 0.5f, 0.0f,   // top right
//     0.5f, -0.5f, 0.0f,  // bottom right
//     -0.5f, -0.5f, 0.0f, // bottom left
//     -0.5f, 0.5f, 0.0f   // top left
// };

GLuint indices[] = {
    // note that we start from 0!
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

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
    static Interface *interface = NULL;

    if (interface == NULL)
    {
        glfwInit();

        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);

        //no black box flickering in the corner with these 2 lines
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        _window = glfwCreateWindow(1280, 720, "Zomboid", NULL, NULL);
        glfwMakeContextCurrent(_window);
        glewInit();

        glViewport(0, 0, 1280, 720);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        _shader = new Shader(pTVSFileName, pTFSFileName);

        _vao = new VAO();
        _vbo = new VBO(vertices, sizeof(vertices), GL_STATIC_DRAW);
        _ebo = new EBO(indices, sizeof(indices), GL_STATIC_DRAW);

        // next 3 lines for cheese image
        _vao->AttribPointer(*_vbo, 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
        _vao->AttribPointer(*_vbo, 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
        _vao->AttribPointer(*_vbo, 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));

        //this line is just for rectangle
        //_vao->AttribPointer(*_vbo, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

        _vao->unbind();
        _vbo->unbind();
        _ebo->unbind();

        const char *titleCheeseLoc = "texture/titleCheese.png";
        _tex = new Texture(titleCheeseLoc, GL_TEXTURE_2D, GL_TEXTURE0);

        // glMatrixMode(GL_PROJECTION);
        // glLoadIdentity();
        // glOrtho(0, 1280, 720, 0, -10, 10);
        // glMatrixMode(GL_MODELVIEW);
        // glLoadIdentity();
    }
}

void Interface::run(Game *game)
{
    while (_running)
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        _running = !glfwWindowShouldClose(_window);

        glfwSetKeyCallback(_window, keyboard);
        glfwSetMouseButtonCallback(_window, mouse);

        render(game);
        //glfwSwapBuffers(_window);
        glfwPollEvents();

        static auto stime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> selapsed = std::chrono::high_resolution_clock::now() - stime;

        if (selapsed.count() > 1. / _framerate)
        {
            game->step();
            stime = std::chrono::high_resolution_clock::now();
        }
    }
    _vao->Delete();
    _vbo->Delete();
    _ebo->Delete();
    _tex->Delete();
    _shader->Delete();
}

void Interface::render(Game *game)
{
    glClear(GL_COLOR_BUFFER_BIT);
    game->render();
    if (game->getGameState() == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        _shader->use();
        _tex->bind();
        _vao->bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
    }
    else
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
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

// unsigned int indices[] = {
//     // note that we start from 0!
//     0, 1, 3, // first triangle
//     1, 2, 3  // second triangle
// };

// //ONLY PICK ONE PAIR OF VERTEXSHADERSOURCE AND FRAGMENTSHADERSOURCE

// ///* This block of code is for Cheese Icon, implementTexture
// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "layout (location = 1) in vec3 aColor;\n"
//                                  "layout (location = 2) in vec2 aTexCoord;\n"
//                                  "out vec3 ourColor;\n"
//                                  "out vec2 TexCoord;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "    gl_Position = vec4(aPos.x, aPos.y+0.5, aPos.z, 1.0);\n"
//                                  "    ourColor = aColor;\n"
//                                  "    TexCoord = aTexCoord;\n"
//                                  "}\0";

// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "in vec3 ourColor;\n"
//                                    "in vec2 TexCoord;\n"
//                                    "uniform sampler2D ourTexture;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = texture(ourTexture, TexCoord);\n"
//                                    "}\0";

// // This is for cheese
// float vertices[] = {
//     // positions          // colors           // texture coords
//     0.35f, 0.35f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
//     0.35f, -0.35f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
//     -0.35f, -0.35f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
//     -0.35f, 0.35f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
// };
// //*/

// /* This block of code is for Enter Icon, implementTexture
// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "layout (location = 1) in vec3 aColor;\n"
//                                  "layout (location = 2) in vec2 aTexCoord;\n"
//                                  "out vec3 ourColor;\n"
//                                  "out vec2 TexCoord;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "    gl_Position = vec4(aPos.x-0.025, aPos.y-0.75, aPos.z, 1.0);\n"
//                                  "    ourColor = aColor;\n"
//                                  "    TexCoord = aTexCoord;\n"
//                                  "}\0";

// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "in vec3 ourColor;\n"
//                                    "in vec2 TexCoord;\n"
//                                    "uniform sampler2D ourTexture;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = texture(ourTexture, TexCoord);\n"
//                                    "}\0";

// // This is for enter
// float vertices[] = {
//     // positions          // colors           // texture coords
//     0.9f, 0.3f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
//     0.9f, -0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
//     -0.9f, -0.3f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
//     -0.9f, 0.3f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
// };
// */

// /* This block of code is Cheese Location, implementShader
// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   gl_Position = vec4(aPos.x, aPos.y+0.5, aPos.z, 1.0);\n"
//                                  "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                    "}\n\0";
// //this one is for cheese size
// float vertices[] = {
//     0.35f, 0.35f, 0.0f,   // top right
//     0.35f, -0.35f, 0.0f,  // bottom right
//     -0.35f, -0.35f, 0.0f, // bottom left
//     -0.35f, 0.35f, 0.0f   // top left
// };
// */

// /* This block of code is for Enter Location,, implementShader
// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   gl_Position = vec4(aPos.x, aPos.y-0.75, aPos.z, 1.0);\n"
//                                  "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                    "}\n\0";
// // //this one is for enter size
// float vertices[] = {
//     0.9f, 0.2f, 0.0f,   // top right
//     0.9f, -0.2f, 0.0f,  // bottom right
//     -0.9f, -0.2f, 0.0f, // bottom left
//     -0.9f, 0.2f, 0.0f   // top left
// };
// */

// GLuint VBO, VAO, EBO, texture;
// GLuint shaderProgramSetup()
// {
//     GLuint vertexShader;
//     vertexShader = glCreateShader(GL_VERTEX_SHADER);

//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     glCompileShader(vertexShader);

//     GLint Result = GL_FALSE;
//     int InfoLogLength;
//     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &Result);
//     glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
//     if (InfoLogLength > 0)
//     {
//         std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
//         glGetShaderInfoLog(vertexShader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
//         printf("%s\n", &VertexShaderErrorMessage[0]);
//     }

//     GLuint fragmentShader;
//     fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     glCompileShader(fragmentShader);

//     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &Result);
//     glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
//     if (InfoLogLength > 0)
//     {
//         std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
//         glGetShaderInfoLog(fragmentShader, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
//         printf("%s\n", &FragmentShaderErrorMessage[0]);
//     }

//     GLuint shaderProgram = glCreateProgram();

//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);

//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Result);
//     glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
//     if (InfoLogLength > 0)
//     {
//         std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
//         glGetProgramInfoLog(shaderProgram, InfoLogLength, NULL, &ProgramErrorMessage[0]);
//         printf("%s\n", &ProgramErrorMessage[0]);
//     }

//     glDetachShader(shaderProgram, vertexShader);
//     glDetachShader(shaderProgram, fragmentShader);

//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     return shaderProgram;
// }

// void BuffObj(bool texture)
// {
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
//     glGenBuffers(1, &EBO);

//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//     if (texture)
//     {
//         // position attribute
//         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
//         glEnableVertexAttribArray(0);
//         // color attribute
//         glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
//         glEnableVertexAttribArray(1);
//         // texture coord attribute
//         glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
//         glEnableVertexAttribArray(2);
//     }
//     else
//     {
//         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
//         glEnableVertexAttribArray(0);
//     }

//     glBindVertexArray(0);
//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
// }

// void grabTexture()
// {
//     int width, height, nrChannels;
//     //pick which image u want to load
//     unsigned char *image = SOIL_load_image("texture/titleCheese.png", &width, &height, &nrChannels, SOIL_LOAD_RGBA);
//     //unsigned char *image = SOIL_load_image("texture/pressEnter.png", &width, &height, &nrChannels, SOIL_LOAD_RGBA);

//     glGenTextures(1, &texture);
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//     //glGenerateMipmap(GL_TEXTURE_2D);
//     glUniform1i(glGetUniformLocation(shaderProgramSetup(), "cheese"), 0);
//     SOIL_free_image_data(image);
//     //glBindTexture(GL_TEXTURE_2D, 0);
// }

// void implementShader()
// {
//     //shaderProgramSetup();
//     // BuffObj(false);
//     glUseProgram(shaderProgramSetup());
//     glBindVertexArray(VAO);
//     glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
// }

// void implementTexture()
// {
//     //BuffObj(true);
//     GLuint shaderProgram = shaderProgramSetup();
//     glUseProgram(shaderProgram);
//     glBindTexture(GL_TEXTURE_2D, texture);
//     glBindVertexArray(VAO);
//     glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//     //

//     //https://learnopengl.com/Getting-started/Textures
//     //https://learnopengl.com/Getting-started/Hello-Triangle
// }