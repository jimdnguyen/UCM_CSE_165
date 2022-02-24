#include "Entity.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <iostream>

const char *pVSFileName = "shader/simpleshader.vs";
const char *pFSFileName = "shader/simpleshader.fs";

Entity::Entity()
{
    _shader = new Shader(pVSFileName, pFSFileName);
}

Entity::Entity(int health, int x, int y, double speed)
{
    this->health = health;
    this->x = x;
    this->y = y;

    this->speed = speed;
}

Entity::~Entity()
{
}

void Entity::render()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(this->x + 0, this->y + 0);
    glVertex2f(this->x + 0, this->y + 10);
    glVertex2f(this->x + 10, this->y + 10);
    glVertex2f(this->x + 10, this->y + 0);
    glEnd();
    glFlush();
}

double Entity::dist(Entity *b)
{
    double xpos = this->x - b->getX();
    double ypos = this->y - b->getY();
    return sqrt((xpos * xpos) + (ypos * ypos));
}