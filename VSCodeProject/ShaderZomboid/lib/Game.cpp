#include <GL/glew.h>
#include "Game.h"
#include "Interface.h"
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <math.h>
#include <iostream>
#include <vector>

class InterfaceNotSetup
{
};

Game::Game()
{
}

Game::~Game()
{
}

void Game::setup()
{
    this->_window = glfwGetCurrentContext();
    if (_window == NULL)
        throw InterfaceNotSetup();
    int width, height;
    GLFWimage image;
    image.pixels = SOIL_load_image("texture/cursor3.png", &width, &height, 0, SOIL_LOAD_RGBA);
    image.width = width;
    image.height = height;
    GLFWcursor *_cursor = glfwCreateCursor(&image, 0, 0);
    glfwSetCursor(_window, _cursor);

    //glfwPollEvents();
    //glfwSwapBuffers(_window);

    reset();
}

void Game::render()
{
    switch (_gamestate)
    {
    case 0: // Title Screen
        renderTitle();
        break;
    case 1: // In Game
        renderInGame();
        break;
    case 2: // Paused
        break;
    default:
        break;
    }
}

void Game::renderTitle()
{

    //implementShader(); // if you want to see the shape
    //implementTexture(); //if you want to see the image
}

void Game::renderInGame()
{
    for (auto e : projectiles)
        e->render();
    player->render();
    for (auto e : enemies)
        e->render();
}

void Game::step()
{
    int *inputState = Interface::getInputState();
    if (_gamestate == 0)
        stepTitle(inputState);
    if (_gamestate == 1)
    {
        stepInGame(inputState);
    }
    if (_gamestate == 2)
        stepPaused(inputState);
}

void Game::reset()
{
    player = new Entity(1, 1280 / 2, 720 / 2, 10);
    for (int i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
    enemies.clear();
    for (int i = 0; i < projectiles.size(); i++)
    {
        delete projectiles[i];
    }
    projectiles.clear();
    enemies.push_back(new Zombie(50, 0, 0, 5));
    enemies.push_back(new Zombie(500, 600, 600, 5));
    enemies.push_back(new Zombie(50, 0, 600, 5));
}

void Game::stepTitle(int *inputState)
{
    if (inputState[GLFW_KEY_ESCAPE])
    {
        _gamestate = 2;
        reset();
    }
    if (inputState[GLFW_KEY_ENTER])
    {
        _gamestate = 1;
        reset();
    }
}

void Game::stepInGame(int *inputState)
{
    if (inputState[GLFW_KEY_ESCAPE])
    {
        _gamestate = 2;
        //inputState[GLFW_KEY_ESCAPE] = 0;
    }
    if (inputState[GLFW_KEY_W])
    {
        this->player->setY(this->player->getY() - this->player->getSpeed());
    }
    if (inputState[GLFW_KEY_A])
    {
        this->player->setX(this->player->getX() - this->player->getSpeed());
    }
    if (inputState[GLFW_KEY_S])
    {
        this->player->setY(this->player->getY() + this->player->getSpeed());
    }
    if (inputState[GLFW_KEY_D])
    {
        this->player->setX(this->player->getX() + this->player->getSpeed());
    }
    if (inputState[GLFW_MOUSE_BUTTON_1])
    {
        this->addProjectile(25, this->player->getSpeed()); // add modifiers to dmg
        inputState[GLFW_MOUSE_BUTTON_1] = 0;               // remove to enable full auto
    }
    for (auto e : projectiles)
        e->step();
    for (auto e : enemies)
        e->step(this->player->getX(), this->player->getY());

    for (int i = 0; i < projectiles.size(); i++)
    {
        for (int j = 0; j < enemies.size(); j++)
        {
            if (projectiles[i]->dist(enemies[j]) < 10)
            {
                enemies[j]->setHealth(enemies[j]->getHealth() - projectiles[i]->getHealth());
                delete projectiles[i];
                projectiles.erase(projectiles.begin() + i);
                i = (i > 0) ? i - 1 : i;
                break;
            }
        }
    }
    // Remove dead zombies
    for (int j = 0; j < enemies.size(); j++)
    {
        if (enemies[j]->getHealth() <= 0)
        {
            delete enemies[j];
            enemies.erase(enemies.begin() + j);
            j = (j > 0) ? j - 1 : j;
        }
    }
    // Remove lost projectiles
    for (int i = 0; i < projectiles.size(); i++)
    {
        if (projectiles[i]->dist(player) > 500) // limits attack range
        {
            delete projectiles[i];
            projectiles.erase(projectiles.begin() + i);
            i = (i > 0) ? i - 1 : i;
        }
    }
    // Game Over
    for (int j = 0; j < enemies.size(); j++)
    {
        if (player->dist(enemies[j]) < 10)
        {
            reset();
        }
    }
}

void Game::stepPaused(int *inputState)
{
    if (inputState[GLFW_KEY_ESCAPE])
    {
        _gamestate = 2;
        //inputState[GLFW_KEY_ESCAPE];
    }
    if (inputState[GLFW_KEY_ENTER])
    {
        _gamestate = 1;
    }
}

void Game::addProjectile(int health, double speed)
{
    double xpos, ypos;
    glfwGetCursorPos(_window, &xpos, &ypos);
    double dirx = xpos - player->getX();
    double diry = ypos - player->getY();
    double len = sqrt(dirx * dirx + diry * diry);
    dirx /= len;
    diry /= len;
    projectiles.push_back(new Projectile(health, player->getX(), player->getY(), speed, dirx, diry));
}