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
#include "Updatable.h"
#include<vector>

using namespace std;

/*! \brief
* A collection of all the road pieces and the environment
*/
class Highway : public WorldObject, public Updatable
{
	Road* lastRoad; /** <The last road which has been put */
	Road *leftRoad; /** <If there is an intersection this is the left road*/
	Road *rightRoad;/** <If there is an intersection this is the right road*/
	Corner* nextCorner; /** <The next corner in the highway */	
	vector<Road*> roads; /** <Vector containing the roads forming the highway */
	Curve *newCurve; /** < The next curve in the highway */

	Ball* ball; /** <The ball on the highway */
	Scene* scene; /** <The scene on which the highway is part of */

	vector<Mountain*> mountains; /** <Vector containing the mountains */
	vector<Plant*> plants; /** <Vector containing the plants */

	/** Draws all the object on the highway */
	void DrawObject(); 
	/** If there is an intersection checks if you took the right or the left way */
	void CheckPossibilities();
public:
	Highway(Scene* scene);
	~Highway();

	/*! Sets the object to follow the ball*/
	void Follow(Ball* ball);
	/*! Creates the roads and scenary as the ball moves*/
	void Update();

	/*! Checks if the ball can move left
	@param point the vector that is the distance between the ball and the nextCorner point
	*/
	bool CanMoveLeft (Point3D &point);
	/*! Checks if the ball can move right
	@param point the vector that is the distance between the ball and the nextCorner point
	*/
	bool CanMoveRight(Point3D &point);

	/*! Check if the ball has gone off the road*/
	bool IsOffRoad();
};
