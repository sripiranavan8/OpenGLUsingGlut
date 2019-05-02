#include "Line.h"

Line::Line()
{

}

Line::~Line()
{

}

void Line::DrawLine(Position start, Position finish)
{
	glBegin(GL_LINES);
	glVertex2i(start.x, start.y);
	glVertex2i(finish.x, finish.y);
	glEnd();
}
