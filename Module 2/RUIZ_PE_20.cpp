#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <iostream>

using namespace std;

const int SEGMENT_COUNT = 60;
const float PI = 3.14159265f;

void getRainbowColor(float t, float &r, float &g, float &b) {
  r = 0.5f + 0.5f * sinf(2.0f * PI * t);
  g = 0.5f + 0.5f * sinf(2.0f * PI * t + 2.0f * PI / 3.0f);
  b = 0.5f + 0.5f * sinf(2.0f * PI * t + 4.0f * PI / 3.0f);
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);

  const float radius = 0.7f;

  glBegin(GL_TRIANGLE_FAN);

  // Center
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(0.0f, 0.0f);

  for (int i = 0; i <= SEGMENT_COUNT; i++) {

    float t = (float)i / SEGMENT_COUNT;

    float angle = t * 2.0f * PI;

    float r, g, b;

    getRainbowColor(t, r, g, b);

    glColor3f(r, g, b);

    float x = radius * cosf(angle);

    float y = radius * sinf(angle);

    glVertex2f(x, y);
  }

  glEnd();

  glFlush();
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitWindowSize(700, 700);

  glutCreateWindow("RUIZ_Q20");

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}