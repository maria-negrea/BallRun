#pragma once
#include "Textures.h"
#include "WorldObject.h"

class Ball : public WorldObject
{
private:
	GLUquadricObj *quadratic;
	Point3D direction;

public:
	Ball(Point3D initialDirection);
	~Ball();
	void DrawObject();
	void MoveLeft();
	void MoveRight();
	Point3D GetDirection();
	void MoveForward();
};
