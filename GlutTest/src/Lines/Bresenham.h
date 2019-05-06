#pragma once
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "Shapes/Position.h"


using namespace std;

class Bresenham
{
public:
	Bresenham();
	~Bresenham();

	void draw_pixel(int x, int y);
	void draw_line(int x1, int x2, int y1, int y2);
};