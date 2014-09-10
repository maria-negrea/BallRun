#include "Cactus.h"

/*!
* @param width double -- The width of the surface 
* @param height double -- The height of the surface
* @param numberOfBranches int -- The number of branches
* @param level int -- The levels of branches
*/
Cactus::Cactus(double width, double height, int numberOfBranches, int level)
:Plant(width, height, numberOfBranches, level)
{
	/*!
*	Initializes the texture index.
*	Generates a random value for the maximum height.
*	Generates random values for directions, each branch's radius and angles for the rotations around Y and Z axis.
*	Calculate the maximum height for the current branch.
*	Generates the maximum heights for each branch.
*/
	textureIndex=7;
	this->maxHeight=GetRandomGLfloat(2.0, 3.0);
	for(int i=0;i<numberOfBranches;i++)
	{
		directions.push_back(rand()%2+1);
		int currentHeight=maxHeight-i*maxHeight/numberOfBranches;
		heights.push_back(GetRandomGLfloat(currentHeight-currentHeight/2, currentHeight));
		anglesY.push_back(GetRandomGLfloat(0.0, 360.0));
		anglesZ.push_back(GetRandomGLfloat(10.0, 60.0));
		branchesRadius.push_back(GetRandomGLfloat(this->radius/2, this->radius));
	}
}

/*!
* Initializes a vector of top points using a given base, its radius and a pass.
* @param base vector<Point3D>  -- A vector that stores the points of the base of the branch 
* @param top vector<Point3D>  -- A vector that will be initialized with the points of the top of the branch
* @param currentLevel int -- The current level of branches
* @param radius GLfloat -- The radius of the base
* @param pass GLfloat -- The difference between the radius of the base and the radius of the top
* @param index GLfloat -- The index of the branch
*/
void Cactus:: SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index)
{
	double value;
	/*!
	*	Calculates the difference between each top and base.
	*/
	if(currentLevel==1)
	{
		value=maxHeight/numberOfBranches;
	}
	else
	{
		value=heights[index]/numberOfBranches;
	}
	
	/*!
	*	Sets the difference on the X axis for the first half of branches.
	*/
	int xDir=0.0;
	if(index<numberOfBranches/2+1)
	{
		xDir+=0.8;
	}
	else
	{
		xDir=0.0;
		
	}
	/*!
	*	Increments the current radius so that each top's radius will be bigger than the previous one.
	*/
	radius+=pass;
	for (double t = 0; t < 2 * PI; t = t + 1.5)
	{
		/*!
		*	Initializes the top points on the left/right side according to the corresponding direction(1-left, 2-right).
		*/
		switch(directions[index])
		{
			case 1:
				{
					/*!
					*	If the current branch is the stem(currentLevel=1), the radius of the top will not be bigger than
					*	the base.Otherwise, the radius of the top will be bigger than the base.
					*/
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

/*!
* Initializes the difference between top's and base's radius.
* @param radius GLfloat -- The radius of the base
* @param pass GLfloat -- The difference between the radius of the base and the radius of the top
*/
void Cactus::SetInitialPass(GLfloat& pass, GLfloat radius)
{
	pass=radius/20;
}

/*!
* Sets the value for incrementing the pass.
*/
void Cactus::IncrementPass(GLfloat& pass, GLfloat radius)
{
}

Cactus::~Cactus(void)
{
}
