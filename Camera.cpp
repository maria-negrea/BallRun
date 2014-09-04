#include "Camera.h"

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
}