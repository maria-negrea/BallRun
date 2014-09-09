#include "EndScreen.h"

EndScreen::EndScreen()
{
}

EndScreen::~EndScreen()
{
}

void EndScreen::DrawObject() {
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[8]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(-6.0, 0.0, -10.0);
		glTexCoord2f(1, 0); glVertex3f( 6.0, 0.0, -10.0);
		glTexCoord2f(1, 1); glVertex3f( 6.0, 5.0, -10.0);
		glTexCoord2f(0, 1); glVertex3f(-6.0, 5.0, -10.0);
	glEnd();

}
