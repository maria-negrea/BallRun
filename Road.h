#pragma once
#include "Textures.h"
#include "WorldObject.h"
#include "Textures.h"

/*! \brief
*	Draws a quad with the "road texture" 
*/
class Road : public WorldObject
{
public:
    Road(Point3D x) {
        translate = x;
    }
    ~Road() {}

    void DrawObject();
	Point3D GetEndPoint();
};