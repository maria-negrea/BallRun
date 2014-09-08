#pragma once

#include "Ball.h"
#include "WorldObject.h"

class Camera : public WorldObject
{
protected:
	Point3D direction;
	void DrawObject();
	Ball *ball;
public:
	Camera();
	~Camera();

	void Perspective();

	void Follow(Ball *ball);
	void UnFollow();

	void Update();
};
