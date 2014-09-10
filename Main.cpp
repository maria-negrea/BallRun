#include "Camera.h"
#include "Sky.h"
#include "Highway.h"
#include "EndScreen.h"
#include "Digit.h"
#include "Earth.h"

#include <vector>
#include <iostream>
#include <time.h>

/**
\mainpage Ball Run
* Moldoveanu Florin & Maria Negrea & Bogdan Musat & Ferencz Timea & Catalin Ionescu

* 05 / 09 / 2014 -> 10/ 09/ 2014

* This is a game similar to temple run with the protagonist being a route66 ball. 
* The game invites you in trying to reach a score of 66 points. 
* Take sharper and sharper turns as your speed increasing leading to your inevitable defeat by missing a turn.

* We are using the Glut Library for using drawing methods in OpenGL.

* In order to build this project under Windows, one must use the Visual Studio suite (v. 2008 recommended).
*/
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

GLfloat* score;

Digit *scoreDigit1;
Digit *scoreDigit2; 

void Initialize() 
{
	srand(time(0));
	score = new GLfloat[1];
	*score = 0;

	scoreDigit1 = new Digit(0,0,score);
	scoreDigit2 = new Digit(0,1,score);

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
	scoreDigit1->UnFollow();
	scoreDigit2->UnFollow();

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
	
	scene->Update();

	if(!isGameOver);
	{
		*score = *score + (newBall->GetTranslate()-lastBallPosition).Magnitude()/100*1.5;
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
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 10000.0);
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