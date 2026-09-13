#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

void DrawSun() {

    glColor3f(1.0f, 1.0f, 0.0f);
    const int segments = 40;
    const float radius = 0.15f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.6f, 0.6f);
        for (int i = 0; i <= segments; i++) {
            float angle =
                (float)i / segments * 2.0f * 3.14159265f;
            float x = 0.6f + radius * cosf(angle);
            float y = 0.6f + radius * sinf(angle);
            glVertex2f(x, y);
        }

    glEnd();
}

void display() {

    glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Ground
    glColor3f(0.0f, 0.6f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f(1.0f, -0.4f);
        glVertex2f(1.0f, -1.0f);
    glEnd();

    // Sun
    DrawSun();
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("RUIZ_Q14 - Simple Landscape");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}