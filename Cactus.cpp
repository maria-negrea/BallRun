#include "Cactus.h"

Cactus::Cactus(double width, double height, int numberOfBranches)
:Plant(width, height, numberOfBranches)
{
}

void Cactus:: SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int level, GLfloat radius, GLfloat pass, GLfloat index)
{
	double value=heights[index]/numberOfBranches;
	int xDir=0.0;
	if(index<2)
	{
		xDir+=0.2;
	}
	for (double t = 0; t < 2 * PI; t = t + 0.5)
	{
		switch(directions[index])
		{
			case 1:
				{
					if(level==1)
					{
						top.push_back(Point3D(base[0].x+xDir+pass/2/directions[index]+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
					}
					else
					{
						top.push_back(Point3D(base[0].x+xDir+pass/2/directions[index]+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));

					}					
					break;
				}
			case 2:
				{
					if(level==1)
					{
						top.push_back(Point3D(xDir-pass/2/directions[index]+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
					}
					else
					{
						top.push_back(Point3D(xDir-pass/2/directions[index]+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
					}
					
					break;
				}
		}			
	}
}

void Cactus:: DrawBranch(vector<Point3D> base, GLfloat radius, int level)
{
	if(level==3)
	{
		return;
	}

	vector<Point3D> top;	
	double pass=radius/20;
	
	for(int i=0;i<this->numberOfBranches && radius-pass>0;i++)
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

		//value-=0.02;
		base.clear();
		base=top;
		top.clear();
		/*pass+=radius/6;*/
		/*pass=GetRandomGLfloat(radius/4, radius);*/
	}

}

Cactus::~Cactus(void)
{
}
