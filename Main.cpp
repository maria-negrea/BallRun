#include "Ball.h"
#include "Plant.h"
#include "Camera.h"
#include "Road.h"
#include "Earth.h"
#include <vector>
#include <iostream>
#include<time.h>

using namespace std;

Textures* Textures::instance = NULL;
Camera *mainCamera = new Camera();
Ball *newBall = new Ball(Point3D(0, 0, 1),-0.5, 0.5);
Earth *newEarth = new Earth();
vector<Road*> roads;
int count = 0;
Point3D point;

void Initialize() 
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_BLEND);
	gluPerspective(60.0, (GLfloat) GLUT_WINDOW_WIDTH/(GLfloat) GLUT_WINDOW_HEIGHT, 1.0, 100.0);
	roads.push_back(new Road(Point3D(0.0, 0.0, 1.0)));

	Textures::GetInstance()->LoadGLTextures();
	mainCamera->Follow(newBall);

	srand(time(NULL));
}

void Draw()
{
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
	 mainCamera->Perspective();
	 newEarth->Draw();

	  for(int i=0; i < roads.size(); i++) 
	  {
	   glColor4f(1.0 , 1.0 , 1.0, 1.0);
	   roads[i]->Draw();
	  }

	  Point3D endRoad = roads[roads.size()-1]->GetEndPoint();
	  if((endRoad - newBall->GetTranslate()).Magnitude() < 30.0)
	  {
	   roads.push_back(new Road(endRoad+roads[roads.size()-1]->GetForward()*4));
	   roads[roads.size()-1]->Rotate(roads[roads.size()-2]->GetRotate());
	   
	   int random = rand() % 17;
			
		   if(random == 0) 
		   {
			roads[roads.size()-1]->Rotate(Point3D(0.0, 90.0, 0.0));
			roads[roads.size()-1]->Translate(roads[roads.size()-2]->GetForward()*(-2)+roads[roads.size()-2]->GetRight()*3);
		   }

		   else if(random == 1) 
		   {
			roads[roads.size()-1]->Rotate(Point3D(0.0, -90.0, 0.0));
			roads[roads.size()-1]->Translate(roads[roads.size()-2]->GetForward()*(-2)-roads[roads.size()-2]->GetRight()*3);
		   }
		   
	   int nr = roads.size() - 15;
	   for(int i = 0; i < nr; i++)
		   roads.erase(roads.begin());
	  }

	 newBall->Draw();
	 glFlush();
}

void specialKey(int key, int x, int y)
{ 
	switch(key) 
	{
		case GLUT_KEY_RIGHT :
			newBall->MoveRight();
			break;

		case GLUT_KEY_LEFT :
			newBall->MoveLeft();
			break;
	}

	glutPostRedisplay();
}

void Timer(int value)
{
	newBall->MoveForward();
	mainCamera->Update();
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
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