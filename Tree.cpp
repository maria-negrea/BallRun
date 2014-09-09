#include "Tree.h"

using namespace std;

Tree::Tree(double width, double height, int numberOfBranches, int level)
:Plant(width, height, numberOfBranches, level)
{
	textureIndex=6;
	for(int i=0;i<numberOfBranches;i++)
	{
		anglesY.push_back(GetRandomGLfloat(0.0, 360.0));
		anglesZ.push_back(GetRandomGLfloat(10.0, 60.0));
		branchesRadius.push_back(GetRandomGLfloat(this->radius/4, this->radius/2));
	}
}

Tree::~Tree(void)
{
}

void Tree:: SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index)
{
	double value=heights[index]/numberOfBranches;
	int randomValue=directions[index];
		for (double t = 0; t < 2 * PI; t = t + 1.5)
		{			
			switch(randomValue)
			{
				case 1:
					{
						top.push_back(Point3D(pass/2+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
						break;
					}
				case 2:
					{
						top.push_back(Point3D(-pass/2+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
						break;
					}
			}			
		}
}




void Tree::SetInitialPass(GLfloat& pass, GLfloat radius)
{
	pass=radius/6;
}

void Tree::IncrementPass(GLfloat& pass, GLfloat radius)
{
	pass+=radius/6;
}

