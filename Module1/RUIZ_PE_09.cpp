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

    const int rows = 4;
    const int cols = 4;

    float startX = -0.8f;
    float startY = -0.8f;
    float cellSize = 0.4f;

    // Draw the checkerboard pattern
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {

            if ((row + col) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f);
            else
                glColor3f(0.0f, 0.0f, 0.0f);

            float x = startX + col * cellSize;
            float y = startY + row * cellSize;

            glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x, y + cellSize);
            glVertex2f(x + cellSize, y + cellSize);
            glVertex2f(x + cellSize, y);
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q09 - 4x4 Checkerboard");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}