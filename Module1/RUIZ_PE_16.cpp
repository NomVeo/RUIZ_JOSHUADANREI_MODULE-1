#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

float BallX = 0.0f;
float BallY = 0.0f;

float dx = 0.0002f;
float dy = 0.0002f;

const float radius = 0.1f;

void drawBall() {
    glColor3f(1.0f, 0.3f, 0.0f);
    const int segments = 40;
    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(BallX, BallY);

        for (int i = 0; i <= segments; i++) {

            float angle =
                (float)i / segments * 2.0f * 3.14159265f;
            float x = BallX + radius * cosf(angle);
            float y = BallY + radius * sinf(angle);

            glVertex2f(x, y);
        }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBall();
    glFlush();
}

void idle() {

    BallX += dx;
    BallY += dy;

    if (BallX + radius >= 1.0f ||
        BallX - radius <= -1.0f) {
        dx = -dx;
    }

    if (BallY + radius >= 1.0f ||
        BallY - radius <= -1.0f) {
        dy = -dy;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q16 - Bouncing Ball");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
