#pragma once
#include "WorldObject.h"

class Sky : public WorldObject
{
	GLfloat size;
	void DrawObject();
public:
	Sky(GLfloat size);
	~Sky();
};
