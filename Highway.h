#pragma once
#include "WorldObject.h"
#include "Road.h"
#include "Corner.h"
#include<vector>

using namespace std;

class Highway : public WorldObject
{
	Road* lastRoad;
	Road *leftRoad,*rightRoad;
	Corner* nextCorner;	
	vector<Road*> roads;

	Ball* ball;

	void DrawObject();
	void CheckPossibilities();
public:
	Highway();
	~Highway();

	void Follow(Ball* ball);
	void Update();

	bool CanMoveLeft (Point3D &point);
	bool CanMoveRight(Point3D &point);

	bool IsOffRoad();
};
