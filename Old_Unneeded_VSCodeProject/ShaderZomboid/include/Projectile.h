#ifndef Projectile_h
#define Projectile_h

#include "Entity.h"

class Projectile : public Entity
{
private:
    double dirx;
    double diry;
public:
    Projectile(int,int,int,double,double,double);
    virtual ~Projectile();

    void step();
    virtual void render();
};

#endif // Projectile_h