#include <GL/glut.h>
#include <SOIL/SOIL.h>

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("SAMPLE TEST");
    glutDisplayFunc(displayMe);
    glutMainLoop();

    int wi, hi, c;

    unsigned char *test = SOIL_load_image("img.png", &wi, &hi, &c, SOIL_LOAD_AUTO);

    return 0;
}
/*
Links Used to Help Run OpenGL/SOIL
https://medium.com/swlh/setting-opengl-for-windows-d0b45062caf
This is so much easier to use than VSCode
https://packages.msys2.org/package/mingw-w64-x86_64-soil?repo=mingw64
*/
