#pragma once
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

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
	WorldObject(GLfloat X = 0.0, GLfloat Y = 0.0, GLfloat Z = 0.0, GLfloat W = 0.0, GLfloat H = 0.0);
	~WorldObject();

	void Translate(Point3D);
	void Rotate(Point3D);

	void Draw();

	Point3D GetTranslate();
};
