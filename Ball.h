#pragma once
#include "Textures.h"
#include "WorldObject.h"

class Ball : public WorldObject
{
private:
	GLUquadricObj *quadratic;
	Point3D direction;
	double speed;
	Point3D onTrack;
	GLfloat radius;
public:
	Ball(Point3D initialDirection,double speed, GLfloat radius);
	~Ball();
	void DrawObject();

	Point3D GetDirection();
	void MoveLeft(Point3D onTrack);
	void MoveRight(Point3D onTrack);
	void MoveForward();
};
