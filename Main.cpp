#include "Ball.h"
#include "Camera.h"
#include "Road.h"
#include "Tree.h"
#include "Cactus.h"
#include "Earth.h"
#include "Corner.h"
#include "Sky.h"
#include "Scene.h"
#include "Highway.h"
#include "Curve.h"
#include "Mountain.h"
#include "EndScreen.h"
#include "Digit.h"

#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

Textures* Textures::instance = NULL;
Camera *mainCamera = new Camera();
Ball *newBall = new Ball(Point3D(0, 0, 1),-0.9, 0.5);
Earth *newEarth = new Earth();
int count = 0;
Point3D point;

Sky* sky = new Sky(30);
Scene* scene;
Highway* highway = new Highway(scene);

EndScreen *screen = new EndScreen();
bool isGameOver = false;

Digit *scoreDigit1 = new Digit(0);
Digit *scoreDigit2 = new Digit(0);

GLfloat score = 0;

void Initialize() 
{
	srand(time(0));

	scene = new Scene();
	highway = new Highway(scene);

	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_BLEND);
	
	mainCamera->Follow(newBall);
	sky->Follow(newBall);
	highway->Follow(newBall);

	scoreDigit1->Follow(newBall,Point3D(9,5,3));
	scoreDigit2->Follow(newBall,Point3D(9,5,1));

	scene->SetMainCamera(mainCamera);
	scene->AddObject(newBall);
	scene->AddObject(newEarth);
	scene->AddObject(highway);
	scene->AddObject(sky);
	scene->AddObject(scoreDigit1);
	scene->AddObject(scoreDigit2);
	Textures::GetInstance()->LoadGLTextures();	
}

void Draw()
{
	scene->Render();
}

void specialKey(int key, int x, int y)
{ 

	switch(key) 
	{
		case GLUT_KEY_RIGHT :
			if(highway->CanMoveRight(point))
				newBall->MoveRight(point+newBall->GetRight());
			break;

		case GLUT_KEY_LEFT :
			if(highway->CanMoveLeft(point))
				newBall->MoveLeft(point-newBall->GetRight());
			break;
	}

	glutPostRedisplay();
}

void GameOver()
{
	mainCamera->UnFollow();
	sky->UnFollow();

	scene->AddObject(screen);
	screen->Translate(screen->GetTranslate()*(-1));
	screen->Translate(newBall->GetTranslate());
	screen->Rotate(screen->GetRotate()*(-1));
	screen->Rotate(Point3D(0.0, newBall->GetRotate().y, 0.0));

	isGameOver = true;
}

void CheckGameOver()
{
	if(!isGameOver && highway->IsOffRoad())
	{
		GameOver();
	}
}

void Timer(int value)
{
	Point3D lastBallPosition = newBall->GetTranslate();
	newBall->MoveForward();

	if(!isGameOver)
	{
		highway->Update();
		sky->Update();
		mainCamera->Update();
		scoreDigit1->Update();
		scoreDigit2->Update();

		score += (newBall->GetTranslate()-lastBallPosition).Magnitude()/100*1.5;
		scoreDigit1->SetDigit(score);
		scoreDigit2->SetDigit(score/10);
	}

	CheckGameOver();

    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
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