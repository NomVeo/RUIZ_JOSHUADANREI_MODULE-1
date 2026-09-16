#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3f, 0.8f, 0.4f);

    glBegin(GL_QUADS);
        glVertex2f(-0.7f, -0.4f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.7f, 0.4f);
        glVertex2f(0.5f, -0.5f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q7");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}