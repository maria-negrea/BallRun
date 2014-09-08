#pragma once
#include "Textures.h"
#include "WorldObject.h"
#include<vector>
#include<math.h>
#include<ctime>
#define PI 3.14

class Plant:public WorldObject
{
protected:
	GLfloat radius;
	GLfloat maxHeight;
	vector<GLfloat> angles;
	vector<GLfloat> branchesRadius;
	vector<int> directions;
	vector<GLfloat> heights;
	int numberOfBranches;

public:
	Plant(double width, double height, int numberOfBranches);
	~Plant(void);
	void DrawObject();
	virtual void DrawBranch(vector<Point3D>base, GLfloat radius, int level)=0;
	void PutTextureOnCylinder(vector<Point3D> base, vector<Point3D> top);
	virtual void SetBranchTop(vector<Point3D> base, vector<Point3D>& top, int level, GLfloat radius, GLfloat pass, GLfloat index)=0;
	friend GLfloat GetRandomGLfloat(GLfloat min, GLfloat max);
};