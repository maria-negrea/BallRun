#include "Digit.h"
#include "Textures.h"

Digit::Digit(int digit)
	:digit(digit)
{
}

Digit::~Digit(void)
{
}

void Digit::DrawObject()
{
	int digitPlus = digit+1;
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[9]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.1*digit, 0); glVertex3f(-1.0, -1.5, 0.0);
		glTexCoord2f(0.1*digitPlus, 0); glVertex3f( 1.0, -1.5, 0.0);
		glTexCoord2f(0.1*digitPlus, 1); glVertex3f( 1.0, 1.5, 0.0);
		glTexCoord2f(0.1*digit, 1); glVertex3f(-1.0, 1.5, 0.0);
	glEnd();	
}

void Digit::Follow(Ball* ball,Point3D followPoint)
{
	this->ball = ball;
	this->followPoint = followPoint;
}

void Digit::Update()
{
	if(ball != NULL)
	{
		translate = ball->GetTranslate();
		translate += ball->GetDirection()*-followPoint.x+ball->GetDirection().rotateY(90)*-followPoint.z;
		translate.y = followPoint.y;

		rotate.y = ball->GetRotate().y;
	}
}

void Digit::SetDigit(double digit)
{
	this->digit = (int)digit%10;
}