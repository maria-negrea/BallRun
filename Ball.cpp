#include "Ball.h"

Ball::Ball()
{
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	Textures q;
	q.LoadGLTextures();

	glBindTexture(GL_TEXTURE_2D, q.GetTextures()[0]);
	gluQuadricTexture(quadratic, GL_TRUE);
}

Ball::~Ball(void)
{
	//delete[] quadratic;
}

void Ball::DrawObject()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	gluSphere(quadratic,0.3f,100,100);

	glFlush();
}
