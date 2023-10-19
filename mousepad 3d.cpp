//5222600030_Muhammad Fatih Tahir
//5222600024_Faiz Gibran Hilmi Indrato
#include <GL/glut.h>

float rotasiX = 0.0f;
float rotasiY = 0.0f;

void tampilan() {
    // Bersihkan buffer warna dan buffer kedalaman dengan warna putih
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Setel warna latar belakang menjadi putih

    // Atur matriks tampilan dan proyeksi
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 10.0f); // Proyeksi perspektif

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 2.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // Posisi kamera

    // Terapkan rotasi
    glRotatef(rotasiX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotasiY, 0.0f, 1.0f, 0.0f);

    // Gambar mousepad 3D (sebuah persegi panjang yang lebih tipis)
    glColor3f(0.0f, 0.0f, 0.0f); // Atur warna menjadi hitam

    glPushMatrix();
    glTranslatef(-0.45f, -0.25f, -0.02f); // Atur posisi sepanjang sumbu z
    glScalef(0.9f, 0.5f, 0.04f); // Skala untuk membuat persegi panjang yang lebih tipis
    glutSolidCube(1.0f); // Gambar sebuah kubus solid
    glPopMatrix();

    // Tukar buffer depan dan belakang untuk menampilkan gambar yang dirender
    glutSwapBuffers();
}

void tombolSpesial(int tombol, int x, int y) {
    // Tangani penekanan tombol panah untuk memutar mousepad
    switch (tombol) {
    case GLUT_KEY_UP:
        rotasiX += 5.0f;
        break;
    case GLUT_KEY_DOWN:
        rotasiX -= 5.0f;
        break;
    case GLUT_KEY_LEFT:
        rotasiY += 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        rotasiY -= 5.0f;
        break;
    }
    glutPostRedisplay(); // Minta penggambaran ulang untuk melihat perubahan
}

int main(int argc, char** argv) {
    // Inisialisasi GLUT dan buat jendela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Mousepad 3D yang Lebih Tipis");

    // Aktifkan pengujian kedalaman untuk penggambaran 3D
    glEnable(GL_DEPTH_TEST);

    // Atur fungsi tampilan
    glutDisplayFunc(tampilan);

    // Atur fungsi khusus untuk penekanan tombol panah
    glutSpecialFunc(tombolSpesial);

    // Masuk ke loop utama GLUT
    glutMainLoop();

    return 0;
}
