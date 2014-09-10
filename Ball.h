#pragma once
#include "Textures.h"
#include "WorldObject.h"
#include "Updatable.h"

class Ball : public WorldObject, public Updatable
{
private:
	GLUquadricObj *quadratic;/**< Creates a new quadrics object and returns a pointer to it. A null pointer is returned if the routine fails */
	
	Point3D direction; 	/*! * Moving direction of the ball*/
	double speed; /**< Speed of the ball must be negative */
	Point3D onTrack; /** < Vector differerence between ball and the center of the road */
	GLfloat radius; /** < Radius of the ball */
public:
	/** Constructor
	@param initialDirection - moving direction of the ball
	@param speed - speed of the ball
	@param radius - radius of the ball
	*/
	Ball(Point3D initialDirection,double speed, GLfloat radius);
	/**Destructor */
	~Ball();
	/** Draws the ball */
	void DrawObject();

	Point3D GetDirection();
	/** Turns the ball to the left, and sets it on track */
	void MoveLeft(Point3D onTrack);
	/** Turns the ball to the right, and sets it on track */
	void MoveRight(Point3D onTrack);
	/** Moves the ball forward */
	void Update();
};
