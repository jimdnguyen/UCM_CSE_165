#ifndef Shader_h
#define Shader_h

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

class Shader
{
public:
    GLuint shaderProgram;

    Shader(const char *vertexFile, const char *fragmentCode);

    void use();

    ~Shader();
};

#endif
// shader.h