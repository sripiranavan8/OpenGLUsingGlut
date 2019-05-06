#include "Triangle.h"

Triangle::Triangle()
{ 

}

Triangle::~Triangle()
{

}

void Triangle::DrawTriangle(Position start, Position finish)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex2i(start.x, start.y);
	glVertex2i(finish.x, start.y);
	glVertex2i(finish.x, finish.y);
	glEnd();
}
