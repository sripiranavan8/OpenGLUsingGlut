#include "BoundaryFill.h"

BoundaryFill::BoundaryFill()
{
}

BoundaryFill::~BoundaryFill()
{
}

void BoundaryFill::setPixel(int pointx, int pointy, float f[3])
{
	glBegin(GL_POINTS);
	glColor3fv(f);
	glVertex2i(pointx, pointy);
	glEnd();
	glFlush();
}

void BoundaryFill::getPixel(int x, int y, float pixels[3])
{
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixels);
}

void BoundaryFill::boundaryFill4(int x, int y, float fillColor[3], float borderColor[3])
{
	float interiorColor[3];
	getPixel(x, y, interiorColor);
	if ((interiorColor[0] != borderColor[0] && (interiorColor[1]) != borderColor[1] && (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] && (interiorColor[1]) != fillColor[1] && (interiorColor[2]) != fillColor[2]))
	{
		setPixel(x, y, fillColor);
		boundaryFill4(x + 1, y, fillColor, borderColor);
		boundaryFill4(x - 1, y, fillColor, borderColor);
		boundaryFill4(x, y + 1, fillColor, borderColor);
		boundaryFill4(x, y - 1, fillColor, borderColor);
	}
}

void BoundaryFill::mouseT(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int xi = x;
		int wh = GLUT_SCREEN_HEIGHT;
		int yi = (wh - y);
		boundaryFill4(xi, yi, fillCol, borderCol);
	}
}
