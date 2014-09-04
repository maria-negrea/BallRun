#include "Plant.h"
#include<vector>
#include<math.h>
#define PI 3.14

using namespace std;

Plant::Plant()
{
	center.x=0.0;
	center.y=0.0;
	center.z=0.0;
}
Plant::Plant(double width, double height)
{
	center.x=0.0;
	center.y=0.0;
	center.z=0.0;
	this->width=width;
	this->height=height;

}

Plant::~Plant(void)
{
}
void Plant::DrawObject()
{
	vector<Point3D>base; 
	vector<Point3D>top;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat radius = (width >= height ? height : width)/6;

	//glRotatef(20, 1, 0, 0);
	for (double t = 0; t < 2 * PI; t = t + 0.001)
		{
			base.push_back(Point3D(center.x+radius*cos(t), 0.0,  center.z+radius*sin(t)));
		}

	double pass=radius/6, value=0.2;
	
	for(int i=0;i<5&&radius-pass>0;i++)
	{
		//glRotatef(20, 1, 0, 0);
		for (double t = 0; t < 2 * PI; t = t + 0.001)
		{
			if(i%2==0)
			{
				top.push_back(Point3D(pass/4+center.x+(radius-pass)*cos(t), base[0].y+value,  center.z+(radius-pass)*sin(t)));
			}
			else
			{
				top.push_back(Point3D(-pass/4+center.x+(radius-pass)*cos(t), base[0].y+value,  center.z+(radius-pass)*sin(t)));
			}
			
		}
		
		glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[0]);

		double step=1.0/base.size();
		int i;
		double j=0.0;

		for(i=0;i<base.size()-1;i++)
		{
			glBegin(GL_TRIANGLES);
				glTexCoord2f(j, 0.0f); glVertex3f(base[i].x, base[i].y, base[i].z);				
				glTexCoord2f(j, 1.0f); glVertex3f(top[i].x, top[i].y, top[i].z);
				glTexCoord2f(j+step, 1.0f); glVertex3f(top[i+1].x, top[i+1].y, top[i+1].z);
			glEnd();

			glBegin(GL_TRIANGLES);
				glTexCoord2f(j+step, 1.0f); glVertex3f(top[i+1].x, top[i+1].y, top[i+1].z);
				glTexCoord2f(j+step, 0.0f);  glVertex3f(base[i+1].x, base[i+1].y, base[i+1].z);
				glTexCoord2f(j, 0.0f); glVertex3f(base[i].x, base[i].y, base[i].z);
			glEnd();

			j+=step;

		}


		base.clear();
		base=top;
		top.clear();
		pass+=radius/6;
	   value-=0.02;

	}

	glFlush();
}
