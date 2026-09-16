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
    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.7f, -0.4f);
        glVertex2f(-0.7f, 0.4f);
        glVertex2f(0.7f, -0.4f);
        glVertex2f(0.7f, 0.4f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q9");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}