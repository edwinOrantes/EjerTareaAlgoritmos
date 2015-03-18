#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    GLfloat angulo;
    float x, y;
    float radio=0.5;                    // Radio
    for (float i=0.0; i<360; i+=7.2)
    {
        angulo =i*M_PI/180.0f;
        x= radio*(cos(angulo));
        y= radio*(sin(angulo));
        glVertex3f(x,y, 0.0f);
    }
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
        glutInitWindowSize(500,500);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Ejercicio 1: By: Edwin Alexander Cortez Orantes");
        init();
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;

    }

