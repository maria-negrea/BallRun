#include "Ball.h"

Ball::Ball(Point3D initialDirection,double speed, GLfloat radius)
:direction(initialDirection),speed(speed),WorldObject(radius*2,radius*2)
{
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[0]);
	gluQuadricTexture(quadratic, GL_TRUE);
}

Ball::~Ball(void)
{
	//delete[] quadratic;
}

void Ball::DrawObject()
{
	gluSphere(quadratic,0.3f,100,100);
}

void Ball::MoveLeft()
{
	direction = Point3D(direction.z, 0, -direction.x);
}

void Ball::MoveRight()
{
	direction = Point3D(-direction.z, 0, direction.x);
}

Point3D Ball::GetDirection()
{
	return direction;
}

void Ball::MoveForward()
{
	Translate(direction*speed);

	Point3D rotate;
	rotate.x = direction.z;
	rotate.z = direction.x;

	Rotate(rotate*(-15));
}
