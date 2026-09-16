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
    glColor3f(0.6f, 0.2f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(0.6f, 0.35f);
        glVertex2f(0.6f, -0.35f);
        glVertex2f(0.0f, -0.7f);
        glVertex2f(-0.6f, -0.35f);
        glVertex2f(-0.6f, 0.35f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q8");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}