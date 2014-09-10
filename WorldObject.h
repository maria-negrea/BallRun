#pragma once
#include <iostream>
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif
#include <math.h>
#include <vector>

using namespace std;

/*! @struct
*	A 3D point
*/
struct Point3D
{
	GLfloat x,y,z;

	/*!
	*	Constructs a 3D point
	*/
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

	Point3D operator/(GLfloat value)
	{
		return Point3D(x/value,y/value,z/value);
	}	

	GLfloat operator*(Point3D point)
	{
		return x*point.x+y*point.y+z*point.z;
	}

	/*! Distance from a point to the origin */
	GLfloat Magnitude()
	{
		return sqrt(x*x+y*y+z*z);
	}

	/*!Rotates a vector around the Y axis
		@param angle by wich the vector rotates
	*/
	Point3D rotateY(GLfloat angle)
	{
		GLfloat PI = 3.14159265359;
		return Point3D(x*cos(angle*PI/180) - z*sin(angle*PI/180), 0.0, x*sin(angle*PI/180) + z*cos(angle*PI/180));
	}

	/*!Returns a vector with the same direction as this vector but with a length of 1*/
	Point3D Normalize()
	{
		GLfloat magnitude = Magnitude();
		if(magnitude == 0)
			return Point3D(0,0,0);
		return (*this)/magnitude;
	}

	/*! Returns the angle between to vectors*/
	GLfloat AngleBetween(Point3D point)
	{
		GLfloat PI = 3.14159265359;

		GLfloat dotProduct = ((*this)*point);
		
		return acos(dotProduct/1.0)*180/PI;
	}
};

/*! A 3D object */
class WorldObject
{
protected:
	/*! Draws the object on the screen */
	virtual void DrawObject() = 0;
	/*! Changes the perspective to that of the object */
	void ModifyPerspective();
	/* Changes the perspective back to the world*/
	void ModifyPerspectiveBack();

	/*!< the rotation of the object*/
	Point3D rotate;
	/*!< the position of the object*/
	Point3D translate;
	/*! the width and height of the object*/
	GLfloat width, height;
public:
	WorldObject(GLfloat W = 0.0, GLfloat H = 0.0,GLfloat X = 0.0, GLfloat Y = 0.0, GLfloat Z = 0.0);
	~WorldObject();

	/*! Translates the object by a value
		* @param point the amount by wich the object is translated
	*/
	void Translate(Point3D point);
	/*! Rotates the object by a value
		* @param point the amount by wich the object is rotated
	*/
	void Rotate(Point3D point);

	void Draw();

	/*! Gets the forward direction of the object*/
	Point3D GetForward();

	/*! Gets the right direction of the object*/
	Point3D GetRight();

	Point3D GetTranslate();
	Point3D GetRotate();
};
