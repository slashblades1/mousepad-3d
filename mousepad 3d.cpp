//5222600030_Muhammad Fatih Tahir
//5222600024_Faiz Gibran Hilmi Indrato


#include <GL/glut.h>

float rotationX = 0.0f;
float rotationY = 0.0f;

void display() {
    // Clear the color buffer and depth buffer with white color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white

    // Set up the view and projection matrices
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 10.0f); // Perspective projection

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 2.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // Camera position

    // Apply rotations
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

    // Draw the 3D mousepad (a thinner rectangle)
    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black

    glPushMatrix();
    glTranslatef(-0.45f, -0.25f, -0.02f); // Set the position along the z-axis
    glScalef(0.9f, 0.5f, 0.04f); // Scale to create the thinner rectangle
    glutSolidCube(1.0f); // Draw a solid cube
    glPopMatrix();

    // Swap the front and back buffers to display the rendered image
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    // Handle arrow key presses to rotate the mousepad
    switch (key) {
    case GLUT_KEY_UP:
        rotationX += 5.0f;
        break;
    case GLUT_KEY_DOWN:
        rotationX -= 5.0f;
        break;
    case GLUT_KEY_LEFT:
        rotationY += 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        rotationY -= 5.0f;
        break;
    }
    glutPostRedisplay(); // Request a redraw to see the changes
}

int main(int argc, char** argv) {
    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Even Thinner 3D Mousepad");

    // Enable depth testing for 3D rendering
    glEnable(GL_DEPTH_TEST);

    // Set the display function
    glutDisplayFunc(display);

    // Set the special function for arrow key presses
    glutSpecialFunc(specialKeys);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}
