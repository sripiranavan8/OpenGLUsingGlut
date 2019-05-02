#pragma once
#include <GL/glut.h>
#include "Position.h"

class Triangle
{
public:
	Triangle();
	~Triangle();

	void DrawTriangle(Position start,Position finish);
};