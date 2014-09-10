#pragma once

#include "Ball.h"
#include "WorldObject.h"
#include "Updatable.h"

class Camera : public WorldObject, public Updatable
{
protected:
	/** Direction into which the camers looks */
	Point3D direction;
	/** Implements the method, for the class not to be abstract */
	void DrawObject();
	/*! The ball it follows*/
	Ball *ball;
public:
	Camera();
	~Camera();

	/** Changes the view to the camera's perspective */ 
	void Perspective();

	/*! Sets the object to follow the ball*/
	void Follow(Ball* ball);
	/*! Stops following the selected ball*/
	void UnFollow();

	/** Moves the camera behind the ball */
	void Update();
};
