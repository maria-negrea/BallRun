#include "Tree.h"

using namespace std;

/*!
* @param width double -- The width of the surface 
* @param height double -- The height of the surface
* @param numberOfBranches int -- The number of branches
* @param level int -- The levels of branches
*/
Tree::Tree(double width, double height, int numberOfBranches, int level)
:Plant(width, height, numberOfBranches, level)
{
	/*!
*	Initializes the texture index.
*	Generates a random value for the maximum height.
*	Generates random values for directions, each branch's radius and angles for the rotations around Y and Z axis.
*	Calculate the maximum height for the current branch.
*	Generates the maximum heights for each branch.
*/
	textureIndex=6;
	this->maxHeight=GetRandomGLfloat(2.0, 3.0);
	for(int i=0;i<numberOfBranches;i++)
	{
		directions.push_back(rand()%2+1);
		int currentHeight=maxHeight-i*maxHeight/numberOfBranches;
		heights.push_back(GetRandomGLfloat(currentHeight-currentHeight/2, currentHeight));
		anglesY.push_back(GetRandomGLfloat(0.0, 360.0));
		anglesZ.push_back(GetRandomGLfloat(10.0, 60.0));
		branchesRadius.push_back(GetRandomGLfloat(this->radius/4, this->radius/2));
	}
}

Tree::~Tree(void)
{
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
void Tree:: SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index)
{
	/*!
	*	Calculates the difference between each top and base.
	*/
	double value=heights[index]/numberOfBranches;
	for (double t = 0; t < 2 * PI; t = t + 1.5)
	{
		/*!
		*	Initializes the top points on the left/right side according to the corresponding direction(1-left, 2-right).
		*	The radius of the top will be smaller than the radius of the base.
		*/
		switch(directions[index])
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

/*!
* Initializes the difference between top's and base's radius.
* @param radius GLfloat -- The radius of the base
* @param pass GLfloat -- The difference between the radius of the base and the radius of the top
*/
void Tree::SetInitialPass(GLfloat& pass, GLfloat radius)
{
	pass=radius/6;
}

/*!
* Sets the value for incrementing the pass.
*/
void Tree::IncrementPass(GLfloat& pass, GLfloat radius)
{
	pass+=radius/6;
}

