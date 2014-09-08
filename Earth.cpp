#include "Earth.h"

void Earth::DrawObject() {
    glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[2]);
    glBegin(GL_QUADS);
		glTexCoord2f(0, 100); glVertex3f(-1000, -0.1,  1000.0);
        glTexCoord2f(100, 100); glVertex3f( 1000, -0.1,  1000.0);
        glTexCoord2f(100, 0); glVertex3f( 1000, -0.1, -1000.0);
        glTexCoord2f(0, 0); glVertex3f(-1000, -0.1, -1000.0);
    glEnd();
}