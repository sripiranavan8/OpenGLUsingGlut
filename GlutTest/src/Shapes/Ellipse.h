#pragma once
#include <GL/glut.h>

#include "Position.h"

class Ellipse
{
public:
	Ellipse();
	~Ellipse();

	void DrawEllipse(Position start,Position finish);
};
