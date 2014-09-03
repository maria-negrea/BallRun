#include "WorldObject.h"

WorldObject::WorldObject(void)
{
}

WorldObject::~WorldObject(void)
{
}

void WorldObject::Draw()
{
	glLoadIdentity();
	
	glTranslatef(translate.x,translate.y,translate.z);
	
	glRotatef(rotate.x,1,0,0);
	glRotatef(rotate.y,0,1,0);
	glRotatef(rotate.z,0,0,1);

	DrawObject();

	glLoadIdentity();
}