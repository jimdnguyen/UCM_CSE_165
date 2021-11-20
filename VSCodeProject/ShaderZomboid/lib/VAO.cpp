#include "VAO.h"

VAO::VAO()
{
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);
}

void VAO::AttribPointer(VBO &VBO, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizeiptr stride, const void *pointer)
{
    VBO.bind();
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
    VBO.unbind();
}

void VAO::bind()
{
    glBindVertexArray(id);
}

void VAO::unbind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &id);
}