#include "Plant.h"
#include<vector>
#include<math.h>
#define PI 3.14

using namespace std;

Plant::Plant(double width, double height, Point3D center)
{
	this->center=center;

}

Plant::~Plant(void)
{
}
void Plant::DrawObject()
{
	vector<Point3D>base; 
	vector<Point3D>top;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glRotatef(0,1,0,0);
	glColor3f(0,1,0);
	//	glRotatef(90, 0, 1, 1);
		for (double t = 0; t < 2 * PI; t = t + 0.001)
		{
			glBegin(GL_LINE_STRIP);
			//glColor3f( 241/255.0 , 215/255.0, 166/255.0);
			glVertex3f( center.x+0.2*cos(t), center.y+0.2*sin(t),  center.z+0.);
			base.push_back(Point3D(center.x+0.2*cos(t), center.y+0.2*sin(t),  center.z+0.));			
			glVertex3f(center.x+0.0, center.y+0.0,  center.z+0.0);
			glEnd();

			glBegin(GL_LINE_STRIP);
			//glColor3f(255/255.0, 0/255.0, 0);
			glVertex3f(center.x+0.2*cos(t), center.y+0.2*sin(t)+0.5,  center.z+0.);
			top.push_back(Point3D(center.x+0.2*cos(t), center.y+0.2*sin(t)+0.5,  center.z+0.));
			//glColor4f(1, 0.4, 0.1, 0.6);
			glVertex3f(center.x+0.0, center.y+0.5,  center.z+0.0);
			glEnd();
		}

		//glColor3f(0,0,1);
		for(int i=0;i<base.size()-1;i++)
		{
			glBegin(GL_TRIANGLES);
				glVertex3f(base[i].x, base[i].y, base[i].z);
				glVertex3f(top[i].x, top[i].y, top[i].z);
				glVertex3f(top[i+1].x, top[i+1].y, top[i+1].z);
			glEnd();

			glBegin(GL_TRIANGLES);
				glVertex3f(top[i+1].x, top[i+1].y, top[i+1].z);
				glVertex3f(base[i+1].x, base[i+1].y, base[i+1].z);
				glVertex3f(base[i].x, base[i].y, base[i].z);
			glEnd();


		}
	

	glFlush();
}
