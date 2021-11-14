#include "glad\glad.h"
#include "Game.h"
#include "Interface.h"
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <math.h>
#include <iostream>
#include <vector>

unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

//ONLY PICK ONE PAIR OF VERTEXSHADERSOURCE AND FRAGMENTSHADERSOURCE

///* This block of code is for Cheese Icon, implementTexture
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "layout (location = 1) in vec3 aColor;\n"
                                 "layout (location = 2) in vec2 aTexCoord;\n"
                                 "out vec3 ourColor;\n"
                                 "out vec2 TexCoord;\n"
                                 "void main()\n"
                                 "{\n"
                                 "    gl_Position = vec4(aPos.x, aPos.y+0.5, aPos.z, 1.0);\n"
                                 "    ourColor = aColor;\n"
                                 "    TexCoord = aTexCoord;\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "in vec3 ourColor;\n"
                                   "in vec2 TexCoord;\n"
                                   "uniform sampler2D ourTexture;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = texture(ourTexture, TexCoord);\n"
                                   "}\0";

///* This is for cheese
float vertices[] = {
    // positions          // colors           // texture coords
    0.35f, 0.35f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
    0.35f, -0.35f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -0.35f, -0.35f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.35f, 0.35f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
};
//*/
//*/

/* This block of code is for Enter Icon, implementTexture
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "layout (location = 1) in vec3 aColor;\n"
                                 "layout (location = 2) in vec2 aTexCoord;\n"
                                 "out vec3 ourColor;\n"
                                 "out vec2 TexCoord;\n"
                                 "void main()\n"
                                 "{\n"
                                 "    gl_Position = vec4(aPos.x-0.025, aPos.y-0.75, aPos.z, 1.0);\n"
                                 "    ourColor = aColor;\n"
                                 "    TexCoord = aTexCoord;\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "in vec3 ourColor;\n"
                                   "in vec2 TexCoord;\n"
                                   "uniform sampler2D ourTexture;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = texture(ourTexture, TexCoord);\n"
                                   "}\0";

///* This is for enter
// float vertices[] = {
//     // positions          // colors           // texture coords
//     0.9f, 0.3f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
//     0.9f, -0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
//     -0.9f, -0.3f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
//     -0.9f, 0.3f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
// };
//*/

///* This block of code is Cheese Location, implementShader
// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   gl_Position = vec4(aPos.x, aPos.y+0.5, aPos.z, 1.0);\n"
//                                  "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                    "}\n\0";
//this one is for cheese size
// float vertices[] = {
//     0.35f, 0.35f, 0.0f,   // top right
//     0.35f, -0.35f, 0.0f,  // bottom right
//     -0.35f, -0.35f, 0.0f, // bottom left
//     -0.35f, 0.35f, 0.0f   // top left
// };
//*/

///* This block of code is for Enter Location,, implementShader
// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   gl_Position = vec4(aPos.x, aPos.y-0.75, aPos.z, 1.0);\n"
//                                  "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//                                    "out vec4 FragColor;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                    "}\n\0";
// //this one is for enter size
// float vertices[] = {
//     0.9f, 0.2f, 0.0f,   // top right
//     0.9f, -0.2f, 0.0f,  // bottom right
//     -0.9f, -0.2f, 0.0f, // bottom left
//     -0.9f, 0.2f, 0.0f   // top left
// };
//*/

GLuint shaderProgramSetup()
{
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

GLuint VBO, VAO, EBO;

void BuffObj(bool texture)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    if (texture)
    {
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // texture coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }
    else
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void implementShader()
{
    GLuint shaderProgram = shaderProgramSetup();

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void implementTexture()
{
    int width, height, nrChannels;
    //pick which image u want to load
    unsigned char *image = SOIL_load_image("texture/titleCheese.png", &width, &height, &nrChannels, 0);
    //unsigned char *image = SOIL_load_image("texture/pressEnter.png", &width, &height, &nrChannels, SOIL_LOAD_RGBA);

    GLuint texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint shaderProgram = shaderProgramSetup();

    glUseProgram(shaderProgram);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    //

    //https://learnopengl.com/Getting-started/Textures
    //https://learnopengl.com/Getting-started/Hello-Triangle
}

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
        exit(0);
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
        inputState[GLFW_KEY_ESCAPE] = 0;
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
        _gamestate = 0;
        inputState[GLFW_KEY_ESCAPE] = 0;
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