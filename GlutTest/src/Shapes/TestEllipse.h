#pragma once
#include <GL/glut.h>

#include "Position.h"
#include <iostream>
#include <math.h>
#include <time.h>

class TestEllipse
{
public:
	TestEllipse();
	~TestEllipse();

	void DrawEllipse(Position start, Position finish);
	void delay(unsigned int ms);
	void drawDot(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b);
	void symmetricPixels(float x, float y, float xc, float yc, float r, float g, float b);
	void Ellipse(int a, int b, int xc, int yc, float r, float g, float bl);

	void DrawCircle(Position start, Position finish);
	void middy_circle(float r, float xc, float yc);

private:

};
