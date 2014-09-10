#pragma once
#include "Textures.h"
#include "WorldObject.h"
#include "Textures.h"

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