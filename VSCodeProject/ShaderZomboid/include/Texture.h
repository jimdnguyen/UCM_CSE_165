#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

class Texture
{

public:
    GLuint id;
    GLenum type;

    Texture(const char *imageLocation, GLenum textureType, GLenum slot);

    void bind();

    void unbind();

    void Delete();
};
#endif