#include "WorldObject.h"

WorldObject::WorldObject(GLfloat W, GLfloat H,GLfloat X, GLfloat Y, GLfloat Z)
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
	ModifyPerspective();

	DrawObject();
	
	ModifyPerspectiveBack();
}

void WorldObject::ModifyPerspective()
{
	glTranslatef(translate.x,translate.y,translate.z);

	glRotatef(rotate.y,0,1,0);
	glRotatef(rotate.x,1,0,0);
	glRotatef(rotate.z,0,0,1);
}


void WorldObject::ModifyPerspectiveBack()
{
	glRotatef(-rotate.y,0,1,0);
	glRotatef(-rotate.z,0,0,1);
	glRotatef(-rotate.x,1,0,0);

	glTranslatef(-translate.x,-translate.y,-translate.z);
}


void WorldObject::Translate(Point3D translation)
{
	translate += translation;
}

void WorldObject::Rotate(Point3D rotation)
{
	rotate += rotation;
}

Point3D WorldObject::GetTranslate()
{
	return translate;
}