#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    //Cuadro
    glBegin(GL_POLYGON);
	glVertex3f(0.4,0.2,0.0);
	glVertex3f(-0.4,0.2,0.0);
	glVertex3f(-0.4,-0.2,0.0);
	glVertex3f(0.4,-0.2,0.0);
    glEnd();

    //Punta
    glBegin(GL_TRIANGLES);
    glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, -0.3, 0.0);
    glVertex3f(0.7, 0.0, 0.0);
    glEnd();
    
    // Ala de arriba
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0.2, 0.2, 0.0);
    glVertex3f(-0.2, 0.2, 0.0);
    glVertex3f(0.0, 0.4, 0.0);
    glVertex3f(-0.4, 0.4, 0.0);
    glEnd();
    
    // Ala de abajo
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.2, -0.2, 0.0);
    glVertex3f(0.2, -0.2, 0.0);
    glVertex3f(0.0, -0.4, 0.0);

    //Otro
    glVertex3f(-0.2, -0.2, 0.0);
    glVertex3f(0.0, -0.4, 0.0);
    glVertex3f(-0.4, -0.4, 0.0);
    glEnd();

    // Parte de atras
    glPointSize(60);
    glBegin(GL_POINTS);
    glVertex3f(-0.4, 0.1, 0.0);
    glVertex3f(-0.4, -0.1, 0.0);
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
        glutCreateWindow("Ejercicio 3: By: Edwin Alexander Cortez Orantes");
        init();
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;

    }

