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

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(4.0f);

    // First line - dashed
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.8f, 0.4f);
        glVertex2f(0.8f, 0.4f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);

    // Second line - dotted
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xAAAA);

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.8f, -0.4f);
        glVertex2f(0.8f, -0.4f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 500);
    glutCreateWindow("RUIZ_Q14");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}