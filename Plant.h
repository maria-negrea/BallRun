#pragma once
#include "Textures.h"
#include "WorldObject.h"

class Plant:public WorldObject
{
private:
	Point3D center;

public:
	Plant(void);
	Plant(double width, double height, Point3D center);

	~Plant(void);
	void DrawObject();
};
