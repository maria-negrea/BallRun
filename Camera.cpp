#include "Camera.h"
#include<iostream>

using namespace std;

Camera::Camera()
{
}

Camera::~Camera()
{

}

void Camera::DrawObject()
{

}

void Camera::Perspective()
{
	ModifyPerspectiveBack();
}


void Camera::Follow(Ball* ball)
{
	this->ball = ball;
	direction = ball->GetDirection();
}

void Camera::Update()
{
	if(ball != NULL)
	{
		/** The camera fades a little behind the ball */
		Point3D gap = ball->GetDirection()-direction;

		direction = direction+gap*0.25;
		direction = direction.Normalize();

		translate = ball->GetTranslate()+direction*5;

		rotate.y = Point3D(0,0,1).AngleBetween(direction);
		if(direction.x < 0)
			rotate.y = 360-rotate.y;
	}
	translate.y = 1.5;
}

void Camera::UnFollow()
{
	ball = NULL;
}