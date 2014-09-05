#include "Road.h"
#include <time.h>


void Road::DrawObject()
{
    glColor4f( 0.0 , 1.0 , 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(-1, 0.0,  5.0);
        glVertex3f( 1, 0.0,  5.0);
        glVertex3f( 1, 0.0, -5.0);
        glVertex3f(-1, 0.0, -5.0);
    glEnd();
}

Point3D Road::GetEndPoint() {
    return GetForward()*5 + translate;
}