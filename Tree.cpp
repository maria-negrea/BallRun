#include "Tree.h"

using namespace std;

Tree::Tree(double width, double height, int numberOfBranches)
:Plant(width, height, numberOfBranches)
{

}

Tree::~Tree(void)
{
}

void Tree:: SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int level, GLfloat radius, GLfloat pass, GLfloat index)
{

	double value=0.2/level;
	int randomValue=directions[index];
		for (double t = 0; t < 2 * PI; t = t + 0.1)
		{
			
			switch(randomValue)
			{
				case 1:
					{
						top.push_back(Point3D(pass/2/randomValue+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
						break;
					}
				case 2:
					{
						top.push_back(Point3D(-pass/2/randomValue+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
						break;
					}
			}			
		}
}


void Tree:: DrawBranch(vector<Point3D> base, GLfloat radius, int level)
{
	if(level==3)
	{
		return;
	}
	
	vector<Point3D>top;	
	double pass=radius/6;
	
	for(int i=0;i<numberOfBranches && radius-pass>0;i++)
	{
		SetBranchTop(base, top, level, radius, pass, i);		
		PutTextureOnCylinder(base, top);

		if(i<3)
		{
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(this->angles[i], 0, 1, 1);
				glTranslatef(0,-top[0].y,0);

			}
			
			DrawBranch(top, branchesRadius[i], level+1);
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(-this->angles[i], 0, 1, 1);
				glTranslatef(0,-top[0].y,0);
			}

		}

		if(i<3)
		{
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(350.0, 0, 0, 1);
				glTranslatef(0,-top[0].y,0);

			}
			
			DrawBranch(top,branchesRadius[i], level+1);
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(-350.0, 0, 0, 1);
				glTranslatef(0,-top[0].y,0);
			}

		}

		base.clear();
		base=top;
		top.clear();
		pass+=radius/6;
	}
}

