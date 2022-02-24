#ifndef EBO_h
#define EBO_h

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class EBO
{
public:
    GLuint id;

    EBO(GLuint *indices, GLsizeiptr size, GLenum usage);

    void bind();

    void unbind();

    void Delete();
};

#endif // EBO_h