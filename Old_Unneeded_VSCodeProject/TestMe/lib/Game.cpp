#include "Game.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <math.h>
#include <iostream>
#include <vector>

Game::Game()
{
}

Game::~Game()
{
}

void Game::setup()
{
}

void Game::render()
{
    switch (_gamestate)
    {
    case 0: // Title Screen
        renderInGame();
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

void Game::renderInGame()
{
    for (auto e : projectiles)
        e->render();
    player->render();
    for (auto e : enemies)
        e->render();
}
