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

    glLineWidth(12.0f);

    glBegin(GL_LINES);

        // Yellow
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.8f, 0.0f);

        // Purple
        glColor3f(0.5f, 0.0f, 0.8f);
        glVertex2f(0.8f, 0.0f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 400);
    glutCreateWindow("RUIZ_Q13");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}