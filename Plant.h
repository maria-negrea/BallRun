#pragma once
#include "Textures.h"
#include "WorldObject.h"
#include<vector>
#include<math.h>
#include<ctime>
#define PI 3.14

/*! \brief
 * Abstract class, indicates the way a branch will be drawn.
 */

class Plant:public WorldObject
{
protected:
	 /*!
    * The radius of the base of the plant
    */
	GLfloat radius;
	 /*!
    * The maximum height of the stem
    */
	GLfloat maxHeight;
	 /*!
    * A vector GLfloat that stores the angles for the rotation around the Y axis for each branch
    */
	vector<GLfloat> anglesY;
	 /*!
    * A vector that stores the angles for the rotation around the Z axis for each branch
    */
	vector<GLfloat> anglesZ;
	/*!
    * A vector that stores the radius of the base of each branch
    */
	vector<GLfloat> branchesRadius;
	/*!
    * A vector that stores the directions of each branch(left:1, right:2)
    */
	vector<int> directions;
	/*!
    * A vector that stores the maximum heights of each branch
    */
	vector<GLfloat> heights;
	/*!
    * The total number of branches
    */
	int numberOfBranches;
	/*!
    * Plant's index in textures vector
    */
	int textureIndex;
	/*!
    * A value that indicates the levels of branches(1-st level: the stem, 2-level: the branches, 3-level: the branches of the branches)
    */
	int level;

public:
	Plant(double width, double height, int numberOfBranches, int level);
	~Plant(void);
	void DrawObject();
	void DrawBranch(vector<Point3D>base, GLfloat radius, int currentLevel);
	void PutTextureOnCylinder(vector<Point3D> base, vector<Point3D> top);
	virtual void SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index)=0;
	virtual void SetInitialPass(GLfloat& pass, GLfloat radius)=0;
	virtual void IncrementPass(GLfloat& pass, GLfloat radius)=0;
	friend GLfloat GetRandomGLfloat(GLfloat min, GLfloat max);
};