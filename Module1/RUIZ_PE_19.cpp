#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

int SelectedColor = 0;

float colors[6][3] = {
    {1.0f, 0.0f, 0.0f}, // Red
    {0.0f, 1.0f, 0.0f}, // Green
    {0.0f, 0.0f, 1.0f}, // Blue
    {1.0f, 1.0f, 0.0f}, // Yellow
    {1.0f, 0.0f, 1.0f}, // Magenta
    {0.0f, 1.0f, 1.0f}  // Cyan
};

string colorNames[6] = {
    "Red",
    "Green",
    "Blue",
    "Yellow",
    "Magenta",
    "Cyan"
};

void display() {

    glClearColor(
        colors[SelectedColor][0],
        colors[SelectedColor][1],
        colors[SelectedColor][2],
        1.0f
    );

    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {

    if (key >= '1' && key <= '6') {

        SelectedColor = key - '1';

        cout << "Selected color: "
             << colorNames[SelectedColor]
             << endl;

        glutPostRedisplay();
    }

    if (key == 27) {
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q19 - Keyboard Color Picker");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}