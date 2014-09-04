#include "Plant.h"

Plant::Plant(void)
{
	quadratic = gluNewQuadric();

	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	Textures q;
	q.LoadGLTextures();

	glBindTexture(GL_TEXTURE_2D, q.GetTextures()[0]);
	gluQuadricTexture(quadratic, GL_TRUE);

}

Plant::~Plant(void)
{
}
void Plant::DrawObject()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(120,1,0,0);

	gluCylinder(quadratic, 0.2,0.3,0.5,100,100);

	glFlush();
}
