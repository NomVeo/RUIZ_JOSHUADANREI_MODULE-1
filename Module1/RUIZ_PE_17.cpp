#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

int ActiveLight = 0;

void DrawCircle(float x, float y, float radius, float r, float g, float b) {

    glColor3f(r, g, b);
    const int segments = 40;
    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(x, y);

        for (int i = 0; i <= segments; i++) {
            float angle =
                (float)i / segments * 2.0f * 3.14159265f;

            glVertex2f(
                x + radius * cosf(angle),
                y + radius * sinf(angle)
            );
        }

    glEnd();
}

void display() {

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Traffic light housing
    glColor3f(0.05f, 0.05f, 0.05f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, -0.8f);
        glVertex2f(-0.3f, 0.8f);
        glVertex2f(0.3f, 0.8f);
        glVertex2f(0.3f, -0.8f);
    glEnd();

    // Red Light
    if (ActiveLight == 0)
        DrawCircle(0.0f, 0.5f, 0.18f, 1.0f, 0.0f, 0.0f);
    else
        DrawCircle(0.0f, 0.5f, 0.18f, 0.3f, 0.0f, 0.0f);

    // Yellow Light
    if (ActiveLight == 1)
        DrawCircle(0.0f, 0.0f, 0.18f, 1.0f, 1.0f, 0.0f);
    else
        DrawCircle(0.0f, 0.0f, 0.18f, 0.3f, 0.3f, 0.0f);

    // Green Light
    if (ActiveLight == 2)
        DrawCircle(0.0f, -0.5f, 0.18f, 0.0f, 1.0f, 0.0f);
    else
        DrawCircle(0.0f, -0.5f, 0.18f, 0.0f, 0.3f, 0.0f);

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {

    if (key == 'n') {
        ActiveLight = (ActiveLight + 1) % 3;
        glutPostRedisplay();
    }
    if (key == 27) {
        exit(0);
    }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(400, 700);
    glutCreateWindow("RUIZ_Q17 - Traffic Light");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}