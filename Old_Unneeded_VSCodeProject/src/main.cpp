#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include "SOIL\SOIL.h"
#include <iostream>

int main()
{

    int wi, hi, c;

    unsigned char *test = SOIL_load_image("img.png", &wi, &hi, &c, SOIL_LOAD_AUTO);

    return 0;
}

/*
Links used to help me learn and understand OpenGL
https://medium.com/@vivekjha92/setup-opengl-with-vs-code-82852c653c43
https://www.glfw.org/download.html
https://learnopengl.com/Getting-started/Hello-Window
https://code.visualstudio.com/docs/cpp/config-mingw#_build-helloworldcpp
https://glad.dav1d.de/
//compile in cmd not wsl, https://stackoverflow.com/questions/66127102/command-cmd-not-found-but-there-are-16-similar-ones
*/

/*
Links used to help me learn and understand SOIL
https://askubuntu.com/questions/306703/compile-opengl-program-missing-gl-gl-h
https://github.com/paralin/soil
*/