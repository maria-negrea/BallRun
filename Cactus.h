#pragma once
#include "Plant.h"

/*! \brief
 * Derived from Plant class, indicates the pattern for creating each set of top points and the difference between 
 * each top's and base's radius.
 */
class Cactus: public Plant
{
public:
	Cactus(double width, double height, int numberOfBranches, int level);
	void SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index);
	void SetInitialPass(GLfloat& pass, GLfloat radius);
	void IncrementPass(GLfloat& pass, GLfloat radius);
	~Cactus(void);
};
