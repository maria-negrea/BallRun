#pragma once
#include "WorldObject.h"
#include "Ball.h"
#include "Updatable.h"

class Digit : public WorldObject, public Updatable
{
	/**< The digit to draw */
	int digit;
	void DrawObject();
	/* The digit position in the score */
	int position;

	Ball* ball;
	/* The score */
	GLfloat *score;
	/**< The position of the digit relative to the ball */
	Point3D followPoint;

	void SetDigit(double digit);
public:
	Digit(int digit,int position,GLfloat* score);
	~Digit();
	
	/*! Sets the object to follow the ball
	* @param ball the ball it will follow
	* @param followPoint the position of the digit relative to the ball
	*/
	void Follow(Ball* ball,Point3D followPoint);
	/*! Stops following the selected ball*/
	void UnFollow();

	/*! Moves the object to the relative position indicated by the followPoint */
	void Update();
};