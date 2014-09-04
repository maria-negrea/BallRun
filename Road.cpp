#include "Road.h"

void Road::DrawObject() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f( 0.0 , 255.0 , 255.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f( 0.5, -0.5, -0.5);
        glVertex3f( 0.5,  0.5, -0.5);
        glVertex3f(-0.5,  0.5, -0.5);
    glEnd();

}