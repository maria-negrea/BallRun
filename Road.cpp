#include "Road.h"
#include <time.h>


void Road::DrawObject()
{
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[1]);

    glBegin(GL_QUADS);
	   glTexCoord2f(0, 0);glVertex3f(-2, 0.0,  20.0);
       glTexCoord2f(1, 0); glVertex3f( 2, 0.0,  20.0);
       glTexCoord2f(1, 1); glVertex3f( 2, 0.0, -20.0);
       glTexCoord2f(0, 1); glVertex3f(-2, 0.0, -20.0);
    glEnd();
}

Point3D Road::GetEndPoint()
{
    return GetForward()*20 + translate;
}