#pragma once
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

struct Point3D
{
	GLfloat x,y,z;

	Point3D(GLfloat X = 0.0, GLfloat Y = 0.0, GLfloat Z = 0.0):
	x(X), y(Y), z(Z)
	{}

};

class WorldObject
{
protected:
	virtual void DrawObject() = 0;
	Point3D rotate;
	Point3D translate;
	GLfloat width, height;
public:
	WorldObject(GLfloat X = 0.0, GLfloat Y = 0.0, GLfloat Z = 0.0, GLfloat W = 0.0, GLfloat H = 0.0);
	~WorldObject();

	void Draw();
};
