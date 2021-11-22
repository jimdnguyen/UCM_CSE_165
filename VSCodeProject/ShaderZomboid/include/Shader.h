#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    // the program ID
    GLuint ShaderProgram;

    // constructor reads and builds the shader
    Shader(const char *vsFile, const char *fsFile);
    // use/activate the shader
    void use();

    void Delete();
};

#endif