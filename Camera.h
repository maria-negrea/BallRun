#pragma once

#include "Ball.h"
#include "WorldObject.h"

class Camera : public WorldObject
{
protected:
	void DrawObject();
public:
	Camera();
	~Camera();

	void Perspective();
	void Follow(Ball& ball);
};
