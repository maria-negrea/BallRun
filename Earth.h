#pragma once
#include "WorldObject.h"
#include "Textures.h"
class Earth : public WorldObject
{
public:
    Earth() {}
    ~Earth() {}
	
	/*! Draws the Earth */
    void DrawObject();
};