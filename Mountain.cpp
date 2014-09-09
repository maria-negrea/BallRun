#include "Mountain.h"
#include<vector>
#include<math.h>
#include<algorithm>

Mountain::Mountain()
{}

Mountain::Mountain(GLfloat width, GLfloat height, GLfloat inaltime)
{
this->width=width;
this->height=height;
this->inaltime=inaltime;
}

Mountain::~Mountain(void)
{
}
void Mountain::DrawObject()
{

    std::vector<Point3D> base;
	std::vector<Point3D> top;
	std::vector<Point3D> thingsbase;
	std::vector<Point3D>thingstop;

	

	 base.push_back(Point3D(0.1*width,0,0.8*height));
    base.push_back(Point3D(0.2*width,0,0.7*height));
 base.push_back(Point3D(0.3*width,0,0.6*height));
    base.push_back(Point3D(0.5*width,0,0.3*height));
    base.push_back(Point3D(0.8*width,0,0.3*height));
 base.push_back(Point3D(0.4*width,0.0, -0.6*height));
 base.push_back(Point3D(-0.19*width,0.0, -0.8*height));
 base.push_back(Point3D(-0.2*width,0.0, -0.7*height));
 base.push_back(Point3D(-0.7*width, 0.0, -0.1*height));
 base.push_back(Point3D(-0.8*width,0.0,0.2*height));
 base.push_back(Point3D(-0.6*width,0.0,0.3*height));
 base.push_back(Point3D(-0.36*width,0.0, 0.35*height));
 base.push_back(Point3D(0.1*width,0.0,0.8*height));


 top.push_back(Point3D(0.1*width,inaltime,0.3*height));
    top.push_back(Point3D(0.15*width,inaltime,0.27*height));
 top.push_back(Point3D(0.1*width,inaltime,0.2*height));
    top.push_back(Point3D(0.2*width,inaltime,0.15*height));
    top.push_back(Point3D( 0.5*width,inaltime,0.1*height));
    top.push_back(Point3D(0.2*width, inaltime, -0.1*height));
 top.push_back(Point3D(-0.1*width, inaltime, -0.2*height));
 top.push_back(Point3D(-0.15*width,inaltime,-0.15*height));
 top.push_back(Point3D(-0.3*width,inaltime, -0.08*height));
 top.push_back(Point3D(-0.4*width,inaltime,0.18*height));
 top.push_back(Point3D(-0.2*width,inaltime,0.23*height));
 top.push_back(Point3D(-0.1*width,inaltime,0.3*height));
 top.push_back(Point3D(0.1*width,inaltime,0.3*height));
 

 thingsbase.push_back(Point3D(0.4*width,0, 0.92*height));
 thingsbase.push_back(Point3D(0.3*width,0, height));
 thingsbase.push_back(Point3D(-0.15*width,0,0.95*height));
 thingsbase.push_back(Point3D(-0.2*width, 0, 0.86*height));
 thingsbase.push_back(Point3D(-0.16*width,0, 0.4*height));
 thingsbase.push_back(Point3D(-0.2*width, 0, 0.3*height));


 thingsbase.push_back(Point3D(-0.1*width, 0, 0.4*height));
 thingsbase.push_back(Point3D(0.1*width, 0, 0.8*height));
 thingsbase.push_back(Point3D(0.2*width, 0, 0.866*height));
 thingsbase.push_back(Point3D(0.4*width,0, 0.92*height));

 GLfloat inaltime2=inaltime*0.7;

 thingstop.push_back(Point3D(0.2*width,inaltime2, 0.9*height));
 thingstop.push_back(Point3D(0.07*width, inaltime2, 0.91*height));
 thingstop.push_back(Point3D(-0.1*width, inaltime2, 0.83*height));
 thingstop.push_back(Point3D(-0.11*width, inaltime2, 0.83*height));
 thingstop.push_back(Point3D(-0.09*width, inaltime2, 0.5*height));
 thingstop.push_back(Point3D(-0.1*width, inaltime2, 0.6*height));

 thingstop.push_back(Point3D(-0.08*width, inaltime2, 0.5*height));
 thingstop.push_back(Point3D(0.09*width, inaltime2, 0.84*height));
 thingstop.push_back(Point3D(0.11*width, inaltime2, 0.85*height));
 thingstop.push_back(Point3D(0.2*width,inaltime2, 0.9*height));





double step=1./base.size();	
double j=0;

 glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[3]);
for(double i=0;i<base.size()-1;i++)
{
	glBegin(GL_QUADS);
				glTexCoord2f(j, 0.0f); glVertex3f(base[i].x, base[i].y, base[i].z);				
				glTexCoord2f(j, 1.0f); glVertex3f(top[i].x, top[i].y, top[i].z);
				glTexCoord2f((j+step), 1.0f); glVertex3f(top[i+1].x, top[i+1].y, top[i+1].z);
				glTexCoord2f((j+step),0.0f);   glVertex3f(base[i+1].x, base[i+1].y, base[i+1].z);
	glEnd();

			

			j+=step;

}

for(double k=1;k<top.size()-2;k++)
{
	glBegin(GL_TRIANGLES);
        glTexCoord2d(0.5,0.5);
		glVertex3f(top[0].x, top[0].y, top[0].z);
		glTexCoord2d(0.7,0.5);
		glVertex3f(top[k].x, top[k].y, top[k].z);
		glTexCoord2d(0.6, 0.7);
		glVertex3f(top[k+1].x, top[k+1].y, top[k+1].z);
	glEnd();

}

j=0;
for(double i=0;i<thingsbase.size()-1;i++)
{
	glBegin(GL_QUADS);
				glTexCoord2f(j, 0.0f); glVertex3f(thingsbase[i].x, thingsbase[i].y, thingsbase[i].z);				
				glTexCoord2f(j, 1.0f); glVertex3f(thingstop[i].x, thingstop[i].y, thingstop[i].z);
				glTexCoord2f((j+step), 1.0f); glVertex3f(thingstop[i+1].x, thingstop[i+1].y, thingstop[i+1].z);
				glTexCoord2f((j+step),0.0f);   glVertex3f(thingsbase[i+1].x, thingsbase[i+1].y, thingsbase[i+1].z);
	glEnd();

			

			j+=step;

}

for(double k=1;k<thingstop.size()-2;k++)
{
	glBegin(GL_TRIANGLES);
        glTexCoord2d(0.5,0.5);
		glVertex3f(thingstop[0].x, thingstop[0].y, thingstop[0].z);
		glTexCoord2d(0.7,0.5);
		glVertex3f(thingstop[k].x, thingstop[k].y, thingstop[k].z);
		glTexCoord2d(0.6, 0.7);
		glVertex3f(thingstop[k+1].x, thingstop[k+1].y, thingstop[k+1].z);
	glEnd();

}
}