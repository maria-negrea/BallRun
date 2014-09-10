#pragma once
#include "WorldObject.h"
#include "Ball.h"

/*! \brief
* A corner between two road ajacent pieces with different rotations
*/
class Corner
{
	bool left; /** <Check whether the ball can move left */
	bool right;/** <Check whether the ball can move right */
	Point3D point; /** <The point of the corner */
	GLfloat radius; /** <The corner's radius */
public:
	Corner(Point3D point, bool left, bool right, GLfloat radius = 8.0);
	~Corner();

	/**Checks if the ball can be moved to the left */
	bool CanMoveLeft(Ball* ball);
	/**Checks if the ball can be moved to the right */
	bool CanMoveRight(Ball* ball);

	Point3D GetPoint();
	GLfloat GetRadius();
};
