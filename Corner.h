#pragma once
#include "WorldObject.h"
#include "Ball.h"

class Corner
{
	bool left, right;
	Point3D point;
	GLfloat radius;
public:
	Corner(Point3D point, bool left, bool right, GLfloat radius = 10.0);
	~Corner();

	bool CanMoveLeft(Ball* ball);
	bool CanMoveRight(Ball* ball);

	Point3D GetPoint();
};
