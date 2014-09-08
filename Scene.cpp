#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Render()
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	mainCamera->Perspective();

	for(int i=0;i<sceneObjects.size();i++)
	{
		sceneObjects[i]->Draw();
	}
	glFlush();

}

void Scene::SetMainCamera(Camera* camera)
{
	mainCamera = camera;
}

void Scene::AddObject(WorldObject* object)
{
	sceneObjects.push_back(object);
}

void Scene::RemoveObject(WorldObject* object)
{
	for (unsigned i=0; i<sceneObjects.size(); ++i)
	{
		if(sceneObjects[i] == object)
		{
			sceneObjects.erase(sceneObjects.begin()+i);
			break;
		}
	}
}