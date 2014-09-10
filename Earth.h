#pragma once
#include "WorldObject.h"
#include "Textures.h"

/*! \brief
* Draws a quad with earth texture  
*/
class Earth : public WorldObject
{
	/*! Draws the Earth */
    void DrawObject();
public:
    Earth() {}
    ~Earth() {}
};