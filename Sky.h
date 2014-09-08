#pragma once
#include "WorldObject.h"
#include "Ball.h"

class Sky : public WorldObject
{
	GLfloat size;
	void DrawObject();
	Ball* ball;
public:
	Sky(GLfloat size);
	~Sky();

	void Follow(Ball* ball);
	void UnFollow();

	void Update();
};
