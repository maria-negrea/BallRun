#pragma once
#include "Textures.h"
#include "WorldObject.h"

class Ball : public WorldObject
{
	GLUquadricObj *quadratic;

public:
	Ball();
	~Ball();
	void DrawObject();

	Point3D GetDirection();
};
