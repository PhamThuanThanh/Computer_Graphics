

/* -- INCLUDE FILES ------------------------------------------------------ */

#include "gl/gl.h"
#include "gl/glu.h"
#include "gl/glut.h"


static GLfloat spin = 0.0;
void init(void) 
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPopMatrix();
    glutSwapBuffers();

}

void spinDisplay(void)
{
    spin = spin + 45.0;
    if (spin > 360.0)
    spin = spin - 360.0;
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int n=0;
void Mymouse(int button, int state, int x, int y) 
{
	
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    	n++;
    	glutIdleFunc(spinDisplay);
	} else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		n++;
    	glutIdleFunc(NULL);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Vidu_02");
    init();
    
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutMouseFunc(Mymouse);
    glutMainLoop();
return 0;
}
