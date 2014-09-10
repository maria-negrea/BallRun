#pragma once
#include "WorldObject.h"
#include "Textures.h"
class Earth : public WorldObject
{
	/*! Draws the Earth */
    void DrawObject();
public:
    Earth() {}
    ~Earth() {}
};