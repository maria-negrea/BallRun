#pragma once
#include <glut.h>

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

	void operator +=(Point3D point)
	{
		*this = *this+point;
	}
};

class WorldObject
{
protected:
	virtual void DrawObject() = 0;
private:
	Point3D rotate;
	Point3D translate;
public:
	WorldObject();
	~WorldObject();

	void Translate(Point3D);
	void Rotate(Point3D);

	void Draw();
};
