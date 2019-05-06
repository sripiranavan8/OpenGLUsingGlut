#include "Circle.h"
#include <math.h>

Circle::Circle()
{

}

Circle::~Circle()
{

}

void Circle::DrawCircle(Position start, Position finish)
{
	glClear(GL_COLOR_BUFFER_BIT);
	double x = finish.x - start.x; //calculating number to square in next step
	double y = finish.y - start.y;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);

	double theta;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.142 / 180;
		glVertex2d(start.x + dist * cos(theta), start.y + dist * sin(theta));
	}
	glEnd();
}
