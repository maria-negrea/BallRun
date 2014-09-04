#include "Map.h"

Map::Map() {

}

Map::~Map() {

}

void Map::addObject(WorldObject *newObj) {
    objects.push_back(newObj);
}

void Map::showObjects() {
    for(int i=0; i < objects.size(); i++) {
        
    }
}