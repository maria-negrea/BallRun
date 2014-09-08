#include "Ball.h"
#include "Plant.h"
#include "Camera.h"
#include "Road.h"
#include "Tree.h"
#include "Cactus.h"
#include "Earth.h"
#include "Corner.h"
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

Textures* Textures::instance = NULL;
Camera *mainCamera = new Camera();
Earth *newEarth = new Earth();
vector<Road*> roads;
int count = 0;
Point3D point;
Ball *newBall = new Ball(Point3D(0, 0, 1),-0.1, 0.5);
Plant *newPlant;
Tree *newTree;
Road* lastRoad;
Road *leftRoad,*rightRoad;
Corner* nextCorner;


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
	gluPerspective(60.0, (GLfloat) GLUT_WINDOW_WIDTH/(GLfloat) GLUT_WINDOW_HEIGHT, 1.0, 100.0);

	newPlant->Translate(Point3D(0.,-0.3,-2));
	newTree->Translate(Point3D(0.,-0.3,-2));

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

	for(int i=0; i < roads.size(); i++) 
	{
		roads[i]->Draw();
	}

	newEarth->Draw();
	newBall->Draw();
	/*newTree->Draw();
	newPlant->Draw();*/

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
		if((endRoad - newBall->GetTranslate()).Magnitude() < 30.0)
		{
			Road *newRoad = new Road(lastRoad->GetTranslate());
			roads.push_back(newRoad);
			newRoad->Rotate(lastRoad->GetRotate());

			int random = rand() % 7;
			
		   if(random == 0) 
		   {
				newRoad->Rotate(Point3D(0.0, 90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22+lastRoad->GetRight()*22);

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,false,true);
				lastRoad = newRoad;
		   }
		   else if(random == 1) 
		   {
				newRoad->Rotate(Point3D(0.0, -90.0, 0.0));
				newRoad->Translate(lastRoad->GetForward()*22-lastRoad->GetRight()*22);

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,false);
				lastRoad = newRoad;
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

				nextCorner = new Corner(lastRoad->GetTranslate()+lastRoad->GetForward()*22,true,true);
				lastRoad = NULL;
				leftRoad = newRoad;
				rightRoad = otherRoad;
		   }
		   else
		   {
				newRoad->Translate(lastRoad->GetForward()*40);
				lastRoad = newRoad;
		   }
			int nr = roads.size() - 15;
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
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
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