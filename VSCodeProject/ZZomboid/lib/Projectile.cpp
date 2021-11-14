#include "Projectile.h"
#include <GLFW/glfw3.h>

Projectile::Projectile(int health, int x, int y, double speed, double dirx, double diry) : Entity(health, x, y, speed)
{
    this->dirx = dirx;
    this->diry = diry;
}

Projectile::~Projectile()
{
}

void Projectile::render()
{
    int x = getX();
    int y = getY();
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.75f, 0.0f);
    glVertex2f(x + 0, y + 0);
    glVertex2f(x + 0, y + 10);
    glVertex2f(x + 10, y + 10);
    glVertex2f(x + 10, y + 0);
    glEnd();
    glFlush();
}

void Projectile::step()
{
    this->setX(this->getX() + this->dirx * this->getSpeed());
    this->setY(this->getY() + this->diry * this->getSpeed());
}