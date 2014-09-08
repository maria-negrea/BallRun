#pragma once
#include "Plant.h"

class Cactus: public Plant
{
public:
	Cactus(double width, double height, int numberOfBranches);
	void DrawBranch(vector<Point3D>base, GLfloat radius, int level);
	void SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int level, GLfloat radius, GLfloat pass, GLfloat index);
	~Cactus(void);
};
