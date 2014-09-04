#include "Camera.h"
#include<iostream>

using namespace std;

Camera::Camera()
{
//	rotate.z = 180;
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

	//if(ball.GetDirection().z > 0)
	//{
	//	rotate.z = 0;
	//}
	//else
	//{
	//	rotate.z = 0;
	//}
	//if(ball.GetDirection().z == 0)
	//{
	//	if(ball.GetDirection().x > 0)
	//	{
	//		rotate.z = 0;
	//	}
	//	else
	//	{
	//		rotate.x = 270;
	//	}
	//}
	rotate.y = 360-Point3D(0,0,1).AngleBetween(ball.GetDirection());
	//cout<<rotate.y<<endl;
}