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

	//Sets the perspective to the perspective of the main camera
	mainCamera->Perspective();

	//Draws the objects on screen
	for(unsigned i=0;i<sceneObjects.size();++i)
	{
		sceneObjects[i]->Draw();
	}
	glFlush();

}

void Scene::Update()
{
	for(unsigned i=0;i<updateObjects.size();++i)
	{
		updateObjects[i]->Update();
	}
	mainCamera->Update();
}

void Scene::RemoveUpdatable(Updatable* object)
{
	for (unsigned i=0; i<updateObjects.size(); ++i)
	{
		if(updateObjects[i] == object)
		{
			updateObjects.erase(updateObjects.begin()+i);
			break;
		}
	}
}

void Scene::SetMainCamera(Camera* camera)
{
	mainCamera = camera;
}

void Scene::AddObject(WorldObject* object)
{
	sceneObjects.push_back(object);

	Updatable* updatableObject = dynamic_cast<Updatable*>(object);
	if(updatableObject != NULL)
	{
		updateObjects.push_back(updatableObject);
	}
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

	Updatable* updatableObject = dynamic_cast<Updatable*>(object);
	if(updatableObject != NULL)
	{
		RemoveUpdatable(updatableObject);
	}
}