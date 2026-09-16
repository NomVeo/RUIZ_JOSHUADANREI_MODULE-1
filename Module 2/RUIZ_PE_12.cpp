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
    glColor3f(0.8f, 0.4f, 0.1f);

    glBegin(GL_QUAD_STRIP);

        // Quadrant 1
        glVertex2f(-0.8f, -0.7f);
        glVertex2f(-0.8f, -0.2f);

        // Quadrant 2
        glVertex2f(-0.3f, -0.7f);
        glVertex2f(-0.3f, 0.0f);

        // Quadrant 3
        glVertex2f(0.2f, -0.7f);
        glVertex2f(0.2f, 0.25f);

        // Quadrant 4
        glVertex2f(0.7f, -0.7f);
        glVertex2f(0.7f, 0.5f);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 600);
    glutCreateWindow("RUIZ_Q12");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}