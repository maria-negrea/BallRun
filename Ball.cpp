#include "Ball.h"

Ball::Ball(Point3D initialDirection,double speed, GLfloat radius)
:direction(initialDirection),speed(speed),radius(radius),WorldObject(radius*2,radius*2)
{
	Translate(Point3D(0,radius,0));
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	gluQuadricTexture(quadratic, GL_TRUE);
	onTrack = Point3D(0,0,0);
}

Ball::~Ball(void)
{
	delete quadratic;
}

void Ball::DrawObject()
{
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[0]);
	gluSphere(quadratic,radius,100,100);

	//glEnable(GL_BLEND);
	//glBindTexture(GL_TEXTURE_2D,0);
	//glColor4f(0.5,0.5,0.5,0.5);
	//GLfloat PI = 3.141;
	//
	//glRotatef(-rotate.z,0,0,1);
	//glRotatef(-rotate.x,1,0,0);
	//glRotatef(-rotate.y,0,1,0);

	//glBegin(GL_TRIANGLE_FAN);
	//	glVertex3f(0.0,-0.3,0.0);
	//	for(GLfloat t = 0; t< PI*2 ; t +=0.1)
	//	{
	//		glVertex3f(cos(t)*radius,-radius,sin(t)*radius);			
	//	}
	//glEnd();

	//glColor4f(1.0,1.0,1.0,1.0);

	//glRotatef(rotate.y,0,1,0);
	//glRotatef(rotate.x,1,0,0);
	//glRotatef(rotate.z,0,0,1);
}

void Ball::MoveLeft(Point3D onTrack)
{
	direction = Point3D(direction.z, 0, -direction.x);
	Rotate(Point3D(0,90,0));
	this->onTrack = onTrack-translate;
	this->onTrack.y = 0;
}

void Ball::MoveRight(Point3D onTrack)
{
	direction = Point3D(-direction.z, 0, direction.x);
	Rotate(Point3D(0,-90,0));
	this->onTrack = onTrack-translate;
	this->onTrack.y = 0;
}

Point3D Ball::GetDirection()
{
	return direction;
}

void Ball::MoveForward()
{
	Translate(direction*speed);
	Translate(onTrack*0.5);

	onTrack = onTrack*0.5;

	Rotate(Point3D(15*speed,0,0));

	speed -= 0.001;
}
