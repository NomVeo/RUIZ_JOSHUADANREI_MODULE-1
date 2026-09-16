#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.0f);

    const float PI = 3.14159265f;
    const float radius = 0.6f;
    const int segments = 8;

    glBegin(GL_TRIANGLE_FAN);

        // Shared middle
        glVertex2f(0.0f, 0.0f);

        for (int i = 0; i <= segments; i++) {

            float angle =
                (float)i / segments * PI;

            float x = radius * cosf(angle);
            float y = radius * sinf(angle);

            glVertex2f(x, y);
        }

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q10");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}