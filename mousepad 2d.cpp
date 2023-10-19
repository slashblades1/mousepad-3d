#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

GLfloat rotation = 0.0f;
bool rotateClockwise = true;

void drawMousepad() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the black mousepad (rectangle)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, -0.4f); // Bottom-left corner
    glVertex2f(0.6f, -0.4f);  // Bottom-right corner
    glVertex2f(0.6f, 0.4f);   // Top-right corner
    glVertex2f(-0.6f, 0.4f);  // Top-left corner
    glEnd();

    // Draw the blue outline
    glColor3f(0.0f, 0.0f, 1.0f); // Blue outline
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(0.6f, -0.4f);
    glVertex2f(0.6f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
    drawMousepad();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Manual Rotating Mousepad (Rectangle)");

    glutDisplayFunc(display);
    
    

    glewInit();

    glutMainLoop();

    return 0;
}
