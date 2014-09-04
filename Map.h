#pragma once
#include "WorldObject.h"
#include <vector>

using namespace std;

class Map {
    private:
        vector<WorldObject*> objects;        
    public:
        Map();
        ~Map();
        void addObject(WorldObject *newObj);
        void showObjects();
};