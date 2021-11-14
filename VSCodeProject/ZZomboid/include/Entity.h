#ifndef Entity_h
#define Entity_h

class Entity
{
private:
    int health;
    double x;
    double y;

    double speed;

public:
    Entity();
    Entity(int, int, int, double);
    virtual ~Entity();
    virtual void render();

    double dist(Entity *);
    double getX() { return x; }
    double getY() { return y; }
    void setX(int i) { this->x = i; }
    void setY(int i) { this->y = i; }

    int getHealth() { return health; }
    void setHealth(int i) { this->health = i; }

    double getSpeed() { return speed; }
};

#endif // Entity_h