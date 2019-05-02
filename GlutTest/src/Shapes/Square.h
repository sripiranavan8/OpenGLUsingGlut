#pragma once
#include <GL/glut.h>

#include "Position.h"

class Square
{
public:
	Square();
	~Square();

	void DrawSquare(Position start,Position finish);
};