#ifndef VAO_h
#define VAO_h

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VBO.h"

class VAO
{
public:
    GLuint id;

    VAO();

    void AttribPointer(VBO &VBO, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizeiptr stride, const void *pointer);

    void bind();

    void unbind();

    void Delete();
};

#endif // VAO_h
