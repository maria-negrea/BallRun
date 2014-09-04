#include "Ball.h"

Ball::Ball(GLfloat X, GLfloat Y, GLfloat Z, GLfloat radius) 
	:WorldObject(X,Y,Z,radius*2,radius*2)
{
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[0]);
	gluQuadricTexture(quadratic, GL_TRUE);
}

Ball::~Ball(void)
{
	//delete[] quadratic;
}

void Ball::DrawObject()
{
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	gluSphere(quadratic,0.3f,100,100);
}
