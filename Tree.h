#pragma once
#include "Plant.h"
#include<vector>
#include<math.h>
#include<ctime>
#define PI 3.14

class Tree:public Plant
{

public:
	Tree(double width, double height, int numberOfBranches);
	~Tree(void);
	void DrawBranch(vector<Point3D>base, GLfloat radius, int level);
	void SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int level, GLfloat radius, GLfloat pass, GLfloat index);
};