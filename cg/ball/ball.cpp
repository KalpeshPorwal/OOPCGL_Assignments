/*==============================================

Name : Shalaka Alkute
Roll No : 21203
Problem Statement : Movement of Ball using arrow keys

===============================================*/
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

float xr = 0, yr = 0; // to control the ball movement
#define PI 3.14159265f
GLfloat ballRadius = 0.1f;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(xr, yr, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 1, 0);
	glVertex2f(0.0f, 0.0f);//specifies the x and y coordinates of the vertex, and the z coordinate is set to zero
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++)
	{
		angle = i * 2.0f * PI / numSegments;
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}
	glEnd();
	glFlush();
	glutPostRedisplay();//marks the current window as needing to be redisplayed
	glutSwapBuffers();// swaps the buffers of the current window if double buffered.
	//Performs a buffer swap on the layer in use for the current window.
}

void keymovement(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP: // to move ball up
		yr = yr + 0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN: // to move ball down
		yr-=0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT: // to move ball left
		xr-=0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT: // to move ball right
		xr+=0.1;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char* argv[])
{
	cout << "Use arrow key" << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);//glutInitWindowSize and glutInitWindowPosition define the size
	glutInitWindowPosition(600, 50);//position (upper left corner) of the window on the screen.
	glutCreateWindow("Moving ball");

	glutDisplayFunc(display);

	glClearColor(0, 0.4, 0.5, 0);
	gluOrtho2D(0.0, 400, 0.0, 400);//specifies the red, green, blue, and alpha values used by
	//glClear() to clear the color buffers
	glutSpecialFunc(keymovement);

	glutMainLoop();

	return 0;
}

