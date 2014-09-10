#include "EndScreen.h"

/*@class

* Draws the quad which appears when the game ends

*/

EndScreen::EndScreen()
{
}

EndScreen::~EndScreen()
{
}

/*!

* Draws a quad placed above the ball on OY axis with the "end game" texture

*/

void EndScreen::DrawObject() {
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[8]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(-6.0, 0.0, -10.0);
		glTexCoord2f(1, 0); glVertex3f( 6.0, 0.0, -10.0);
		glTexCoord2f(1, 1); glVertex3f( 6.0, 5.0, -10.0);
		glTexCoord2f(0, 1); glVertex3f(-6.0, 5.0, -10.0);
	glEnd();

}
