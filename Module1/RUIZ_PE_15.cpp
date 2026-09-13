#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

float SquareX = 0.0f;
float SquareY = 0.0f;

const float HalfSize = 0.1f;
const float Speed = 0.05f;

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.7f, 1.0f);

    glBegin(GL_POLYGON);
        glVertex2f(SquareX - HalfSize, SquareY - HalfSize);
        glVertex2f(SquareX - HalfSize, SquareY + HalfSize);
        glVertex2f(SquareX + HalfSize, SquareY + HalfSize);
        glVertex2f(SquareX + HalfSize, SquareY - HalfSize);
    glEnd();

    glFlush();
}

void specialKeys(int key, int x, int y) {

    if (key == GLUT_KEY_LEFT)
        SquareX -= Speed;
    if (key == GLUT_KEY_RIGHT)
        SquareX += Speed;
    if (key == GLUT_KEY_UP)
        SquareY += Speed;
    if (key == GLUT_KEY_DOWN)
        SquareY -= Speed;

    // Keep the entire square inside the window
    if (SquareX > 1.0f - HalfSize)
        SquareX = 1.0f - HalfSize;
    if (SquareX < -1.0f + HalfSize)
        SquareX = -1.0f + HalfSize;
    if (SquareY > 1.0f - HalfSize)
        SquareY = 1.0f - HalfSize;
    if (SquareY < -1.0f + HalfSize)
        SquareY = -1.0f + HalfSize;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q15 - Move Square");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}