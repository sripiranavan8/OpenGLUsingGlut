#include "TestEllipse.h"

TestEllipse::TestEllipse()
{
}

TestEllipse::~TestEllipse()
{
}

void TestEllipse::DrawEllipse(Position start, Position finish)
{
	glClear(GL_COLOR_BUFFER_BIT);
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double h = glutGet(GLUT_WINDOW_HEIGHT);

	Ellipse(int(0.5*finish.x),int(0.5*finish.y),start.x,start.y, 0, 0, 0);

}

void TestEllipse::delay(unsigned int ms)
{
	clock_t goal = ms + clock();
	while (goal > clock());
}

void TestEllipse::drawDot(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b)
{
	glColor3f(r, g, b);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void TestEllipse::symmetricPixels(float x, float y, float xc, float yc, float r, float g, float b)
{
	drawDot(xc + x, yc + y, r, g, b);
	drawDot(xc - x, yc + y, r, g, b);
	drawDot(xc + x, yc - y, r, g, b);
	drawDot(xc - x, yc - y, r, g, b);
}

void TestEllipse::Ellipse(int a, int b, int xc, int yc, float r, float g, float bl)
{
	int aSq, bSq, twoASq, twoBSq, d, dx, dy, x, y;
	aSq = a * a;
	bSq = b * b;
	twoASq = 2 * aSq;
	twoBSq = 2 * bSq;
	d = bSq - b * aSq + aSq / 4;
	dx = 0;
	dy = twoASq * b;
	x = 0;
	y = b;
	symmetricPixels(float(x), float(y), float(xc), float(yc), float(r), float(g), float(bl));
	while (dx < dy)
	{
		x++;
		dx += twoBSq;
		if (d >= 0)
		{
			y--;
			dy -= twoASq;
		}
		if (d < 0)
			d += bSq + dx;
		else
			d += bSq + dx - dy;
		symmetricPixels(float(x), float(y), float(xc), float(yc), float(r), float(g), float(bl));
	}
	d = (int)(bSq*(x + 0.5)*(x + 0.5) + aSq * (y - 1)*(y - 1) -
		aSq * bSq);
	while (y > 0)
	{
		y--;
		dy -= twoASq;
		if (d <= 0)
		{
			x++;
			dx += twoBSq;
		}
		if (d > 0)
			d += aSq - dy;
		else
			d += aSq - dy + dx;
		symmetricPixels(float(x), float(y), float(xc), float(yc), float(r), float(g), float(bl));
	}
	glFlush();
}

void TestEllipse::DrawCircle(Position start, Position finish)
{
	glClear(GL_COLOR_BUFFER_BIT);
	float x = float(finish.x - start.x); //calculating number to square in next step
	float y = float(finish.y - start.y);
	float dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);

		middy_circle(float(dist), float(start.x), float(start.y));
		delay(2);

}

void TestEllipse::middy_circle(float r, float xc, float yc)
{
	glPointSize(1.0);
	float d = 1 - r;
	float x = 0, y = r;
	glBegin(GL_POINTS);
	glVertex2f(round(x + xc), round(y + yc));
	glEnd();
	glFlush();
	glBegin(GL_POINTS);
	while (y > x) {
		if (d < 0)
		{
			d += ((2 * x) + 3);
			x++;
		}
		else if (d >= 0)
		{
			d += (2 * (x - y)) + 5;
			x++;
			y--;
		}
		glVertex2f(round(x + xc), round(y + yc));
		glVertex2f(round(y + xc), round(x + yc));
		glVertex2f(round(x + xc), round(-y + yc));
		glVertex2f(round(y + xc), round(-x + yc));
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(round(-x + xc), round(-y + yc));
		glVertex2f(round(-y + xc), round(-x + yc));
		glVertex2f(round(-x + xc), round(y + yc));
		glVertex2f(round(-y + xc), round(x + yc));
		glColor3f(0.0, 0.0, 0.0);
	}
	glEnd();
	glFlush();
}
