#include "Plant.h"


using namespace std;

Plant::Plant(double width, double height, int numberOfBranches)
{
	this->width=width;
	this->height=height;
	this->numberOfBranches=numberOfBranches;
	this->maxHeight=GetRandomGLfloat(6, 8);
	
	double minDimension=width >= height ? height : width;	
	this->radius = GetRandomGLfloat(minDimension/8, minDimension/4);
	for(int i=0;i<numberOfBranches;i++)
	{
		angles.push_back(GetRandomGLfloat(10.0, 60.0));
		branchesRadius.push_back(GetRandomGLfloat(this->radius/8, this->radius/4));
		directions.push_back(rand()%2+1);
		heights.push_back(GetRandomGLfloat(0.1, maxHeight));
	}

}

Plant::~Plant(void)
{
}

void Plant:: PutTextureOnCylinder(vector<Point3D> base, vector<Point3D> top)
{
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[3]);

	double step=1.0/base.size();
	int k;
	double j=0.0;

	for(k=0;k<base.size()-1;k++)
	{
		glBegin(GL_TRIANGLES);
			glTexCoord2f(j, 0.0f); glVertex3f(base[k].x, base[k].y, base[k].z);				
			glTexCoord2f(j, 1.0f); glVertex3f(top[k].x, top[k].y, top[k].z);
			glTexCoord2f(j+step, 1.0f); glVertex3f(top[k+1].x, top[k+1].y, top[k+1].z);
		glEnd();

		glBegin(GL_TRIANGLES);
			glTexCoord2f(j+step, 1.0f); glVertex3f(top[k+1].x, top[k+1].y, top[k+1].z);
			glTexCoord2f(j+step, 0.0f);  glVertex3f(base[k+1].x, base[k+1].y, base[k+1].z);
			glTexCoord2f(j, 0.0f); glVertex3f(base[k].x, base[k].y, base[k].z);
		glEnd();

		j+=step;
	}

	glBegin(GL_TRIANGLES);
			glTexCoord2f(j, 0.0f); glVertex3f(base[k-1].x, base[k-1].y, base[k-1].z);				
			glTexCoord2f(j, 1.0f); glVertex3f(top[k-1].x, top[k-1].y, top[k-1].z);
			glTexCoord2f(j+step, 1.0f); glVertex3f(top[0].x, top[0].y, top[0].z);
		glEnd();

		glBegin(GL_TRIANGLES);
			glTexCoord2f(j+step, 1.0f); glVertex3f(top[0].x, top[0].y, top[0].z);
			glTexCoord2f(j+step, 0.0f);  glVertex3f(base[0].x, base[0].y, base[0].z);
			glTexCoord2f(j, 0.0f); glVertex3f(base[k-1].x, base[k-1].y, base[k-1].z);
		glEnd();
}



void Plant::DrawObject()
{
	vector<Point3D>base; 
	
	for (double t = 0; t < 2 * PI; t = t + 0.5)
		{
			base.push_back(Point3D(radius*cos(t), 0.0,  radius*sin(t)));
		}

	DrawBranch(base, radius, 1);
}

GLfloat GetRandomGLfloat(GLfloat min, GLfloat max)
{
	GLfloat range = max - min;
	GLfloat num = range * (rand()%100)/100.0;
	return (num + min);

}
