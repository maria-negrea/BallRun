#pragma once
#include "Textures.h"
#include "WorldObject.h"
#include<vector>

class Plant:public WorldObject
{
public:
	Plant(void);
	Plant(double width, double height);

	~Plant(void);
	void DrawObject();
	void DrawBranch(vector<Point3D>base, GLfloat radius, int level);
};
