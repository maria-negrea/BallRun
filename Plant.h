#pragma once
#include "Textures.h"
#include "WorldObject.h"

class Plant:public WorldObject
{
private:
GLUquadricObj *quadratic;

public:
	Plant(void);
	~Plant(void);
	void DrawObject();
};
