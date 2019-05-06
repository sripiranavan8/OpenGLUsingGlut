#include "Quads.h"

Quads::Quads()
{

}

Quads::~Quads()
{

}

void Quads::DrawQuads(Position start, Position finish)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glVertex2i(start.x, start.y);
	glVertex2i(finish.x, start.y);
	glVertex2i(finish.x, finish.y);
	glVertex2i(start.x, finish.y);
	glEnd();
}

