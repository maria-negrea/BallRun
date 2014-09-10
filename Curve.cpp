#include "Curve.h"
#include "Textures.h"


/*!
* Takes as argument the turn id :
* 0 -> right
* 1 -> left
* 2 -> both
*/
Curve::Curve(int TURN) :turn(TURN)
{
}

Curve::~Curve()
{
}

/*!
* draws a quadrant if the turn is 1 or two and a quad otherwise
*/
void Curve::DrawObject()
{
	double PI = 3.141;

	double step = 0.01;

		if(turn == 0) { 
			for(double t = 3*PI/2;t < 2*PI;t += step)
			{
				glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[1]);
				glBegin(GL_TRIANGLES);
					glTexCoord2f(1.0f, t*2/PI); glVertex3f(-2.0, 0.0, 2.0);
					glTexCoord2f(0.0f, t*2/PI); glVertex3f(4*cos(t)-2.0, 0.0, 4*sin(t)+2.0);
					glTexCoord2f(0.0f, (t+step)*2/PI); glVertex3f(4*cos(t+step)-2.0, 0.0, 4*sin(t+step)+2.0);
				glEnd();
			}
		} else if(turn == 1) {
			for(double t = PI;t < 3*PI/2;t += step)
			{
				glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[1]);
				glBegin(GL_TRIANGLES);
					glTexCoord2f(1.0f, t*2/PI); glVertex3f(-2.0, 0.0,+2.0);
					glTexCoord2f(0.0f, t*2/PI); glVertex3f(4*cos(t)-2, 0.0, 4*sin(t)+2);
					glTexCoord2f(0.0f, (t+step)*2/PI); glVertex3f(4*cos(t+step)-2, 0.0, 4*sin(t+step)+2);
				glEnd();
			}
		} else if(turn == 2) {
			glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[5]);
			glBegin(GL_QUADS);
				glTexCoord2f(0, 0);glVertex3f(-2, 0.0,   2.0);
				glTexCoord2f(1, 0); glVertex3f( 2, 0.0,  2.0);
				glTexCoord2f(1, 1); glVertex3f( 2, 0.0, -2.0);
				glTexCoord2f(0, 1); glVertex3f(-2, 0.0, -2.0);
			glEnd();
		}	
}