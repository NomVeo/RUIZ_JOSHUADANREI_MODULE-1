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
    glColor3ub(255, 140, 0);

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6f, -0.5f);
        glVertex2f(0.6f, -0.5f);
        glVertex2f(0.0f, 0.6f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q6");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}