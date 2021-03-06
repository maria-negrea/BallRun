#pragma once
#include "Plant.h"
#include<vector>
#include<math.h>
#include<ctime>
#define PI 3.14

/*! \brief
 * Derived from Plant class, indicates the pattern for creating each set of top points and the difference between 
 * each top's and base's radius.
 */
class Tree:public Plant
{

public:
	Tree(double width, double height, int numberOfBranches, int level);
	~Tree(void);
	void SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index);
	void SetInitialPass(GLfloat& pass, GLfloat radius);
	void IncrementPass(GLfloat& pass, GLfloat radius);
};