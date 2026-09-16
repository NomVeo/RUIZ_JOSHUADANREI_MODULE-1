#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

void drawCircle() {

    const float PI = 3.14159265f;
    const float radius = 0.35f;
    const int segments = 40;

    glColor3f(1.0f, 0.5f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

        // Center
        glVertex2f(0.0f, 0.35f);

        for (int i = 0; i <= segments; i++) {
            float angle = (float)i / segments * 2.0f * PI;
            float x = radius * cosf(angle);
            float y = 0.35f + radius * sinf(angle);
            glVertex2f(x, y);
        }

    glEnd();
}

void drawBase() {

    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.7f);
        glVertex2f(0.15f, -0.7f);
        glVertex2f(0.15f, 0.1f);
        glVertex2f(-0.15f, 0.1f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle();
    drawBase();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q16");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}