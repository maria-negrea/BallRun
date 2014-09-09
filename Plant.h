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
	vector<GLfloat> anglesY;
	vector<GLfloat> anglesZ;
	vector<GLfloat> branchesRadius;
	vector<int> directions;
	vector<GLfloat> heights;
	int numberOfBranches;
	int textureIndex;
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