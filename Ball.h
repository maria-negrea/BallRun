#pragma once
#include "Textures.h"
#include "WorldObject.h"

class Ball : public WorldObject
{
	GLUquadricObj *quadratic;

public:
	Ball(GLfloat X, GLfloat Y, GLfloat Z, GLfloat radius);
	~Ball();
	void DrawObject();
};
