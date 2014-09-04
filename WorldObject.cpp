#include "WorldObject.h"

WorldObject::WorldObject(GLfloat X, GLfloat Y, GLfloat Z, GLfloat W, GLfloat H)
{
    translate = Point3D(X, Y, Z);
    width = W;
    height = H;
}

WorldObject::~WorldObject(void)
{
}

void WorldObject::Draw()
{
	glLoadIdentity();
	
	glTranslatef(translate.x,translate.y,translate.z - 1);
	
	glRotatef(rotate.x,1,0,0);
	glRotatef(rotate.y,0,1,0);
	glRotatef(rotate.z,0,0,1);

	DrawObject();

	glLoadIdentity();
}


void WorldObject::Translate(Point3D translation)
{
	translate += translation;
}

void WorldObject::Rotate(Point3D rotation)
{
	rotate += rotation;
}