#include "WorldObject.h"

WorldObject::WorldObject(void)
{
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

	glRotatef(rotate.x,1,0,0);
	glRotatef(rotate.y,0,1,0);
	glRotatef(rotate.z,0,0,1);
}


void WorldObject::ModifyPerspectiveBack()
{
	glRotatef(-rotate.z,0,0,1);
	glRotatef(-rotate.y,0,1,0);
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