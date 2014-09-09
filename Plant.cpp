#include "Plant.h"


using namespace std;

Plant::Plant(double width, double height, int numberOfBranches, int level)
{
	this->width=width;
	this->height=height;
	this->numberOfBranches=numberOfBranches;
	this->level=level;
	this->maxHeight=GetRandomGLfloat(2.0, 3.0);
	
	double minDimension=width >= height ? height : width;	
	this->radius = GetRandomGLfloat(minDimension/8, minDimension/4);
	for(int i=0;i<numberOfBranches;i++)
	{
		directions.push_back(rand()%2+1);
		int currentIndex=maxHeight-i*maxHeight/numberOfBranches;
		heights.push_back(GetRandomGLfloat(currentIndex-currentIndex/2, currentIndex));
	}

}

Plant::~Plant(void)
{
}

void Plant:: PutTextureOnCylinder(vector<Point3D> base, vector<Point3D> top)
{
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[textureIndex]);
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

void Plant:: DrawBranch(vector<Point3D> base, GLfloat radius, int currentLevel)
{
	if(currentLevel==level)
	{
		return;
	}
	
	vector<Point3D>top;	
	GLfloat pass;
	SetInitialPass(pass, radius);
	
	for(int i=0;i<numberOfBranches && radius-pass>0;i++)
	{
		SetBranchTop(base, top, currentLevel, radius, pass, i);		
		PutTextureOnCylinder(base, top);

		if(i<3)
		{
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(this->anglesY[i], 0, 1, 0);
				glRotatef(this->anglesZ[i], 0, 0, 1);
				glTranslatef(0,-top[0].y,0);

			}
			
			DrawBranch(top, branchesRadius[i], currentLevel+1);
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(-this->anglesZ[i], 0, 0, 1);
				glRotatef(-this->anglesY[i], 0, 1, 0);
				glTranslatef(0,-top[0].y,0);
			}

		}

		if(i<3)
		{
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(360-this->anglesY[i], 0, 1, 0);
				glRotatef(60-this->anglesZ[i], 0, 0, 1);
				glTranslatef(0,-top[0].y,0);

			}
			
			DrawBranch(top,branchesRadius[i], currentLevel+1);
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(-60+this->anglesZ[i], 0, 0, 1);
				glRotatef(-360+this->anglesY[i], 0, 1, 0);
				glTranslatef(0,-top[0].y,0);
			}

		}

		base.clear();
		base=top;
		top.clear();
		IncrementPass(pass, radius);
	}
}

void Plant::DrawObject()
{
	vector<Point3D>base; 
	
	for (double t = 0; t < 2 * PI; t = t + 1.5)
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
