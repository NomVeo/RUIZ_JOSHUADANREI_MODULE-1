#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

//Speed of rotation 
float angle = 0.0001f;

void DrawClockFace() {

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);

    // Circle outline
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 60; i++) {

        float a =
            (float)i / 60.0f * 2.0f * 3.14159265f;

        glVertex2f(0.8f * cosf(a), 0.8f * sinf(a));
    }
    glEnd();

    // 12 tick marks
    glLineWidth(4.0f);

    glBegin(GL_LINES);

    for (int i = 0; i < 12; i++) {

        float a =
            (float)i / 12.0f * 2.0f * 3.14159265f;
        float outerX = 0.75f * cosf(a);
        float outerY = 0.75f * sinf(a);

        float innerX = 0.65f * cosf(a);
        float innerY = 0.65f * sinf(a);

        glVertex2f(innerX, innerY);
        glVertex2f(outerX, outerY);
    }

    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    DrawClockFace();

    // Clock hand
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(5.0f);

    glBegin(GL_LINES);

        glVertex2f(0.0f, 0.0f);

        glVertex2f(
            0.55f * cosf(angle),
            0.55f * sinf(angle)
        );

    glEnd();

    glFlush();
}

void idle() {
    angle += 0.001f;
    if (angle > 2.0f * 3.14159265f)
        angle -= 2.0f * 3.14159265f;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q18 - Rotating Clock Hand");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
