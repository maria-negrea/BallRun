#include "Ball.h"
#include "Camera.h"
#include "Road.h"
#include "Tree.h"
#include "Cactus.h"
#include "Earth.h"
#include "Corner.h"
#include "Curve.h"
#include "Mountain.h"
#include "Sky.h"
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

Textures* Textures::instance = NULL;
Camera *mainCamera = new Camera();
Earth *newEarth = new Earth();
Sky* sky = new Sky(30);

vector<Road*> roads;
vector<Mountain*> mountains;
vector<Plant*> plants;

int count = 0;
Point3D point;
Ball *newBall = new Ball(Point3D(0, 0, 1),-0.5, 0.5);
Plant *newPlant;
Tree *newTree;
Road* lastRoad;
Road *leftRoad,*rightRoad;
Corner* nextCorner;
Curve *newCurve = new Curve(2);


void Initialize() 
{
	srand(time(0));
	newPlant=new Cactus(0.3, 0.3, 10);
	newTree=new Tree(0.3, 0.3, 5);

	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_BLEND);
	lastRoad = new Road(Point3D(0.0, 0.0, 1.0));
	roads.push_back(lastRoad);
	nextCorner = NULL;
	
	mainCamera->Follow(newBall);


	Textures::GetInstance()->LoadGLTextures();	
}

void CheckPossibilities()
{
	if((leftRoad->GetTranslate() - newBall->GetTranslate()).Magnitude() < 2.0)
	{
		lastRoad = leftRoad;
	}
	if((rightRoad->GetTranslate() - newBall->GetTranslate()).Magnitude() < 2.0)
	{
		lastRoad = rightRoad;
	}
}

bool CanMoveLeft ()
{
	if(nextCorner == NULL)
		return false;
	if(nextCorner->CanMoveLeft(newBall))
	{
		point = nextCorner->GetPoint();

		nextCorner = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

bool CanMoveRight()
{
	if(nextCorner == NULL)
		return 0;
	if(nextCorner->CanMoveRight(newBall))
	{
		point = nextCorner->GetPoint();

		nextCorner = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

void Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	mainCamera->Perspective();

	sky->Translate(sky->GetTranslate()*-1+newBall->GetTranslate());
	sky->Draw();

	for(int i=0; i < roads.size(); i++) 
	{
		roads[i]->Draw();
	}

	newEarth->Draw();
	newBall->Draw();
	newCurve->Draw();

	for(int i=0; i < mountains.size(); i++) 
	{
		mountains[i]->Draw();
	}

	glFlush();
}

void specialKey(int key, int x, int y)
{ 

	switch(key) 
	{
		case GLUT_KEY_RIGHT :
			if(CanMoveRight())
				newBall->MoveRight(point+newBall->GetRight());
			break;

		case GLUT_KEY_LEFT :
			if(CanMoveLeft())
				newBall->MoveLeft(point-newBall->GetRight());
			break;
	}

	glutPostRedisplay();
}

void Timer(int value)
{
	newBall->MoveForward();
	newPlant->Rotate(Point3D(0.0, 5.0, 0.0));
	newTree->Rotate(Point3D(0.0, 5.0, 0.0));
	mainCamera->Update();
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);

	if(lastRoad == NULL)
	{
		CheckPossibilities();
	}
	else
	{
		Point3D endRoad = lastRoad->GetEndPoint();
		if((endRoad - newBall->GetTranslate()).Magnitude() < 15.0)
		{
			Road *newRoad = new Road(lastRoad->GetTranslate());
			
			roads.push_back(newRoad);

			newRoad->Rotate(lastRoad->GetRotate());

			int random = rand() % 5;
			
		   if(random == 0) // right turn
		   {
				newRoad->Rotate(Point3D(0.0, 90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22+lastRoad->GetRight()*22);

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,false,true);
				delete newCurve;
				newCurve = new Curve(0);
				newCurve->Translate(lastRoad->GetTranslate()+lastRoad->GetForward()*22);
				//newCurve->Translate(lastRoad->GetRight()*(2));
				newCurve->Rotate(newRoad->GetRotate()*-1+Point3D(0,180,0));
				//newCurve->Rotate(Point3D(0.0, -180.0, 0.0));
				lastRoad = newRoad;
				cout<<"Right turn"<<endl;
		   }
		   else if(random == 1) 
		   {
				newRoad->Rotate(Point3D(0.0, -90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22-lastRoad->GetRight()*22);

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,false);
				delete newCurve;
				newCurve = new Curve(1);
				newCurve->Translate(lastRoad->GetTranslate()+lastRoad->GetForward()*18);
				//newCurve->Translate(lastRoad->GetRight()*(-2));
				newCurve->Rotate(newRoad->GetRotate()*-1+Point3D(0,180,0));
				//newCurve->Rotate(Point3D(0.0, 90.0, 0.0));
				lastRoad = newRoad;
				cout<<"Left turn"<<endl;
		   }
		   else if(random == 2)
		   {
				Road *otherRoad = new Road(lastRoad->GetTranslate());
				roads.push_back(otherRoad);
				otherRoad->Rotate(lastRoad->GetRotate());

				otherRoad->Rotate(Point3D(0.0, -90.0, 0.0));
				otherRoad->Translate(lastRoad->GetForward()*22-lastRoad->GetRight()*22);

				newRoad->Rotate(Point3D(0.0, 90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22+lastRoad->GetRight()*22);
				delete newCurve;
				newCurve = new Curve(2);
				newCurve->Translate(lastRoad->GetTranslate()+lastRoad->GetForward()*22);
				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,true);
				newCurve->Rotate(otherRoad->GetRotate()*(-1) + Point3D(0.0, -90.0, 0.0));
				lastRoad = NULL;
				leftRoad = newRoad;
				rightRoad = otherRoad;
				cout<<"Both turn"<<endl;
		   }
		   else
		   {
				newRoad->Translate(lastRoad->GetForward()*40);
				lastRoad = newRoad;
		   }

		    int side = rand() % 2;
			int dist = rand() % 10 + 20;

		    Mountain *newMountain = new Mountain(rand() % 10 + 10, -rand() % 10 - 10, rand() % 10 + 10);

			if(side == 0)
				newMountain->Translate(newRoad->GetTranslate() + newRoad->GetRight() * dist);
			else 
				newMountain->Translate(newRoad->GetTranslate() - newRoad->GetRight() * dist);
			newMountain->Rotate(Point3D(0, rand() % 360, 0));
			mountains.push_back(newMountain);

			/*Plant *newPlant;
			int plantType = rand() % 2;
			if(plantType == 0)
				newPlant = new Cactus(1, 1, 10);
			else 
				newPlant = new Tree(1, 1, 5);

			newPlant->Translate(newRoad->GetTranslate() + newRoad->GetRight() * 2);
			plants.push_back(newPlant);*/

			int nr = mountains.size() - 5;
			for(int i = 0; i < nr; i++)
				mountains.erase(mountains.begin());

	/*		nr = plants.size() - 3;
			for(int i = 0; i < nr; i++)
				plants.erase(plants.begin());*/

			nr = roads.size() - 4;
			for(int i = 0; i < nr; i++)
				roads.erase(roads.begin());
		}
	}
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 100.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(768, 768);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("BallRun");
	Initialize();
	glutDisplayFunc(Draw);

	glutSpecialFunc(specialKey);
	glutTimerFunc(30, Timer, 0);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}