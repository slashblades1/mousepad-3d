#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

GLfloat rotasi = 0.0f;
bool putarSearahJarumJam = true;

void gambarMousepad() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Latar belakang putih
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar alas mouse (persegi panjang) berwarna hitam
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, -0.4f); // Sudut kiri bawah
    glVertex2f(0.6f, -0.4f);  // Sudut kanan bawah
    glVertex2f(0.6f, 0.4f);   // Sudut kanan atas
    glVertex2f(-0.6f, 0.4f);  // Sudut kiri atas
    glEnd();

    // Gambar pinggiran berwarna biru
    glColor3f(0.0f, 0.0f, 1.0f); // Pinggiran biru
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(0.6f, -0.4f);
    glVertex2f(0.6f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
    glEnd();
}

void tampilan() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(rotasi, 0.0f, 0.0f, 1.0f);
    gambarMousepad();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mousepad Putar Manual (Persegi Panjang)");

    glutDisplayFunc(tampilan);

    glewInit();

    glutMainLoop();

    return 0;
}
