#pragma once
#include <GL/glut.h>

#include "Position.h"

class Line
{
public:
	Line();
	~Line();

	void DrawLine(Position start, Position finish);
};