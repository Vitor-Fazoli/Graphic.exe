//#include <GL/gl.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

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

void resize(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void drawPolygon(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 0.0, 0.0);
    // desenha o poligono
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(20.0, 20.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(80.0, 20.0, 0.0);
    glVertex3f(70.0, 30.0, 0.0);
    glVertex3f(80.0, 80.0, 0.0);
    glVertex3f(70.0, 70.0, 0.0);
    glVertex3f(20.0, 80.0, 0.0);
    glVertex3f(30.0, 70.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(20.0, 80.0, 0.0);
    glVertex3f(20.0, 20.0, 0.0);

    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Um simples quadrado vazado");

    glutDisplayFunc(drawPolygon);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    // glewExperimental = GL_TRUE;

    setup();
    glutMainLoop();

    return 0;
}
