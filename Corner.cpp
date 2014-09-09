#include<iostream>
using namespace std;

#include "Corner.h"

Corner::Corner(Point3D point, bool left, bool right, GLfloat radius)
	:point(point),radius(radius),left(left),right(right)
{
	
}

Corner::~Corner()
{

}

bool Corner::CanMoveLeft(Ball *ball)
{
	if(!left)
		return false;
	return (point - ball->GetTranslate()).Magnitude() < radius;
}

bool Corner::CanMoveRight(Ball *ball)
{
	if(!right)
		return false;
	return (point - ball->GetTranslate()).Magnitude() < radius;
}

Point3D Corner::GetPoint()
{
	return point;
}

GLfloat Corner::GetRadius()
{
	return radius;
}