#include "Plant.h"


using namespace std;

/*!
* @param width double -- The width of the surface 
* @param height double -- The height of the surface
* @param numberOfBranches int -- The number of branches
* @param level int -- The levels of branches
*/
Plant::Plant(double width, double height, int numberOfBranches, int level)
{
	this->width=width;
	this->height=height;
	this->numberOfBranches=numberOfBranches;
	this->level=level;

	/*!
*	Calculate the minimum between height and width.
*	Generates a random value in [minDimension/8, minDimension/4] for the radius.
*/
	double minDimension=width >= height ? height : width;	
	this->radius = GetRandomGLfloat(minDimension/8, minDimension/4);

}
/*!
*	Plant's destructor
*/
Plant::~Plant(void)
{
}

/*!
* Puts a texture on a cylinder based on its base points and its top points
* @param base vector<Point3D> -- A vector that stores the points of the base of the cylinder
* @param top vector<Point3D> -- A vector that stores the points of the top of the cylinder
*/
void Plant:: PutTextureOnCylinder(vector<Point3D> base, vector<Point3D> top)
{
	glBindTexture(GL_TEXTURE_2D, Textures::GetInstance()->GetTextures()[textureIndex]);
	/*!
*	Calculate the distance between two pixels of the texture.
*/
	double step=1.0/base.size();
	int k;
	double j=0.0;

	for(k=0;k<base.size()-1;k++)
	{
		/*!
		*	Puts texture on each triangle based on each 2 points of the top and 1 point of the base.
		*/
		glBegin(GL_TRIANGLES);
			glTexCoord2f(j, 0.0f); glVertex3f(base[k].x, base[k].y, base[k].z);				
			glTexCoord2f(j, 1.0f); glVertex3f(top[k].x, top[k].y, top[k].z);
			glTexCoord2f(j+step, 1.0f); glVertex3f(top[k+1].x, top[k+1].y, top[k+1].z);
		glEnd();

		/*!
		*	Puts texture on the next triangle based on each 2 points of the base and 1 point of the top.
		*/
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

/*!
* @param base vector<Point3D> -- A vector that stores the points of the base of the branch
* @param radius GLfloat -- Base's radius of the branch
* @param currentLevel int -- The current level of branches
*/
void Plant:: DrawBranch(vector<Point3D> base, GLfloat radius, int currentLevel)
{
/*!
*	Checks if the current level is the last one.
*/
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

		/*!
		*	Draws the branch on the right side.
		*/
		if(i<3)
		{
			/*!
			*	Make rotations around the Y and Z axis with the corresponding angles for the current branch if
			*	the current branch is not the last one.
			*/
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(this->anglesY[i], 0, 1, 0);
				glRotatef(this->anglesZ[i], 0, 0, 1);
				glTranslatef(0,-top[0].y,0);

			}
			
			/*!
			*	Draws a branch of the current branch.
			*/
			DrawBranch(top, branchesRadius[i], currentLevel+1);
			/*!
			*	Make rotations around the Y and Z axis with the inverse angles of the previous rotation.
			*/
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(-this->anglesZ[i], 0, 0, 1);
				glRotatef(-this->anglesY[i], 0, 1, 0);
				glTranslatef(0,-top[0].y,0);
			}

		}

		/*!
		*	Draws the branch on the left side.
		*/
		if(i<3)
		{
			/*!
			*	Make rotations around the Y and Z axis with the opposite angles corresponding to the left branch.
			*/
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(360-this->anglesY[i], 0, 1, 0);
				glRotatef(60-this->anglesZ[i], 0, 0, 1);
				glTranslatef(0,-top[0].y,0);

			}
			
			/*!
			*	Draws a branch of the current branch.
			*/
			DrawBranch(top,branchesRadius[i], currentLevel+1);
			/*!
			*	Make rotations around the Y and Z axis with the opposite angles corresponding to the left branch.
			*/
			if(i!=base.size()-1)
			{
				glTranslatef(0,top[0].y,0);
				glRotatef(-60+this->anglesZ[i], 0, 0, 1);
				glRotatef(-360+this->anglesY[i], 0, 1, 0);
				glTranslatef(0,-top[0].y,0);
			}

		}

		/*!
		*	The base will be replaced by the top, the top will be generated after.
		*/
		base.clear();
		base=top;
		top.clear();
		IncrementPass(pass, radius);
	}
}

/*!
*	Draws all branches of the plant.
*/
void Plant::DrawObject()
{
	vector<Point3D>base; 

	/*!
	*	Generates the points of the initial base using the equation of an ellipse.
	*/	
	for (double t = 0; t < 2 * PI; t = t + 1.5)
		{
			base.push_back(Point3D(radius*cos(t), 0.0,  radius*sin(t)));
		}

	DrawBranch(base, radius, 1);
}

/*!
* @param min GLfloat -- The minimum value
* @param max GLfloat -- The maximum value
* Generates a random value in [min, max].
*/
GLfloat GetRandomGLfloat(GLfloat min, GLfloat max)
{
	GLfloat range = max - min;
	GLfloat num = range * (rand()%100)/100.0;
	return (num + min);

}
