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

	void bresenham_line(float x1, float y1, float x2, float y2);
	void bresenham_spoke(Position start, Position finish);
};