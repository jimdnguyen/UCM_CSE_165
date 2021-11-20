#ifndef VBO_h
#define VBO_h

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VBO
{
public:
    GLuint id;

    VBO(GLfloat *vertices, GLsizeiptr size, GLenum usage);

    void bind();

    void unbind();

    void Delete();
};

#endif // VBO_h