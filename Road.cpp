#include "Road.h"
#include <time.h>


void Road::DrawObject()
{
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTexture()[0]);

    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-2, 0.0,  20.0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 2, 0.0,  20.0);
        glTexCoord2f(0.0f, 5.0f); glVertex3f( 2, 0.0, -20.0);
        glTexCoord2f(1.0f, 5.0f); glVertex3f(-2, 0.0, -20.0);
    glEnd();
}

Point3D Road::GetEndPoint() 
{
    return GetForward()*5 + translate;
}