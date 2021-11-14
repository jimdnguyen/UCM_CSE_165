#ifndef Game_h
#define Game_h

#include "Entity.h"
#include "Projectile.h"
#include "Zombie.h"
#include <GLFW/glfw3.h>
#include <vector>

class Game
{
private:
    GLFWwindow *_window;
    Entity *player = NULL;
    std::vector<Zombie *> enemies;
    std::vector<Projectile *> projectiles;
    int _gamestate = 0; // should start at 0 for Title screen

public:
    Game();
    ~Game();
    void setup();
    void render();
    void reset();
    void step();
    int getGameState()
    {
        return _gamestate;
    }

    void renderInGame();
    void renderTitle();
    void renderPaused();

    void stepInGame(int *);
    void stepTitle(int *);
    void stepPaused(int *);

    void addProjectile(int, double);
    void addEnemy();
    // static void keyboard(GLFWwindow *, int, int, int, int);
    // static void mouse(GLFWwindow *, int, int, int);
    // static void mouse_pos(GLFWwindow *, double, double);
};

#endif // Game_h