#pragma once
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

struct Point3D
{
	GLfloat x,y,z;

	Point3D():
	x(0), y(0), z(0)
	{}			
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

	void Draw();
};
