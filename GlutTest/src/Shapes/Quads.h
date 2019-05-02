#pragma once
#include <GL/glut.h>
#include "Position.h"

class Quads
{
public:
	Quads();
	~Quads();

	void DrawQuads(Position start, Position finish);
private:
};