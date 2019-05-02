#include <GL/glut.h>
#include <iostream>

#include "Shapes/Quads.h"
#include "Shapes/Triangle.h"
#include "Shapes/Line.h"
#include "Shapes/Circle.h"
#include "Shapes/Square.h"

Position start, finish;
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		start.x = finish.x = x;
		start.y = finish.y = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		finish.x = x;
		finish.y = y;
	}
	glutPostRedisplay();
}

void motion(int x, int y)
{
	finish.x = x;
	finish.y = y;
	glutPostRedisplay();
}

void display()
{

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double h = glutGet(GLUT_WINDOW_HEIGHT);
	glOrtho(0, w, h, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glColor3f(1, 1, 1);
//
	/*Quads quads;
	quads.DrawQuads(start,finish);
	Triangle triangle;
	triangle.DrawTriangle(start, finish);
	Line line;
	line.DrawLine(start, finish);
	Circle circle;
	circle.DrawCircle(start,finish);
	Square square;
	square.DrawSquare(start, finish);*/


	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT");
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}