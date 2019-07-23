#include <GL/glut.h>
#include <GL/gl.h>

void myDisplay()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2i(30, 30);
        glVertex2i(50, 30);
        glVertex2i(50, 50);
        glVertex2i(30, 50);
    glEnd();

    glutSwapBuffers();
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutCreateWindow("Gambar 3D");

    glutDisplayFunc(myDisplay);
    gluOrtho2D(0, 100, 0, 100);

    glutMainLoop();
}