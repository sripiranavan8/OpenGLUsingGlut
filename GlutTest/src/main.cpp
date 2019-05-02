#include <GL/glut.h>
#include <iostream>

#include "Shapes/Quads.h"
#include "Shapes/Triangle.h"
#include "Shapes/Line.h"
#include "Shapes/Circle.h"
#include "Shapes/Square.h"

static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else {
		value = num;
	}
	glutPostRedisplay();
}
void createMenu(void) {
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Quads", 2);
	glutAddMenuEntry("Triangle", 3);
	glutAddMenuEntry("Circle", 4);
	glutAddMenuEntry("Square", 5);    
	glutAddMenuEntry("Line", 6);
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 1);
	glutAddSubMenu("Draw", submenu_id);
	glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}

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

	if (value == 1) {
		glutPostRedisplay();
	}
	else if (value == 2) {
		Quads quads;
		quads.DrawQuads(start, finish);
	}
	else if (value == 3) {
		Triangle triangle;
		triangle.DrawTriangle(start, finish);
	}
	else if (value == 4) {
		Circle circle;
		circle.DrawCircle(start, finish); 
	}
	else if (value == 5) {
		Square square;
		square.DrawSquare(start, finish);
	}
	else if (value == 6)
	{
		Line line;
		line.DrawLine(start, finish);
	}
	glFlush();

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
	createMenu();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}