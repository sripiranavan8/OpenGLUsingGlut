#include "Square.h"
#include <math.h>

Square::Square()
{

}

Square::~Square()
{

}

void Square::DrawSquare(Position start, Position finish)
{
	double x = finish.x - start.x; //calculating number to square in next step
	double y = finish.y - start.y;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);

	glBegin(GL_POLYGON);
	glVertex3d(start.x, start.y, 0);
	glVertex3d(start.x + dist, start.y, 0);
	glVertex3d(start.x + dist, start.y + dist, 0);
	glVertex3d(start.x, start.y + dist, 0);
	glEnd();
}
