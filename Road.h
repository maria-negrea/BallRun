#pragma once

#include "WorldObject.h"

class Road : public WorldObject
{
public:
    Road(Point3D x) {
        translate = x;
    }
    ~Road() {}
    void DrawObject();
    void GetEndPoint();
};