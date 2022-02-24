#ifndef Zombie_h
#define Zombie_h

#include "Entity.h"

class Zombie : public Entity
{
private:
    double dirx;
    double diry;
public:
    Zombie(int,int,int,double);
    virtual ~Zombie();

    void step(int, int);
    virtual void render();
};

#endif // Zombie_h