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


void Camera::Follow(Ball& ball)
{
	translate = ball.GetTranslate()+ball.GetDirection()*5;
	rotate.y = 360-Point3D(0,0,1).AngleBetween(ball.GetDirection());

	translate.y = 1.5;
}