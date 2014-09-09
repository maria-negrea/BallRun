#pragma once
#include "Plant.h"

class Cactus: public Plant
{
public:
	Cactus(double width, double height, int numberOfBranches, int level);
	void SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int currentLevel, GLfloat radius, GLfloat pass, GLfloat index);
	void SetInitialPass(GLfloat& pass, GLfloat radius);
	void IncrementPass(GLfloat& pass, GLfloat radius);
	~Cactus(void);
};
