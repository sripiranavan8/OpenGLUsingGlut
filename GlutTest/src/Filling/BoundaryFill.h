#pragma once
#include <GL/glut.h>
#include <iostream>
#include "Shapes/Position.h"

class BoundaryFill
{
public:
	BoundaryFill();
	~BoundaryFill();

	void setPixel(int pointx, int pointy, float f[3]);
	void getPixel(int x, int y, float pixels[3]);
	void boundaryFill4(int x, int y, float fillColor[3], float borderColor[3]);
	void mouseT(int btn, int state, int x, int y);

private:
	float fillCol[3] = { 0.4f,0.0f,0.0f };
	float borderCol[3] = { 0.0f,0.0f,0.0f };
};