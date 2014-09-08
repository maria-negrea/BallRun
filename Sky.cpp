#include "Sky.h"
#include "Textures.h"

Sky::Sky(GLfloat size)
:size(size)
{
}

Sky::~Sky(void)
{
}

void Sky::DrawObject()
{
    glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[3]);
    glBegin(GL_QUADS);
		glTexCoord2f(0.5, 0); glVertex3f(-size, -size/1.0,  size);//1
        glTexCoord2f(0.5, 0.33); glVertex3f( size, -size/1.0,  size);
        glTexCoord2f(0.25, 0.33); glVertex3f( size, -size/1.0, -size);
        glTexCoord2f(0.25, 0); glVertex3f(-size, -size/1.0, -size);

		glTexCoord2f(0.5, 0.33); glVertex3f( size, -size/1.0, size);//2
        glTexCoord2f(0.25, 0.33); glVertex3f( size, -size/1.0,  -size);
        glTexCoord2f(0.25, 0.66); glVertex3f( size, size/1.0, -size);
        glTexCoord2f(0.5, 0.66); glVertex3f( size, size/1.0, size);

		glTexCoord2f(0.25, 0.33); glVertex3f( size, -size/1.0, -size);//3
        glTexCoord2f(-0.0001, 0.33); glVertex3f( -size, -size/1.0, -size);
        glTexCoord2f(-0.0001, 0.66); glVertex3f( -size, size/1.0, -size);
        glTexCoord2f(0.25, 0.66); glVertex3f( size, size/1.0, -size);

		glTexCoord2f(1.0001, 0.33); glVertex3f( -size, -size/1.0, -size);//4
        glTexCoord2f(0.75, 0.33); glVertex3f( -size, -size/1.0,  size);
        glTexCoord2f(0.75, 0.66); glVertex3f( -size, size/1.0, size);
        glTexCoord2f(1.0001, 0.66); glVertex3f(-size, size/1.0, -size);

		glTexCoord2f(0.75, 0.33); glVertex3f( -size, -size/1.0, size);//5
        glTexCoord2f(0.5, 0.33); glVertex3f( size, -size/1.0,  size);
        glTexCoord2f(0.5, 0.66); glVertex3f( size, size/1.0, size);
        glTexCoord2f(0.75, 0.66); glVertex3f(-size, size/1.0, size);

		glTexCoord2f(0.5, 0.66); glVertex3f(-size, size/1.0,  size);//6
        glTexCoord2f(0.5, 1); glVertex3f( size, size/1.0,  size);
        glTexCoord2f(0.25, 1); glVertex3f( size, size/1.0, -size);
        glTexCoord2f(0.25, 0.66); glVertex3f(-size, size/1.0, -size);

    glEnd();
}

void Sky::Follow(Ball *ball)
{
	this->ball = ball;
}

void Sky::Update()
{
	if(ball != NULL)
	{
		translate = ball->GetTranslate();
	}
}

void Sky::UnFollow()
{
	ball = NULL;
}