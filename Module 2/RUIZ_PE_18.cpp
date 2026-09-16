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
    glShadeModel(GL_FLAT);
    glBegin(GL_QUAD_STRIP);

        // Quad 1 - Red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.9f, -0.5f);
        glVertex2f(-0.9f, 0.0f);

        // Quadrant 2 - Blue
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.55f, -0.5f);
        glVertex2f(-0.55f, 0.1f);

        // Quadrant 3 - Red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.2f, -0.5f);
        glVertex2f(-0.2f, 0.2f);

        // Quadrant 4 - Blue
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.15f, -0.5f);
        glVertex2f(0.15f, 0.3f);

        // Quadrant 5 - Red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.4f);

        // Quadrant 6 - Blue
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.85f, -0.5f);
        glVertex2f(0.85f, 0.5f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("RUIZ_Q18");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}