#pragma once
#include "WorldObject.h"
#include "Road.h"
#include "Corner.h"
#include "Curve.h"
#include "Scene.h"
#include "Plant.h"
#include "Cactus.h"
#include "Tree.h"
#include "Mountain.h"
#include<vector>

using namespace std;

class Highway : public WorldObject
{
	Road* lastRoad;
	Road *leftRoad,*rightRoad;
	Corner* nextCorner;	
	vector<Road*> roads;
	Curve *newCurve;

	Ball* ball;
	Scene* scene;

	vector<Mountain*> mountains;
	vector<Plant*> plants;

	void DrawObject();
	void CheckPossibilities();
public:
	Highway(Scene* scene);
	~Highway();

	void Follow(Ball* ball);
	void Update();

	bool CanMoveLeft (Point3D &point);
	bool CanMoveRight(Point3D &point);

	bool IsOffRoad();
};
