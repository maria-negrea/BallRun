#include "Earth.h"

/*!
* Draw quad large enough to always seem like there is an earth below the road
*/
void Earth::DrawObject() {

    glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[2]);

    glBegin(GL_QUADS);
		glTexCoord2f(0, 1000); glVertex3f(-10000, -0.03,  10000.0);
        glTexCoord2f(1000, 1000); glVertex3f( 10000, -0.03,  10000.0);
        glTexCoord2f(1000, 0); glVertex3f( 10000, -0.03, -10000.0);
        glTexCoord2f(0, 0); glVertex3f(-10000, -0.03, -10000.0);
    glEnd();
}