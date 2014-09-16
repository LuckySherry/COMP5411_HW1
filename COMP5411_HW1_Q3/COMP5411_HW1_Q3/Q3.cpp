#include <GL/glut.h>
#include <cstdio>

void myDraw();
void myReshape(int w, int h);
void myMouse(int b,int s,int x,int y);
void myKeyboard(unsigned char c, int x, int y);
void myTimeOut(int id);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//initialize glut and gl

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);

	//set up callbacks
	glutDisplayFunc(myDraw);
	glutReshapeFunc(myReshape);
	//glutMouseFunc(myMouse);
	//glutKeyboardFunc(myKeyboard);
	//glutTimerFunc(20, myTimeOut, 0);

	
	glutMainLoop();
	return 0;

}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 1, 1000);     // setup a perspective projection

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//y-lookat
	/*gluLookAt(                          // set up the camera
		1.0, 13.0, 5.0,          // eye position
		1.0, 3.0, 5.0,          // lookat position
		0.0, 0.0, 1.0);         // up direction
		*/
	//z-lookat
	/*gluLookAt(                          // set up the camera
		1.0, 3.0, 15.0,          // eye position
		1.0, 3.0, 5.0,          // lookat position
		0.0, 1.0, 0.0);         // up direction
		*/
	//x-lookat
	gluLookAt(                          // set up the camera
		10.0, 3.0, 5.0,          // eye position
		1.0, 3.0, 5.0,          // lookat position
		0.0, 0.0, 1.0);         // up direction
		
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void myDraw()
{
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	
	//glTranslatef()
	glPushMatrix();
		glTranslatef(1.0, 3.0, 5.0);
		glScalef(1.0, 4.0, 3.0);
		glutSolidSphere(2.0, 20.0, 20.0);
	glPopMatrix();
	//glColor3f(0.0, 0.0, 1.0);
	//glRectf(0.25, 0.25, 0.75, 0.75);
	glutSwapBuffers();
}
