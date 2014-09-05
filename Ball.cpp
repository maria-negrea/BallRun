#include "Ball.h"

Ball::Ball(Point3D initialDirection,double speed, GLfloat radius)
:direction(initialDirection),speed(speed),radius(radius),WorldObject(radius*2,radius*2)
{
	Translate(Point3D(0,radius,0));
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	gluQuadricTexture(quadratic, GL_TRUE);
}

Ball::~Ball(void)
{
	delete quadratic;
}

void Ball::DrawObject()
{
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[0]);
	gluSphere(quadratic,radius,100,100);
}

void Ball::MoveLeft()
{
	direction = Point3D(direction.z, 0, -direction.x);
	Rotate(Point3D(0,90,0));
}

void Ball::MoveRight()
{
	direction = Point3D(-direction.z, 0, direction.x);
	Rotate(Point3D(0,-90,0));
}

Point3D Ball::GetDirection()
{
	return direction;
}

void Ball::MoveForward()
{
	Translate(direction*speed);

	Rotate(Point3D(-15,0,0));
}
