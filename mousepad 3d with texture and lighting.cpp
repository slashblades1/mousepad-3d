//5222600030_Muhammad Fatih Tahir
//5222600024_Faiz Gibran Hilmi Indrato
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "getBMP.h"

GLuint textureID;

float angleX = 0.0f;
float angleY = 0.0f;
float toX = 1.0f;
float toY = 1.0f;
float posX = 0.0f;
float posY = 0.0f;
float rotationSpeed = 0.00169f;

int mouseX, mouseY;
bool isMouseDragging = false;

GLfloat lightPosition[] = { -1.0, 1.0, 0.0, 0.0 };

void setupLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    GLfloat matAmbient[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat matDiffuse[] = { 0.9, 0.9, 0.9, 1.0 };
    GLfloat matSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat matShininess[] = { 100.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
}

void loadTexture(const char* fileName)
{
    imageFile* textureImage = getBMP(fileName);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureImage->width, textureImage->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureImage->data);
    glGenerateMipmap(GL_TEXTURE_2D);

    delete[] textureImage->data;
    delete textureImage;
}

void drawTexturedMousepadWithLighting()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glEnable(GL_LIGHTING);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, 1.0f, 1.0f);
    glEnd();

    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}

void drawSceneWithLighting(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.9, 0.9, 0.9);
    glLoadIdentity();

    glTranslatef(toX, toY, -15.0);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glTranslatef(posX, posY, 0.0f);

    glPushMatrix();
    glScalef(1.0, 2.0, 0.21);
    drawTexturedMousepadWithLighting();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(4.0, 4.0, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void drawScene(void)
{
    drawSceneWithLighting();
}

void update(int value)
{
    angleX += rotationSpeed;
    angleY += rotationSpeed;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void idleCallback(void)
{
    update(0);
}

void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    setupLighting();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void specialKeyInput(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        angleY -= 5.0;
        break;
    case GLUT_KEY_RIGHT:
        angleY += 5.0;
        break;
    case GLUT_KEY_UP:
        angleX -= 5.0;
        break;
    case GLUT_KEY_DOWN:
        angleX += 5.0;
        break;
    case GLUT_KEY_SHIFT_L:
        toX -= 5.0;
        break;
    case GLUT_KEY_SHIFT_R:
        toX += 5.0;
        break;
    }
    glutPostRedisplay();
}

void tombolBiasa(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        posY += 0.1f;
        break;
    case 's':
        posY -= 0.1f;
        break;
    case 'a':
        posX -= 0.1f;
        break;
    case 'd':
        posX += 0.1f;
        break;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            isMouseDragging = true;
            mouseX = x;
            mouseY = y;
        }
        else if (state == GLUT_UP)
        {
            isMouseDragging = false;
        }
    }
}

void mouseMotion(int x, int y)
{
    if (isMouseDragging)
    {
        int dx = x - mouseX;
        int dy = y - mouseY;

        angleY += static_cast<float>(dx) * 0.5f;
        angleX += static_cast<float>(dy) * 0.5f;

        mouseX = x;
        mouseY = y;

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Mousepad Square");

    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);
    glutKeyboardFunc(tombolBiasa);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutIdleFunc(idleCallback);
    loadTexture("../../Textures/mousepad.bmp");

    glutMainLoop();
    return 0;
}