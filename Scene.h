#pragma once
#include "Camera.h"
#include "WorldObject.h"
#include <vector>

using namespace std;

class Scene
{
	Camera* mainCamera;
	vector<WorldObject*> sceneObjects;
public:
	Scene();
	~Scene();
	
	void Render();

	void SetMainCamera(Camera* camera);
	void AddObject(WorldObject* object);
	void RemoveObject(WorldObject* object);
};
