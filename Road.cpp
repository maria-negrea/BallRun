#include "Road.h"

void Road::DrawObject()
{
    glColor4f( 0.0 , 255.0 , 255.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(-1, -1.0, 3.2);
        glVertex3f( 1, -1.0, 3.2);
        glVertex3f( 1, -1.0, -15.0);
        glVertex3f(-1, -1.0, -15.0);
    glEnd();

	glBegin(GL_QUADS);
		glVertex3f(-100, -1.0, -15.0);
        glVertex3f( 100, -1.0, -15.0);
        glVertex3f( 100, -1.0, -17.0);
        glVertex3f(-100, -1.0, -17.0);
    glEnd();
}