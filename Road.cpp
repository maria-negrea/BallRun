#include "Road.h"
#include <time.h>


void Road::DrawObject()
{
    glBegin(GL_QUADS);
        glVertex3f(-1, -1.0,  5.0);
        glVertex3f( 1, -1.0,  5.0);
        glVertex3f( 1, -1.0, -5.0);
        glVertex3f(-1, -1.0, -5.0);
    glEnd();
}

Point3D Road::GetEndPoint() {
    return GetForward()*5 + translate;
}