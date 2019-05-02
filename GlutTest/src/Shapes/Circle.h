#pragma once
#include <GL/glut.h>

#include "Position.h"

class Circle
{
public:
	Circle();
	~Circle();

	void DrawCircle(Position start, Position finish);
};