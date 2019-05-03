#include "DDA.h"

DDA::DDA()
{
}

DDA::~DDA()
{
}

void DDA::dda_line(int x1, int y1, int x2, int y2)
{
	float blue = (float)0.01;
	glPointSize(1.0);
	float dy = float(y2 - y1); float dx = float(x2 - x1);
	int steps = 1, length;
	if (abs(dy) > abs(dx))
		length = int(abs(dy));
	else
		length = int(abs(dx));
	float x = float(x1); float y = float(y1);
	float xinc = dx / length; float yinc = dy / length;
	glBegin(GL_POINTS);
	while (steps < length) {
		glVertex2f(round(x), round(y));
		x += xinc;
		y += yinc;
		steps++;
		glColor3f(0.0, 0.0, blue);
		blue = float(blue + 0.01);
		if (blue == 1.0)
			blue =float(0.01);
	}
	glEnd();
	glFlush();
}

void DDA::dda_star_draw(Position start, Position finish)
{
	glClear(GL_COLOR_BUFFER_BIT);
	dda_line(start.x, start.y, finish.x, finish.y);
}
