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
	translate.z = ball.GetTranslate().z+ball.GetDirection().z*5;
	translate.y = 1.5;
}