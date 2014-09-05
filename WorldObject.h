#pragma once
#include <iostream>
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif
#include <math.h>

using namespace std;

struct Point3D
{
	GLfloat x,y,z;

	Point3D(GLfloat x=0,GLfloat y=0,GLfloat z=0):
	x(x), y(y), z(z)
	{}

	Point3D operator+(Point3D point)
	{
		return Point3D(x+point.x,y+point.y,z+point.z);
	}

	Point3D operator-(Point3D point)
	{
		return Point3D(x-point.x,y-point.y,z-point.z);
	}

	void operator +=(Point3D point)
	{
		*this = *this+point;
	}

	Point3D operator*(GLfloat value)
	{
		return Point3D(x*value,y*value,z*value);
	}

	GLfloat operator*(Point3D point)
	{
		return x*point.x+y*point.y+z*point.z;
	}

	GLfloat Magnitude()
	{
		return sqrt(x*x+y*y+z*z);
	}

	Point3D rotateY(GLfloat angle)
	{
		GLfloat PI = 3.14159265359;
		return Point3D(x*cos(angle*PI/180) - z*sin(angle*PI/180), 0.0, x*sin(angle*PI/180) + z*cos(angle*PI/180));
	}

	GLfloat AngleBetween(Point3D point)
	{
		GLfloat PI = 3.14159265359;

		GLfloat dotProduct = ((*this)*point);
		if(dotProduct == 0)
		{
			if(point.x > 0)
				return 270;
			else
				return 90;
		}

		return acos(Magnitude()*point.Magnitude()/dotProduct)*180/PI;
	}
};

class WorldObject
{
protected:
	virtual void DrawObject() = 0;
	void ModifyPerspective();
	void ModifyPerspectiveBack();

	Point3D rotate;
	Point3D translate;
	GLfloat width, height;
public:
	WorldObject(GLfloat W = 0.0, GLfloat H = 0.0,GLfloat X = 0.0, GLfloat Y = 0.0, GLfloat Z = 0.0);
	~WorldObject();

	void Translate(Point3D);
	void Rotate(Point3D);

	void Draw();

	Point3D GetForward();

	Point3D GetTranslate();

	Point3D GetRight();

	Point3D GetRotate();
};
