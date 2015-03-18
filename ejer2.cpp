#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    //Cuadro
    glBegin(GL_POLYGON);
	glVertex3f(0.2,0.2,0.0);
	glVertex3f(-0.2,0.2,0.0);
	glVertex3f(-0.2,-0.2,0.0);
	glVertex3f(0.2,-0.2,0.0);
    glEnd();

    //Primer Triangulo
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.2,0.2,0.0);
    glVertex3f(0.2,-0.2,0.0);
    glVertex3f(0.5,0.0,0.0);

    //Segundo Triangulo
    glColor3f(1.0, 1.0,0.0);
    glVertex3f(0.2, 0.2, 0.0);
    glVertex3f(-0.2, 0.2, 0.0);
    glVertex3f(0.0,0.5,0.0);

    glColor3f(0.0, 1.0, 0.0);
    //Tercero Triangulo
    glVertex3f(-0.2, 0.2, 0.0);
    glVertex3f(-0.2, -0.2, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);

    //Cuarto Triangulo
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.2, -0.2, 0.0);
    glVertex3f(0.2, -0.2, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glEnd();
    glFlush();
}
    void init (void)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    }

    int main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800,800);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Ejercicio 2: By: Edwin Alexander Cortez Orantes");
        init();
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;

    }

