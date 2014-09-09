#pragma once
#include "WorldObject.h"
#include "Ball.h"

class Digit : public WorldObject
{
	int digit;
	void DrawObject();

	Ball* ball;
	Point3D followPoint;
public:
	Digit(int digit);
	~Digit();

	void Follow(Ball* ball, Point3D followPoint);
	void Update();

	void SetDigit(double digit);
};