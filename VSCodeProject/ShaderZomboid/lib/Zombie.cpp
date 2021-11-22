#include "Zombie.h"
#include <GLFW/glfw3.h>
#include <math.h>

Zombie::Zombie(int health, int x, int y, double speed) : Entity(health, x, y, speed)
{
}

Zombie::~Zombie()
{
}

void Zombie::render()
{
    int x = getX();
    int y = getY();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(x + 0, y + 0);
    glVertex2f(x + 0, y + 10);
    glVertex2f(x + 10, y + 10);
    glVertex2f(x + 10, y + 0);
    glEnd();
    glFlush();
}

void Zombie::step(int x, int y)
{
    double dirx = x - this->getX();
    double diry = y - this->getY();
    double len = sqrt(dirx * dirx + diry * diry);
    dirx /= len;
    diry /= len;
    this->setX(this->getX() + dirx * this->getSpeed());
    this->setY(this->getY() + diry * this->getSpeed());
}