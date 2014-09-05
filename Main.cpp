#include"Ball.h"
#include"Plant.h"
#include"Camera.h"
#include "Road.h"

#include <vector>
#include <iostream>

using namespace std;

Textures* Textures::instance = NULL;
Camera *mainCamera = new Camera();
vector<Road*> roads;
int count = 0;
Point3D point;
Ball *newBall = new Ball(Point3D(0, 0, 1),-0.1, 0.5);
Plant *newPlant=new Plant(0.6, 0.6);

void Initialize() 
{
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_TEXTURE_2D);
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_BLEND);
	gluPerspective(60.0, (GLfloat) GLUT_WINDOW_WIDTH/(GLfloat) GLUT_WINDOW_HEIGHT, 1.0, 100.0);
	roads.push_back(new Road(Point3D(0.0, 0.0, 1.0)));
	Textures::GetInstance()->LoadGLTextures();
	newPlant->Translate(Point3D(0.,-0.3,-2));
	mainCamera->Follow(newBall);
}

void Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mainCamera->Perspective();
		for(int i=0; i < roads.size(); i++) {
			glColor4f( 0.0 , 1.0 , 1.0, 1.0);
			roads[i]->Draw();
		}
		Point3D endRoad = roads[roads.size()-1]->GetEndPoint();
		//if(newBall->GetTranslate().z < (roads[roads.size()-1]->GetTranslate().z + 15.0) ) {
		if((endRoad - newBall->GetTranslate()).Magnitude() < 15.0) {
			count ++;
			roads.push_back(new Road(endRoad));
			roads[roads.size()-1]->Rotate(roads[roads.size()-2]->GetRotate());
			if(count % (rand() % 5 + 3) == 2) {
				roads[roads.size()-1]->Rotate(Point3D(0.0, 90.0, 0.0));
				roads[roads.size()-1]->Translate(roads[roads.size()-1]->GetRight()*10);
			}
			cout<<roads[roads.size()-1]->GetForward().x<<" "<<roads[roads.size()-1]->GetForward().z<<endl;
			if(roads.size() > 10) {
				roads.erase (roads.begin()+2);
			}
		}
		newBall->Draw();
		newPlant->Draw();
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
	newPlant->Rotate(Point3D(0.0, 10.0, 0.0));
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