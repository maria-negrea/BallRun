#include "Plant.h"
#include<vector>
#include<math.h>
#define PI 3.14

using namespace std;

Plant::Plant(double width, double height)
{
	this->width=width;
	this->height=height;

}

Plant::~Plant(void)
{
}

void Plant:: DrawBranch(vector<Point3D> base, GLfloat radius, int level)
{
	if(level==3)
	{
		return;
	}
	
	vector<Point3D>top;
	
	
	double pass=radius/6, value=0.2;
	
	for(int i=0;i<5&&radius-pass>0;i++)
	{	
		for (double t = 0; t < 2 * PI; t = t + 0.1)
		{
			if(i%2==0)
			{
				top.push_back(Point3D(pass/4+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
			}
			else
			{
				top.push_back(Point3D(-pass/4+(radius-pass)*cos(t), base[0].y+value,  (radius-pass)*sin(t)));
			}
			
		}
		
		glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTexture()[0]);

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

		if(i%2==0)
		{
			glTranslatef(0,top[0].y,0);
			glRotatef(30.0, 0, 0, 1);
			glTranslatef(0,-top[0].y,0);
			DrawBranch(top,(radius-pass)/4, level+1);
			glTranslatef(0,top[0].y,0);
			glRotatef(-30.0, 0, 0, 1);
			glTranslatef(0,-top[0].y,0);
			cout<<"Branch"<<endl;

		}		
		value-=0.02;
		base.clear();
		base=top;
		top.clear();
		pass+=radius/6;
	}

}

void Plant::DrawObject()
{
	vector<Point3D>base; 
	GLfloat radius = (width >= height ? height : width)/6;
	for (double t = 0; t < 2 * PI; t = t + 0.1)
		{
			base.push_back(Point3D(radius*cos(t), 0.0,  radius*sin(t)));
		}


	DrawBranch(base, radius, 1);
	
}
