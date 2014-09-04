#pragma once
#include "Textures.h"
#include "WorldObject.h"

class Ball : public WorldObject
{
private:
	GLUquadricObj *quadratic;
	Point3D direction;
	double speed;
	GLfloat radius;
public:
	Ball(Point3D initialDirection,double speed, GLfloat radius);
	~Ball();
	void DrawObject();

	Point3D GetDirection();
	void MoveLeft();
	void MoveRight();
	void MoveForward();
};
