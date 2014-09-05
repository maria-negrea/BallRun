#include "Earth.h"

void Earth::DrawObject() {
    glColor4f( 128.0 / 255.0, 64.0 / 255.0 , 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(-1000, -0.1,  1000.0);
        glVertex3f( 1000, -0.1,  1000.0);
        glVertex3f( 1000, -0.1, -1000.0);
        glVertex3f(-1000, -0.1, -1000.0);
    glEnd();
}