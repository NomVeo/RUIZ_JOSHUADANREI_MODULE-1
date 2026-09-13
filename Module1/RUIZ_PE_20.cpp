#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

const int STRIPE_COUNT = 6;

void drawStripe(float y0, float y1, bool firstColor) {

    if (firstColor)
        glColor3f(0.8f, 0.0f, 0.0f);
    else
        glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, y0);
        glVertex2f(-1.0f, y1);
        glVertex2f(1.0f, y1);
        glVertex2f(1.0f, y0);
    glEnd();
}

void drawStar() {

    glColor3f(1.0f, 1.0f, 0.0f);

    const float PI = 3.14159265f;

    const float centerX = -0.60f;
    const float centerY = 0.50f;

    const float outerRadius = 0.22f;
    const float innerRadius = 0.09f;

    glBegin(GL_POLYGON);

    for (int i = 0; i < 10; i++) {

        float angle =
            i * PI / 5.0f + PI / 2.0f;
        float radius;
        if (i % 2 == 0)
            radius = outerRadius;
        else
            radius = innerRadius;
        float x = centerX + radius * cosf(angle);
        float y = centerY + radius * sinf(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    const float totalHeight = 2.0f;
    const float stripeHeight =
        totalHeight / STRIPE_COUNT;

    for (int i = 0; i < STRIPE_COUNT; i++) {
        float y0 = -1.0f + i * stripeHeight;
        float y1 = y0 + stripeHeight;
        drawStripe(y0, y1, i % 2 == 0
        );
    }

    // Star 
    drawStar();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);
    glutCreateWindow("RUIZ_Q20 - Procedural Striped Flag");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
