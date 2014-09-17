//-----------------------------------------------------------------------
//      File:           Q3.cpp
//      Description:    Example program draw a ellipsoid
//      Programmer:     Wang Xinyu, 20082688
//      For:            COMP 5411 Homework 1, Question 3
//      Date:           16th, Sep. 2014
//
//      By default, you will look at the ellipsoid from the Z-axis at (1,3,15)
//		When you press 'x' button or 'y' button or 'z' button,
//		you can look at it from correspoding axis
//-----------------------------------------------------------------------


#include <cstdlib>
#include <iostream>
#include <cstdio>

#include <GL/glut.h>                    
#include <GL/glu.h>                     
#include <GL/gl.h>                      

void myDraw();
void myReshape(int w, int h);
void myMouse(int b,int s,int x,int y);
void myKeyboard(unsigned char c, int x, int y);
void myTimeOut(int id);

//Globle Variables
double eye_x = 1.0, eye_y = 3.0, eye_z = 15.0, up_y = 1.0, up_z = 0.0;

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
	glutKeyboardFunc(myKeyboard);
	
	glutMainLoop();
	return 0;

}

void myKeyboard(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'x':
		eye_x = 10.0;
		eye_y = 3.0;
		eye_z = 5.0;
		up_y = 0.0;
		up_z = 1.0;
		std::cout << "You Are Looking From X-Axis" << std::endl;
		break;
	case 'y':
		eye_x = 1.0;
		eye_y = 13.0;
		eye_z = 5.0;
		up_y = 0.0;
		up_z = 1.0;
		std::cout << "You Are Looking From Y-Axis" << std::endl;
		break;
	case 'z':
		eye_x = 1.0;
		eye_y = 3.0;
		eye_z = 15.0;
		up_y = 1.0;
		up_z = 0.0;
		std::cout << "You Are Looking From Z-Axis" <<std::endl; 
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 1, 1000);     // setup a perspective projection

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void myDraw()
{
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	
	glPushMatrix();
		//camera position will be different when user change the axis.
		gluLookAt(                          // set up the camera
			eye_x, eye_y, eye_z,          // eye position
			1.0, 3.0, 5.0,          // lookat position
			0.0, up_y, up_z);         // up direction
		glTranslatef(1.0, 3.0, 5.0);	//Move the object from origin to (1,3,5)
		glScalef(1.0, 4.0, 3.0);		//Scale the object seperatedly by y-axis and z-axis
		glutSolidSphere(1.0, 20.0, 20.0);	//draw a ellipsoid centered at origin with radius equals 1.
	glPopMatrix();

	glutSwapBuffers();
}
