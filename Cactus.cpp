#include "Cactus.h"

Cactus::Cactus(double width, double height, int numberOfBranches, int level)
:Plant(width, height, numberOfBranches, level)
{
	textureIndex=7;
	for(int i=0;i<numberOfBranches;i++)
	{
		anglesY.push_back(GetRandomGLfloat(0.0, 360.0));
		anglesZ.push_back(GetRandomGLfloat(10.0, 60.0));
		branchesRadius.push_back(GetRandomGLfloat(this->radius/2, this->radius));
	}
}

void Cactus:: SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index)
{
	double value;
	if(currentLevel==1)
	{
		value=maxHeight/numberOfBranches;
	}
	else
	{
		value=heights[index]/numberOfBranches;
	}
	
	int xDir=0.0;
	if(index<numberOfBranches/2+1)
	{
		xDir+=0.8;
	}
	else
	{
		xDir=0.0;
		
	}
	radius+=pass;
	for (double t = 0; t < 2 * PI; t = t + 1.5)
	{
		switch(directions[index])
		{
			case 1:
				{					
					if(currentLevel==1)
					{
						top.push_back(Point3D(pass/2+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
					}
					else
					{
						top.push_back(Point3D(xDir+pass/2+(radius+pass)*cos(t), base[0].y+value,  (radius+pass)*sin(t)));

					}					
					break;
				}
			case 2:
				{
					if(currentLevel==1)
					{
						top.push_back(Point3D(-pass/2+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
					}
					else
					{
						top.push_back(Point3D(xDir-pass/2+(radius+pass)*cos(t), base[0].y+value,  (radius+pass)*sin(t)));
					}
					
					break;
				}
		}			
	}
}



void Cactus::SetInitialPass(GLfloat& pass, GLfloat radius)
{
	pass=radius/20;
}

void Cactus::IncrementPass(GLfloat& pass, GLfloat radius)
{
}

Cactus::~Cactus(void)
{
}
