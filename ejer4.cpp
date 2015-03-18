#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void display()
{

    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Resetear transformaciones
    glLoadIdentity();

    // Rotar en "rotate_x" y "rotate_y"
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef(rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z);

    // Otras transformaciones
    glScalef(scale, scale, scale);

    // Color blanco
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0 );
    glVertex3f(0.3,  0.0, 0.0 );
    glVertex3f( 0.3,  0.3, 0.0 );
    glVertex3f(0.0, 0.3, 0.0 );
    glEnd();

    //Color azul
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 0.0, 0.3, 0.0 );
    glVertex3f(  0.3,  0.3, 0.0 );
    glVertex3f( 0.3,  0.3, -0.3 );
    glVertex3f( 0.0, 0.3, -0.3 );
    glEnd();

    // Color rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 0.0, 0.0, 0.0 );
    glVertex3f(  0.3,  0.0, 0.0 );
    glVertex3f( 0.3,  0.0, -0.3 );
    glVertex3f( 0.0, 0.0, -0.3 );
    glEnd();

    // Color Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f( 0.0, 0.0, 0.0 );
    glVertex3f(  0.0,  0.3, 0.0 );
    glVertex3f( 0.0,  0.3, -0.3 );
    glVertex3f( 0.0, 0.0, -0.3 );
    glEnd();

    // Color blanco
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f( 0.0, 0.0, -0.3 );
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(  0.3,  0.0, -0.3 );
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 0.3,  0.3, -0.3 );
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 0.0, 0.3, -0.3 );
    glEnd();

    // Color verde
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 0.3, 0.0, 0.0 );
    glVertex3f(  0.3,  0.0, -0.3 );
    glVertex3f( 0.3,  0.3, -0.3 );
    glVertex3f( 0.3, 0.3, 0.0 );
    glEnd();
    glFlush();
    glutSwapBuffers();

}


void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: La rotacion se aumenta en 8 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 8;

    //  Flecha izquierda: La rotacion se disminuye en 8 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 8;

    else if (key == GLUT_KEY_UP)
        rotate_x += 7;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;

    else if (key == GLUT_KEY_F2)
        rotate_z += 7;

    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;

    // actualización de visualización
    glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        scale=0.5;
        break;
    case 'S':
        scale=1.5;
        break;
    case 'n':           //Posicion normal
        scale=1.0;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 27:                 // 27 es Esc
        exit(0);			// Sale del programa
    }

    glutPostRedisplay();  // actualización de visualización
}



int main(int argc, char* argv[])
{

    glutInit(&argc,argv);

    //  Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Ejercicio 4: By: Edwin Alexander Cortez Orantes");

    //  Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); //invoca funcion de teclado
    glutSpecialFunc(specialKeys);//invoca teclas de función especial
    glutMainLoop();
    return 0;

}
