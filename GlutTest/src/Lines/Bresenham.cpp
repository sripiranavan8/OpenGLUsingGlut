#include "Bresenham.h"

Bresenham::Bresenham()
{
}

Bresenham::~Bresenham()
{
}

void Bresenham::bresenham_line(float x1, float y1, float x2, float y2)
{
	glPointSize(1.0);
	int flag = 0, flag1 = 0;
	float m = ((y2 - y1) / (x2 - x1));
	if (m > 0 && m <= 1)
		flag = 1;
	if (m > 1)
		flag = 2;
	if (m < 0 && abs(m) <= 1)
		flag = 3;
	if (m < -1)
		flag = 4;
	// vars
	float dx = x2 - x1; float dy = y2 - y1;
	float dinit, d;
	float x = x1; float y = y1;
	glBegin(GL_POINTS);
	cout << flag;
	switch (flag) {
	case 1: while (x <= x2)
	{
		if (flag1 == 0)
		{
			dinit = (2 * dy) - dx;
			d = dinit;
			glVertex2f(round(x), round(y));
			flag1 = 1;
		}
		else
		{
			if (d <= 0)
			{
				glVertex2f(round(x), round(y));
				x++;
				d = d + (2 * dy);
			}
			else
			{
				glVertex2f(round(x), round(y));
				x++;
				y++;
				d = d + (2 * (dy - dx));
			}
		}
	}break;
	case 2: while (x <= x2)
	{
		if (flag1 == 0)
		{
			dinit = (2 * dx) - dy;
			d = dinit;
			glVertex2f(round(x), round(y));
			flag1 = 1;
		}
		else
		{
			if (d <= 0)
			{
				glVertex2f(round(x), round(y));
				y++;
				d += (2 * dx);
			}
			else
			{
				glVertex2f(round(x), round(y));
				x++;
				y++;
				d += 2 * (dx - dy);
			}
		}
	}break;
	case 3: while (x <= x2)
	{
		if (flag1 == 0)
		{
			dinit = -(2 * dy) - dx;
			d = dinit;
			glVertex2f(round(x), round(y));
			flag1 = 1;
		}
		else
		{
			if (d <= 0)
			{
				glVertex2f(round(x), round(y));
				x++;
				d -= (2 * dy);
			}
			else
			{
				glVertex2f(round(x), round(y));
				x++;
				y--;
				d = d - (2 * (dy + dx));
			}
		}
	}break;
	case 4: while (x <= x2)
	{
		if (flag1 == 0)
		{
			dinit = (2 * x) + dy;
			d = dinit;
			glVertex2f(round(x), round(y));
			flag1 = 1;
		}
		else
		{
			if (d <= 0)
			{
				glVertex2f(round(x), round(y));
				y--;
				d += (2 * dx);
			}
			else
			{
				glVertex2f(round(x), round(y));
				x++;
				y++;
				d += 2 * (dy + dx);
			}
		}
	}break;
	}
	glEnd();
	glFlush();
}

void Bresenham::bresenham_spoke(Position start, Position finish)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	bresenham_line(float(start.x), float(start.y), float(finish.x), float(finish.y));
}
