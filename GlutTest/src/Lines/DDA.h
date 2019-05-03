#pragma once
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "Shapes/Position.h"


using namespace std;

class DDA
{
public:
	DDA();
	~DDA();

	void dda_line(int x1, int y1, int x2, int y2);
	void dda_star_draw(Position start, Position finish);
};