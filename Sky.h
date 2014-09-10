#pragma once
#include "WorldObject.h"
#include "Ball.h"
#include "Updatable.h"

/*!	Skybox */
class Sky : public WorldObject, public Updatable
{
	/*! size of the skybox*/
	GLfloat size;
	
	void DrawObject();

	/*! The ball it follows*/	
	Ball* ball;
public:	
	Sky(GLfloat size);
	~Sky();

	/*! Sets the object to follow the ball*/
	void Follow(Ball* ball);
	/*! Stops following the selected ball*/
	void UnFollow();

	/* Goes to the followed ball's position*/
	void Update();
};
