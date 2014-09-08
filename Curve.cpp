#include "Curve.h"

Curve::Curve()
{
}

Curve::~Curve()
{
}

void Curve::Draw()
{
	double PI = 3.141;

	double step = 0.01;
    glBegin(GL_TRIANGLES);

		for(double t = 0;t< PI/2;t += step)
		{
			glTexCoord2f(1.0f, t*2/PI); glVertex3f(0.0, 0.0,0.0);
			glTexCoord2f(0.0f, t*2/PI); glVertex3f(4*cos(t), 0.0, 4*sin(t));
			glTexCoord2f(0.0f, (t+step)*2/PI); glVertex3f(4*cos(t+step), 0.0, 4*sin(t+step));
		}
    glEnd();
}